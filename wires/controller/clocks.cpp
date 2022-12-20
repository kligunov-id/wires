#include <clocks.hpp>

namespace Controller {
    
    GameClock::GameClock(uint64_t fps): frame_minimum_duration(1000 / fps), frame_start(SDL_GetTicks64()) {}

    void GameClock::wait_until_next_frame() {
        auto elapsed_time = SDL_GetTicks64() - frame_start;        
        if (frame_minimum_duration > elapsed_time) {
            SDL_Delay(frame_minimum_duration - elapsed_time);
        }
        frame_start = SDL_GetTicks64();
    }

    ModelClock::ModelClock(uint64_t fps) : frame_minimum_duration(1000 / fps), frame_start(SDL_GetTicks64()) {}

    bool ModelClock::should_start() {
        auto elapsed_time = SDL_GetTicks64() - frame_start;
        bool should_start = elapsed_time >= frame_minimum_duration;
        if (should_start)
            frame_start += elapsed_time;
        return should_start;
    }
}
