#pragma once

#include <SDL.h>

namespace View {

    class Window {
        SDL_Window *window_ptr = nullptr;
    public:
        Window();
        Window(const Window &other) = delete;
        Window(Window &&other) = delete;
        Window& operator=(const Window &other) = delete;
        Window& operator=(Window &&other) = delete;
        ~Window();
    };
}