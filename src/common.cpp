#include <iostream>

#include <raycaster/common.h>

bool initializeWindow(SDL_Window *&window, SDL_Renderer *&renderer) {

    
    //Initialize SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {

        fprintf(stderr, "Error Initializing SDL.\n");
        return false;

    }

    //Create Window
    window = SDL_CreateWindow(
        "Game",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        0
    );

    if(!window) {
        fprintf(stderr, "Error Initializing Window.\n");
        return false;
    }

    //Create Renderer
    renderer = SDL_CreateRenderer(window, -1, 0); //-1 the default (dont care) //0 no special flag
    if(!renderer) {
        fprintf(stderr, "Error Initializing Renderer.\n");
        return false;
    }

    return true;
}

void destroyWindow(SDL_Window *&window, SDL_Renderer *&renderer) {
    //Destroy Renderer first then window
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
