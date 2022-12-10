#include <iostream>
#include <SDL.h>
#include <view/view.hpp>

int main(int argc, char* argv[]) {
    std::cerr << "Initializing SDL..." << std::endl;
    if (SDL_Init(SDL_INIT_VIDEO)) {
        std::cout << "Could not init SDL2\n";
    }
    View::Window window;
    std::cout << "Up and running...\n";
    SDL_Delay(6000);
    std::cout << "Wrapping up...\n";
    window.~Window();
    SDL_Quit();
    return 0;
}
