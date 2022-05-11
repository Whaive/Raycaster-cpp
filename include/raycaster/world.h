#ifndef WORLD_H
#define WORLD_H

#include <SDL2/SDL.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class World {

    private:
        glm::vec2 mapSize;
        int cellSize;
    public:
        int* map;
        World();
        World(int* map, glm::vec2 mapSize, int cellSize);
        ~World();
        void init(int* map, glm::vec2 mapSize, int cellSize);
        void drawMap(SDL_Renderer *renderer);
        void drawRays(int fov);

};

#endif