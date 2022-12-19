#include <user_interface.hpp>
#include <iostream>
#include <view/user_interface.hpp>
#include <optional>

namespace View {

    GraphicsInitializer::GraphicsInitializer() {
        std::clog << "Initializing SDL..." << std::endl;
        if (SDL_Init(SDL_INIT_VIDEO)) {
            std::cerr << "Could not init SDL2\n";
            throw SDL_GetError();
        }
    }

    GraphicsInitializer::~GraphicsInitializer() {
        std::clog << "Quitting..." << std::endl;
        SDL_Quit();
    }

    UserInterface::UserInterface(): initializer(), window() {
        std::clog << "Up and running..." << std::endl;
    }

    std::optional<InterfaceEvent> UserInterface::poll_event() {
        return queue.poll_event();
    }
    
    void UserInterface::render_frame(const CellFrame &frame, int32_t cell_size) {
        window.render_frame(frame, cell_size);
    }
}
