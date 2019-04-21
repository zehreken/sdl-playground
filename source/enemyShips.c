#include "enemyShips.h"

const int ENEMY_SIZE = 8;
static GameObject enemyShips[ENEMY_SIZE];

void initEnemyShips(SDL_Renderer* renderer)
{
    for (int i = 0; i < ENEMY_SIZE; i++)
    {
        createGameObject(renderer, &enemyShips[i], "assets/enemyRed1.png");
        enemyShips[i].position.x = 50 + i * 100;
        enemyShips[i].position.y = -100;
        enemyShips[i].boxSize.x *= 0.5;
        enemyShips[i].boxSize.y *= 0.5;
    }
}

void updateEnemyShips(SDL_Renderer* renderer, float deltaTime)
{
    for (int i = 0; i < ENEMY_SIZE; i++)
    {
        enemyShips[i].position.y += deltaTime * 20;
        if (enemyShips[i].hasCollision)
        {
            enemyShips[i].position.x = 100000;
        }
        drawImage(renderer, &enemyShips[i]);
        drawCollider(renderer, enemyShips[i]);
    }
}

GameObject* getEnemyShips()
{
    return enemyShips;
}
