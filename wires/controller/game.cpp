#include <game.hpp>
#include <vector>
#include <string>
#include <cell/cell.hpp>
#include <iostream>
#include <variant>
#include <optional>

namespace Controller {
    
    auto DEFAULT_NUM_ROWS = 12;
    auto DEFAULT_NUM_COLUMNS = 16;
    auto DEFAULT_CELL_SIZE = 40;
    auto DEFAULT_BRUSH_CELL = Cell::wire;

    Game::Game(): interface(), field(),
        brush_cell(DEFAULT_BRUSH_CELL),
        cell_size(DEFAULT_CELL_SIZE),
        num_rows(DEFAULT_NUM_ROWS),
        num_columns(DEFAULT_NUM_COLUMNS) {
            interface.render_frame(field.get_frame(num_rows, num_columns), cell_size);
        }

    void Game::run_forever() {
        std::clog << "Starting main loop" << std::endl;
        GameClock game_clock;
        ModelClock model_clock;
        while (!should_finish) {
            handle_events();
            if (model_clock.should_start()) {
                field.step();
            }
            interface.render_frame(field.get_frame(num_rows, num_columns), cell_size);
            game_clock.wait_until_next_frame();
        }
    }

    void Game::handle_events() {
        auto handler = [this](auto event){ this->handle_event(event); };
        std::optional<View::InterfaceEvent> event;
        while (event = interface.poll_event()) {
            std::visit(handler, event.value());
        } 
    }

    void Game::handle_event(View::EventQuit) {
        should_finish = true;
    }

    void Game::handle_event(View::EventMouseClick event) {
        auto x = event.x / cell_size;
        auto y = event.y / cell_size;
        field.set_cell({x, y}, brush_cell);
    }

    void Game::handle_event(View::EventSetBrush event) {
        brush_cell = event.cell;
    }

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
