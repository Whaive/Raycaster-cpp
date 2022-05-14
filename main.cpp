# include <iostream>
# include <SDL2/SDL.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <raycaster/common.h>
#include <raycaster/world.h>
#include <raycaster/player.h>

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

World* world;
Player* player;

bool game_is_running = false;


//temporary input system
int w = 0;
int s = 0;
int a = 0;
int d = 0;
void process_input() {

    SDL_Event event;
    SDL_PollEvent(&event);

    switch(event.type) {
        case SDL_QUIT:
            game_is_running = false;
        break;

        case SDL_KEYDOWN:
            if(event.key.keysym.sym == SDLK_ESCAPE)
                game_is_running = false;

            if(event.key.keysym.sym == SDLK_w)
                w = 1;
            if(event.key.keysym.sym == SDLK_s)
                s = 1;
            if(event.key.keysym.sym == SDLK_a)
                a = 1;
            if(event.key.keysym.sym == SDLK_d)
                d = 1;
        break;

        case SDL_KEYUP:

            if(event.key.keysym.sym == SDLK_w)
                w = 0;
            if(event.key.keysym.sym == SDLK_s)
                s = 0;
            if(event.key.keysym.sym == SDLK_d)
                d = 0;
            if(event.key.keysym.sym == SDLK_a)
                a = 0;
            
        break;
    }

    
}


void setup() { //Initialize Game

    int map[] = {
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 0, 0, 0, 0, 1 ,0 ,1,
    1, 0 ,0 ,0 ,0 ,0 ,0, 1,
    1, 1, 1, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0 ,0, 1, 1,
    1, 0, 0, 0, 1, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 1, 
    1, 1, 1, 1, 1, 1, 1, 1
    };

    glm::vec2 mapSize = glm::vec2(8, 8);
    int cellSize = 32;

    world = new World(map, mapSize, cellSize); 
    player = new Player(glm::vec2(90, 90), glm::vec2(4, 4), 100);
}

void update() {

    player->move(glm::vec2(d - a, w - s));

}

void draw() {

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);


    for(int i = 0; i < FOV; i++)
        player->drawView(renderer, world, i);

    world->drawMap(renderer);
    player->draw(renderer, true);

    SDL_RenderPresent(renderer); //Buffer Swap

}

int main(int argc, char* argv[]) {

    game_is_running = initializeWindow(window, renderer);

    setup(); //Star method like a game Engine (start method in unity)
    while(game_is_running) {

        //Three main pillars of a game
        process_input();
        update();
        draw(); //or render

    }

    destroyWindow(window, renderer);
    delete world;
    delete player;

    return 0;

}