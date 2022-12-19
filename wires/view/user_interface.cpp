#include <user_interface.hpp>
#include <iostream>

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

    void UserInterface::render_frame(const CellFrame &frame, int32_t cell_size) {
        window.render_frame(frame, cell_size);
    }
}
