#include "playerShip.h"
#include "constants.h"
#include "game.h"
#include "laserBeam.h"

GameObject playerShip;
bool goUp;
bool goLeft;
bool goDown;
bool goRight;

void getInput();
void setInput();

void initPlayerShip(SDL_Renderer* renderer)
{
    goUp = false;
    goLeft = false;
    goDown = false;
    goRight = false;
    
    createGameObject(renderer, &playerShip, "assets/playerShip1_blue.png");
    playerShip.position.x = 400;
    playerShip.position.y = 300;
}

void updatePlayerShip(SDL_Renderer* renderer)
{
    getInput();
    setInput();
    drawCollider(renderer, playerShip);
    drawImage(renderer, playerShip);
}

void getInput()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_w)
                {
                    goUp = true;
                }
                if (event.key.keysym.sym == SDLK_a)
                {
                    goLeft = true;
                }
                if (event.key.keysym.sym == SDLK_s)
                {
                    goDown = true;
                }
                if (event.key.keysym.sym == SDLK_d)
                {
                    goRight = true;
                }
                break;
            case SDL_KEYUP:
                if (event.key.keysym.sym == SDLK_w)
                {
                    goUp = false;
                }
                if (event.key.keysym.sym == SDLK_a)
                {
                    goLeft = false;
                }
                if (event.key.keysym.sym == SDLK_s)
                {
                    goDown = false;
                }
                if (event.key.keysym.sym == SDLK_d)
                {
                    goRight = false;
                }
                if (event.key.keysym.sym == SDLK_SPACE)
                {
                    fireLaserBeam(playerShip.position);
                }
                break;
            case SDL_QUIT:
                done = SDL_TRUE;
                break;
        }
    }
}

void setInput()
{
    float deltaTime = 0.001;
    if (goUp)
    {
//        boxes[0].position.y -= deltaTime * SPEED;
        playerShip.position.y -= deltaTime * SPEED;
        //        gameObjects[0].rect.y -= 1;
    }
    if (goLeft)
    {
//        boxes[0].position.x -= deltaTime * SPEED;
        playerShip.position.x -= deltaTime * SPEED;
        //        gameObjects[0].rect.x -= 1;
    }
    if (goDown)
    {
//        boxes[0].position.y += deltaTime * SPEED;
        playerShip.position.y += deltaTime * SPEED;
        //        gameObjects[0].rect.y += 1;
    }
    if (goRight)
    {
//        boxes[0].position.x += deltaTime * SPEED;
        playerShip.position.x += deltaTime * SPEED;
        //        gameObjects[0].rect.x += 1;
    }
}
