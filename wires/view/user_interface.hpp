#pragma once

#include <SDL.h>
#include <view/window.hpp>
#include <cell/cell.hpp>
#include <view/interface_events.hpp>
#include <view/event_queue.hpp>

namespace View {

    class GraphicsInitializer {
    public:
        GraphicsInitializer();
        ~GraphicsInitializer();
    };

    class UserInterface {
        const GraphicsInitializer initializer;
        EventQueue queue;
        Window window;
        int32_t cell_length, cell_n, cell_m;

    public:
        UserInterface();
        
        std::optional<InterfaceEvent> poll_event();
        void render_frame(const CellFrame &frame, int32_t cell_size);
    };
}
