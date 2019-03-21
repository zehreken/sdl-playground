#include "game.h"
#include "gameObject.h"
#include "constants.h"

const int GAME_OBJECT_COUNT = 100;
GameObject gameObjects[GAME_OBJECT_COUNT];

void initGame()
{
    for (int i = 0; i < GAME_OBJECT_COUNT; i++)
    {
        gameObjects[i].position.x = rand() / (RAND_MAX + 1.0) * WIDTH;
        gameObjects[i].position.y = rand() / (RAND_MAX + 1.0) * HEIGHT;
        gameObjects[i].boxSize.x = gameObjects[i].boxSize.y = 10 *  (rand() / (RAND_MAX + 1.0)) * 90;
    }
}

void update()
{
    for (int i = 0; i < GAME_OBJECT_COUNT; i++)
    {
        drawCollider();
        drawImage();
    }
}
