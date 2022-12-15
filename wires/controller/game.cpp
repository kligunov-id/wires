#include <game.hpp>

namespace Controller {
    Game::Game(uint64_t fps):frame_minimum_duration(1000 / fps), interface() {}
    
    void Game::run_forever() {
        auto last_update_time = SDL_GetTicks64();
        while (true) {
            interface.handle_event_queue();

            auto elapsed_time = SDL_GetTicks64() - last_update_time;
            if (frame_minimum_duration > elapsed_time) {
                SDL_Delay(frame_minimum_duration - elapsed_time);
            }
            last_update_time += elapsed_time;
        }
    }
}
