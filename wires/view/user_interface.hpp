#pragma once

#include <SDL.h>
#include <view/window.hpp>
#include <cell.hpp>

namespace View {

    class GraphicsInitializer {
    public:
        GraphicsInitializer();
        ~GraphicsInitializer();
    };

    class UserInterface {
        const GraphicsInitializer initializer;
        Window window;
        
        void handle_event(SDL_Event &event);
    public:
        UserInterface();
        
        void handle_event_queue();
        void render_frame(const CellFrame &frame);
    };
}
