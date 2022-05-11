#include <iostream>
#include <cmath>

#include <raycaster/player.h>

#define DG 0.01745329

Player::Player() {

}

Player::Player(glm::vec2 position, glm::vec2 size, float speed) {

        this->position = position;
        this->size = size;
        this->speed = speed;

        this->angle = 0.1;
        this->rotation = glm::vec2(cos(angle), sin(angle));
        this->lastFrameTime = 0;
        this->rotationForce = 0.1;

}

void Player::draw(SDL_Renderer *renderer) {

    SDL_Rect playerRect = {
        (int)position.x,
        (int)position.y,
        (int)size.x,
        (int)size.y
    };

    SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
    SDL_RenderFillRect(renderer, &playerRect);
    SDL_RenderDrawLine(renderer, position.x, position.y, position.x + rotation.x*10, position.y + rotation.y*10);
}

// ! Very Unreadable, needs change
void Player::drawRays(SDL_Renderer *renderer, int *map, float cellSize, float rayAngle) {

    glm::vec2 rayStart = position / cellSize;
    glm::vec2 rayDir = glm::vec2(cos(angle + DG * rayAngle), sin(angle + DG * rayAngle));

    glm::vec2 stepSize = glm::vec2(sqrt(1 + pow(rayDir.y / rayDir.x, 2)), sqrt(1 + pow(rayDir.x / rayDir.y, 2)));
    glm::ivec2 mapCheck = rayStart;

    glm::vec2 rayLength;

    glm::vec2 step;


    if(rayDir.x < 0) {

        step.x = -1;

        rayLength.x = (rayStart.x - (float) mapCheck.x) * stepSize.x;
    }
    else {
        step.x = 1;

        rayLength.x = ((float) (mapCheck.x + 1) - rayStart.x) * stepSize.x;
    }


    if(rayDir.y < 0) {

        step.y = -1;

        rayLength.y = (rayStart.y - (float) mapCheck.y) * stepSize.y;
    }
    else {
        step.y = 1;

        rayLength.y = ((float) (mapCheck.y + 1) - rayStart.y) * stepSize.y;
    }

    bool tileFound = false;
    float maxDistance = 100;
    float distance = 0;

    while(!tileFound && distance < maxDistance) {

        if(rayLength.x < rayLength.y) {
            mapCheck.x += step.x;
            distance = rayLength.x;
            rayLength.x += stepSize.x;
        }
        else {
            
            mapCheck.y += step.y;
            distance = rayLength.y;
            rayLength.y += stepSize.y;
        }

        if(mapCheck.x >= 0 && mapCheck.x < 8 && mapCheck.y >= 0 && mapCheck.y < 8) {

            if(map[mapCheck.x * 8 + mapCheck.y] == 1) {
                tileFound = true;
            }
        }
    }

    glm::vec2 intersection;
    if(tileFound) {

        intersection = rayStart + rayDir * distance;

        intersection *= cellSize;
    }

    SDL_RenderDrawLine(renderer, position.x, position.y, intersection.x, intersection.y);
}

void Player::move(glm::vec2 inputVec) {

    float deltaTime = (SDL_GetTicks() - lastFrameTime) / 1000.0;
    lastFrameTime = SDL_GetTicks();

    angle += inputVec.x * deltaTime;

    if(angle > 2 * M_PI)
        angle -= 2 * M_PI;
    if(angle < 0)
        angle += 2 * M_PI;

    rotation.x = cos(angle);
    rotation.y = sin(angle);

    position.x += rotation.x * speed * inputVec.y * deltaTime;
    position.y += rotation.y * speed * inputVec.y * deltaTime;
    
}