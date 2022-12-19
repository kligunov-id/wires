#include <window.hpp>
#include <iostream>
#include <cell/cell.hpp>

namespace View {
    
    auto DEFAULT_WINDOW_TITLE = "Wires";
    auto DEFAULT_WINDOW_WIDTH = 640;
    auto DEFAULT_WINDOW_HEIGHT = 480;
    auto DEFAULT_WINDOW_FLAGS = 0;

    auto DEFAULT_RENDERER_FLAGS = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;

    Window::Window() {
        window_ptr =  SDL_CreateWindow(
            DEFAULT_WINDOW_TITLE,
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            DEFAULT_WINDOW_WIDTH,
            DEFAULT_WINDOW_HEIGHT,
            DEFAULT_WINDOW_FLAGS);        
        if (window_ptr == nullptr) {
            std::cerr << "Could not create window\n";
            throw SDL_GetError();
        }
        renderer_ptr = SDL_CreateRenderer(window_ptr, -1, DEFAULT_RENDERER_FLAGS);
        if (renderer_ptr == nullptr) {
            SDL_DestroyWindow(window_ptr);
            std::cerr << "Could not create renderer\n";
            throw SDL_GetError();
        }
    }
    
    void Window::set_cell_color(Cell cell) {
        if (cell == Cell::wire) {
            SDL_SetRenderDrawColor(renderer_ptr, 239, 185, 73, 255);
        } else if (cell == Cell::head) {
            SDL_SetRenderDrawColor(renderer_ptr, 73, 208, 239, 255);
        } else if (cell == Cell::tail) {
            SDL_SetRenderDrawColor(renderer_ptr, 239, 73, 73, 255);
        } else { // cell == Cell::empty
            SDL_SetRenderDrawColor(renderer_ptr, 0, 0, 0, 255);
        }
    }

    void Window::set_border_color() {
        SDL_SetRenderDrawColor(renderer_ptr, 120, 120, 120, 255);
    }

    SDL_Rect Window::get_cell_rect(Coordinate coord, int32_t cell_size) {
        auto [y, x] = coord;
        y *= cell_size;
        x *= cell_size;
        return SDL_Rect{static_cast<int>(x), static_cast<int>(y), cell_size, cell_size};
    }

    void Window::render_cell(Cell cell, Coordinate coord, int32_t cell_size) {
        auto cell_rect = get_cell_rect(coord, cell_size);
        set_cell_color(cell);
        SDL_RenderFillRect(renderer_ptr, &cell_rect);
        set_border_color();
        SDL_RenderDrawRect(renderer_ptr, &cell_rect);
    }

    Window::~Window() {
        if (window_ptr != nullptr) {
            SDL_DestroyWindow(window_ptr);
        }
    }

    void Window::render_frame(const CellFrame &frame, int32_t cell_size) {
        SDL_RenderClear(renderer_ptr);
        size_t n = frame.size(), m = frame[0].size();
        for (size_t x = 0; x < n; x++) {
            for (size_t y = 0; y < m; y++) {
                render_cell(frame[x][y], Coordinate(x, y), cell_size);
            }
        }
        SDL_RenderPresent(renderer_ptr);
    }
}
