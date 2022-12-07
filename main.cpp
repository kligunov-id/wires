#include <iostream>
#include <SDL.h>

int main(int argc, char* argv[]) {
    std::cerr << "Initializing SDL..." << std::endl;
    if (SDL_Init(SDL_INIT_VIDEO)) {
        std::cout << "Could not init SDL2\n";
    }
    
    SDL_Window *window = SDL_CreateWindow(
        "Wires",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640,
        480,
        0);
    
    if (window == nullptr) {
        std::cout << "Could not create window\n";
    }
    
    std::cout << "Up and running...\n";
    SDL_Delay(3000);
    std::cout << "Wrapping up...\n";
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
