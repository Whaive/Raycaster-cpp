#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include "common.h"
#include "world.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Player {

    public:
        Player();
        Player(glm::vec2 position, glm::vec2 size, float speed);
        void move(glm::vec2 inputVec);
        void draw(SDL_Renderer *renderer, bool drawRays = false);
        void drawView(SDL_Renderer *renderer, World* world, int rayAngle);

    private:
        glm::vec2 position;
        glm::vec2 rotation;
        float angle;
        float rotationForce;
        glm::vec2 size;
        float speed;
        float lastFrameTime;
        glm::vec2 rays[FOV];
};


#endif