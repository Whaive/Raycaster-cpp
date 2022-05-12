#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Player {

    glm::vec2 position;
    glm::vec2 rotation;
    float angle;
    float rotationForce;
    glm::vec2 size;
    float speed;
    float lastFrameTime;
    glm::vec2 intersection;

    public:
        Player();
        Player(glm::vec2 position, glm::vec2 size, float speed);
        void move(glm::vec2 inputVec);
        void draw(SDL_Renderer *renderer);
        void drawRays(SDL_Renderer *renderer, int *map, glm::vec2 mapSize, float cellSize, float rayAngle);

};


#endif