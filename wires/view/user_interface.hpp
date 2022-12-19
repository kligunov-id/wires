#pragma once

#include <SDL.h>
#include <view/window.hpp>
#include <cell/cell.hpp>

namespace View {

    class GraphicsInitializer {
    public:
        GraphicsInitializer();
        ~GraphicsInitializer();
    };

    class UserInterface {
        const GraphicsInitializer initializer;
        Window window;
        int32_t cell_length, cell_n, cell_m;

        void handle_event(SDL_Event &event);
    public:
        UserInterface();
        
        void handle_event_queue();
        void render_frame(const CellFrame &frame, int32_t cell_size);
    };
}
