#include <game.hpp>
#include <vector>
#include <string>
#include <cell/cell.hpp>
#include <iostream>

namespace Controller {
    
    auto DEFAULT_NUM_ROWS = 12;
    auto DEFAULT_NUM_COLUMNS = 16;
    auto DEFAULT_CELL_SIZE = 40;

    Game::Game(): interface(), field(), cell_size(DEFAULT_CELL_SIZE),
        num_rows(DEFAULT_NUM_ROWS),
        num_columns(DEFAULT_NUM_COLUMNS) {
            interface.render_frame(field.get_frame(num_rows, num_columns), cell_size);
        }
    
    void Game::run_forever() {
        std::clog << "Starting main loop" << std::endl;
        GameClock clock;
        auto i = 0;
        while (true) {
            interface.handle_event_queue();
            field.step();
            interface.render_frame(field.get_frame(num_rows, num_columns), cell_size);
            clock.wait_until_next_frame();
        }
    }

    GameClock::GameClock(uint64_t fps): frame_minimum_duration(1000 / fps), frame_start(SDL_GetTicks64()) {}

    void GameClock::wait_until_next_frame() {
        auto elapsed_time = SDL_GetTicks64() - frame_start;        
        if (frame_minimum_duration > elapsed_time) {
            SDL_Delay(frame_minimum_duration - elapsed_time);
        }
        frame_start = SDL_GetTicks64();
    }
}
