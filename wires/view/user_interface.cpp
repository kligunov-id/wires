#include <view/user_interface.hpp>
#include <iostream>

namespace View {
    UserInterface::UserInterface() {
        std::clog << "Initializing SDL..." << std::endl;
        if (SDL_Init(SDL_INIT_VIDEO)) {
            std::cerr << "Could not init SDL2\n";
            throw SDL_GetError();
        }
        window = new Window();
        std::clog << "Up and running...\n";
    }
    UserInterface::~UserInterface() {
        delete window;
    }
}
