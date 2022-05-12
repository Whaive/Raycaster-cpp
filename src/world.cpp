#include <iostream>

#include <raycaster/world.h>

World::World() {
    
}

World::~World() {
    
    delete[] map;
}

void World::init(int* map, Vec2 mapSize, int cellSize) {

    int size = mapSize.x * mapSize.y;
    this->map = new int[size];
    for(int i = 0; i < size; i++)
        this->map[i] = map[i];
    
    this->mapSize = mapSize;
    this->cellSize = cellSize;

}



void World::drawMap(SDL_Renderer *renderer) {

    
    

    for(int i = 0; i < mapSize.x; i++) {

        for(int j = 0; j < mapSize.y; j++) {

            if(map[i * (int)mapSize.x + j] == 1) {

                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

                SDL_Rect grid_map = {
                    i * cellSize,
                    j * cellSize,
                    cellSize - 1,
                    cellSize - 1
                };

                SDL_RenderFillRect(renderer, &grid_map);

            } 
            else {
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

                SDL_Rect grid_map = {
                    i * cellSize,
                    j * cellSize,
                    cellSize,
                    cellSize
                };

                SDL_RenderFillRect(renderer, &grid_map);
            }

        }
    }

}

int World::getCellSize() {
    return cellSize;
}

Vec2 World::getMapSize() {
    return mapSize;
}

