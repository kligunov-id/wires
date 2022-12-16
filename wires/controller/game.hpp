#pragma once

#include <SDL.h>
#include <view/user_interface.hpp>

namespace Controller {
   class Game {
        View::UserInterface interface;
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
};