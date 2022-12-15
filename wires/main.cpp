#include <iostream>
#include <controller/game.hpp>

int main(int argc, char* argv[]) {
    Controller::Game game;
    game.run_forever();
    return 0;
}
