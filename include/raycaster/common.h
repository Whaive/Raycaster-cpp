#ifndef COMMON_H
#define COMMON_H

#include <SDL2/SDL.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define FOV 45

#define FPS 75
#define FRAME_TARGET_TIME (1000 / FPS) //1000 miliseconds / FPS

/*
    Sets up a SDL window 
*/
bool initializeWindow(SDL_Window *&window, SDL_Renderer *&renderer);

void destroyWindow(SDL_Window *&window, SDL_Renderer *&renderer);

#endif