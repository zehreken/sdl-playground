#include "playerShip.h"
#include "constants.h"
#include "game.h"
#include "laserBeam.h"
#include "audioController.h"

static GameObject playerShip;

static void setInput(float deltaTime);

const float FIRE_RATE = 0.2;
static float fireRateTimer = 0;

static int hitPoint = 100;

void initPlayerShip(SDL_Renderer* renderer)
{
    goUp = false;
    goLeft = false;
    goDown = false;
    goRight = false;
    
    createGameObject(renderer, &playerShip, "assets/playerShip1_blue.png");
    playerShip.position.x = 400;
    playerShip.position.y = 300;
    playerShip.boxSize.x *= 0.3;
    playerShip.boxSize.y *= 0.3;
}

void playerShip_reset()
{
    playerShip.position.x = 400;
    playerShip.position.y = 300;
    hitPoint = 100;
}

void updatePlayerShip(SDL_Renderer* renderer, float deltaTime)
{
    setInput(deltaTime);
    drawImage(renderer, &playerShip);
    drawCollider(renderer, playerShip);
    
    fireRateTimer += deltaTime;
    if (fireRateTimer >= FIRE_RATE)
    {
        fireRateTimer = 0;
        fire();
        audioController_play(1);
    }
    
    if (playerShip.hasCollision)
    {
        hitPoint -= 30;
        if (hitPoint <= 0)
        {
            hitPoint = 0;
            // End game
            endGame();
            audioController_play(2);
        }
    }
}

void fire()
{
    Vector2 posLeft, posRight;
    posLeft.x = playerShip.position.x - 40;
    posRight.x = playerShip.position.x + 40;
    posLeft.y = posRight.y = playerShip.position.y;
    fireLaserBeam(posLeft, false);
    fireLaserBeam(posRight, false);
}

int getPlayerShipHitPoint()
{
    return hitPoint;
}

GameObject* getPlayerShip()
{
    return &playerShip;
}

static void setInput(float deltaTime)
{
    if (goUp && playerShip.position.y > 0)
    {
        playerShip.position.y -= deltaTime * SPEED;
    }
    if (goLeft && playerShip.position.x > 0)
    {
        playerShip.position.x -= deltaTime * SPEED;
    }
    if (goDown && playerShip.position.y < HEIGHT)
    {
        playerShip.position.y += deltaTime * SPEED;
    }
    if (goRight && playerShip.position.x < WIDTH)
    {
        playerShip.position.x += deltaTime * SPEED;
    }
}
