#pragma once

#include <view/user_interface.hpp>
#include <view/interface_events.hpp>
#include <model/field.hpp>
#include <controller/clocks.hpp>

namespace Controller {
   class Game {
        View::UserInterface interface;
        Model::Field field;

        int32_t cell_size, num_rows, num_columns;
        bool should_finish = false;
        bool is_model_running = true;
        Cell brush_cell;
        Coordinate frame_topleft{0,0};

        void handle_event(View::EventQuit event);
        void handle_event(View::EventMouseClick event);
        void handle_event(View::EventSetBrush event);
        void handle_event(View::EventMoveFrame event);
        void handle_event(View::EventPause event);
        void handle_events();
    public:
        Game();
        void run_forever();
    };
};
