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
    }
    
    void EventQueue::process_quit(const SDL_Event &event) {
        if (event.type != SDL_QUIT) return;
        events.emplace(EventQuit());
    }

    std::optional<InterfaceEvent> EventQueue::poll_event() {
        fetch_events();
        if (events.empty()) return {};
        auto event = events.front();
        events.pop();
        return {event};
    }
}
