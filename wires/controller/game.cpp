#include <game.hpp>
#include <vector>
#include <string>
#include <cell.hpp>

namespace Controller {
    
    Game::Game(): interface() {}
    
    void Game::run_forever() {
        GameClock clock;
        while (true) {
            interface.handle_event_queue();
            interface.render_frame(field.get_frame());
            field.step();
            clock.wait_until_next_frame();
        }
    }

    GameClock::GameClock(uint64_t fps): frame_minimum_duration(1000 / fps), frame_start(SDL_GetTicks64()) {}

    void GameClock::wait_until_next_frame() {
        auto elapsed_time = SDL_GetTicks64() - frame_start;
        if (frame_minimum_duration > elapsed_time) {
            SDL_Delay(frame_minimum_duration - elapsed_time);
        }
        frame_start += elapsed_time;
    }
}
