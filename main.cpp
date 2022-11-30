#include <iostream>
#include "SDL.h"

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow(
        "Wires",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640,
        480,
        0);

    SDL_Delay(3000);

    SDL_DestroyWindow(window);
    SDL_Quit();
}
