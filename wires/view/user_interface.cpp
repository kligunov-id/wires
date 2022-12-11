#include <user_interface.hpp>
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

    void UserInterface::handle_event_queue() {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            handle_event(event);
        }  
    }
    
    void UserInterface::handle_event(SDL_Event &event) {
        if (event.type == SDL_QUIT) {
            exit(0);
        }
    }
}
