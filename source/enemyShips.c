#include "enemyShips.h"

const int ENEMY_SIZE = 8;
static GameObject enemyShips[ENEMY_SIZE];

void initEnemyShips(SDL_Renderer* renderer)
{
    for (int i = 0; i < ENEMY_SIZE; i++)
    {
        createGameObject(renderer, &enemyShips[i], "assets/enemyRed1.png");
        enemyShips[i].position.x = i * 100;
        enemyShips[i].position.y = 100;
    }
}

void updateEnemyShips(SDL_Renderer* renderer, float deltaTime)
{
    for (int i = 0; i < ENEMY_SIZE; i++)
    {
        drawCollider(renderer, enemyShips[i]);
        drawImage(renderer, enemyShips[i]);
    }
}

GameObject* getEnemyShips()
{
    return enemyShips;
}
