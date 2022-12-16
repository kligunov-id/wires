#include <window.hpp>
#include <iostream>
#include <cell.hpp>

namespace View {
    
    auto DEFAULT_WINDOW_TITLE = "Wires";
    auto DEFAULT_WINDOW_WIDTH = 640;
    auto DEFAULT_WINDOW_HEIGHT = 480;
    auto DEFAULT_WINDOW_FLAGS = 0;

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
    }

    Window::~Window() {
        if (window_ptr != nullptr) {
            SDL_DestroyWindow(window_ptr);
        }
    }

    void Window::render_frame(const CellFrame &frame) {
        // A mock function
        for (auto &line: frame) {
            for (auto &value: line) {
                if (value == Cell::head)
                    std::cout << "h";
                else if (value == Cell::tail) 
                    std::cout << "t";
                else if (value == Cell::empty)
                    std::cout << "*";
                else
                    std::cout << "w";
                std::cout << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}
