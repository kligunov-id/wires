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
            return {Cell::empty};
        } else if (keycode == SDLK_1) {
            return {Cell::wire};
        } else if (keycode == SDLK_2) {
            return {Cell::head};
        } else if (keycode == SDLK_3) {
            return {Cell::tail};
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

    std::optional<InterfaceEvent> EventQueue::poll_event() {
        fetch_events();
        if (events.empty()) return {};
        auto event = events.front();
        events.pop();
        return {event};
    }
}
