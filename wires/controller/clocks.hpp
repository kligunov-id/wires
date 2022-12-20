#pragma once

#include <SDL.h>

namespace Controller {    
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
}
