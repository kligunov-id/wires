#include <event_queue.hpp>

namespace View {
    void EventQueue::fetch_events() {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            process_event(event);
        }
    }

    void EventQueue::process_event(const SDL_Event &event) {
        process_quit(event);
        process_click(event);
        process_brush_set(event);
        process_move_frame(event);
        process_pause(event);
    }
    
    void EventQueue::process_quit(const SDL_Event &event) {
        if (event.type != SDL_QUIT) return;
        events.emplace(EventQuit());
    }
    
    void EventQueue::process_click(const SDL_Event &event) {
        if (event.type != SDL_MOUSEBUTTONDOWN) return;
        events.emplace(EventMouseClick(event.button.y, event.button.x));
    }
    
    std::optional<Cell> cell_by_keysum(SDL_Keycode keycode) {
        if (keycode == SDLK_0) {
            return {Cell::dead};
        } else if (keycode == SDLK_1) {
            return {Cell::alive};
        }
        return {};
    }

    void EventQueue::process_brush_set(const SDL_Event &event) {
        if (event.type != SDL_KEYDOWN) return;
        auto cell = cell_by_keysum(event.key.keysym.sym);
        if (cell) {
            events.emplace(EventSetBrush(cell.value()));
        }
    }

   std::optional<Coordinate> shift_by_keysum(SDL_Keycode keycode) {
        if (keycode == SDLK_RIGHT) {
            return Coordinate(0, 1);
        } else if (keycode == SDLK_LEFT) {
            return Coordinate(0, -1);
        } else if (keycode == SDLK_UP) {
            return Coordinate(-1, 0);
        } else if (keycode == SDLK_DOWN) {
            return Coordinate(1, 0);
        }
        return {};
   } 

    void EventQueue::process_move_frame(const SDL_Event &event) {
        if (event.type != SDL_KEYDOWN) return;
        auto shift = shift_by_keysum(event.key.keysym.sym);
        if (shift) {
            events.emplace(EventMoveFrame(shift.value()));
        }
    }
    
    void EventQueue::process_pause(const SDL_Event &event) {
        if (event.type != SDL_KEYDOWN) return;
        if (event.key.keysym.sym == SDLK_SPACE) {
            events.emplace(EventPause());
        }
    }

    std::optional<InterfaceEvent> EventQueue::poll_event() {
        fetch_events();
        if (events.empty()) return {};
        auto event = events.front();
        events.pop();
        return {event};
    }
}
