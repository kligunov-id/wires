#pragma once

#include <SDL.h>
#include <view/window.hpp>

namespace View {
    class UserInterface {
        Window *window = nullptr;
        
        void handle_event(SDL_Event &event);
    public:
        UserInterface();
        UserInterface(const UserInterface &other) = delete;
        UserInterface& operator=(const UserInterface &other) = delete;
        UserInterface(UserInterface &&other) = delete;
        UserInterface& operator=(UserInterface &&other) = delete;
        ~UserInterface();
        
        void handle_event_queue();
    };
}
