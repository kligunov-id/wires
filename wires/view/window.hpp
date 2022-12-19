#pragma once

#include <SDL.h>
#include <cell/cell.hpp>

namespace View {

    class Window {
        SDL_Window *window_ptr = nullptr;
        SDL_Renderer *renderer_ptr = nullptr;

        void set_cell_color(Cell cell);
        SDL_Rect get_cell_rect(Coordinate coord, int32_t cell_size);
        void render_cell(Cell cell, Coordinate coord, int32_t cell_size);
        void set_border_color();
    public:
        Window();
        Window(const Window &other) = delete;
        Window(Window &&other) = delete;
        Window& operator=(const Window &other) = delete;
        Window& operator=(Window &&other) = delete;
        ~Window();

        void render_frame(const CellFrame &frame, int32_t width);
    };
}
