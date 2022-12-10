#ifndef VIEW_H
#define VIEW_H

#include <SDL.h>

namespace View {

    class Window {
    private:
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

#endif /* !VIEW_H */
