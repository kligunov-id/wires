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

        void handle_event(View::EventQuit event);
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
        GameClock(uint64_t fps = 1); // Return fps back to 60 when implement graphics
        void wait_until_next_frame();
    };
};
