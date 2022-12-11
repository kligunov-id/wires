#pragma once

#include <SDL.h>
#include <view/window.hpp>

namespace View {
    class UserInterface {
        Window *window = nullptr;
    public:
        UserInterface();
        UserInterface(const UserInterface &other) = delete;
        UserInterface& operator=(const UserInterface &other) = delete;
        UserInterface(UserInterface &&other) = delete;
        UserInterface& operator=(UserInterface &&other) = delete;
        ~UserInterface();
    };
}
