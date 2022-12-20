#pragma once

#include <SDL.h>
#include <view/user_interface.hpp>
#include <model/field.hpp>
#include <view/interface_events.hpp>

namespace Controller {
   class Game {
        View::UserInterface interface;
        Model::Field field;

        int32_t cell_size, num_rows, num_columns;
        bool should_finish = false;
        Cell brush_cell;
        Coordinate frame_topleft{0,0};

        void handle_event(View::EventQuit event);
        void handle_event(View::EventMouseClick event);
        void handle_event(View::EventSetBrush event);
        void handle_event(View::EventMoveFrame event);
        void handle_events();
    public:
        Game();
        void run_forever();
    };

    class GameClock {
    private:
        uint64_t frame_minimum_duration;
        uint64_t frame_start;
    public:
        GameClock(uint64_t fps = 60);
        void wait_until_next_frame();
    };

    class ModelClock {
    private:
        uint64_t frame_minimum_duration;
        uint64_t frame_start;
    public:
        ModelClock(uint64_t fps = 2); 
        bool should_start();
    };
};
