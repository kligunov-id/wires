#pragma once

#include <SDL.h>
#include <view/user_interface.hpp>

namespace Controller {
   class Game {
        View::UserInterface interface;
        int64_t frame_minimum_duration;
    public:
        Game(uint64_t fps=60);

        void run_forever();
    };
};
