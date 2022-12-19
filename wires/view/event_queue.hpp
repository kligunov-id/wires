#pragma once

#include <view/interface_events.hpp>
#include <optional>
#include <queue>
#include <SDL.h>

namespace View {

    class EventQueue {
        std::queue<InterfaceEvent> events;
        
        void fetch_events();
        void process_event(const SDL_Event &event);
        void process_quit(const SDL_Event &event);
    public:
        std::optional<InterfaceEvent> poll_event();
    };
}
