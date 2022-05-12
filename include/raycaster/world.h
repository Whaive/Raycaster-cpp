#ifndef WORLD_H
#define WORLD_H

#include <SDL2/SDL.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using Vec2 = glm::vec2;

class World {

    private:
        Vec2 mapSize;
        int cellSize;
    public:
        int* map;
        World();
        World(int* map, Vec2 mapSize, int cellSize);
        ~World();
        void init(int* map, Vec2 mapSize, int cellSize);
        void drawMap(SDL_Renderer *renderer);
        void drawRays(int fov);

        int getCellSize();
        Vec2 getMapSize();

};

#endif