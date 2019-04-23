#include "enemyShips.h"
#include "scoreController.h"

const int ENEMY_SIZE = 8;
static GameObject enemyShips[ENEMY_SIZE];
static bool enemyShipActive[ENEMY_SIZE];

void initEnemyShips(SDL_Renderer* renderer)
{
    for (int i = 0; i < ENEMY_SIZE; i++)
    {
        createGameObject(renderer, &enemyShips[i], "assets/enemyRed1.png");
        enemyShips[i].position.x = 50 + i * 100;
        enemyShips[i].position.y = -100;
        enemyShips[i].boxSize.x *= 0.5;
        enemyShips[i].boxSize.y *= 0.5;
        enemyShipActive[i] = true;
    }
}

void spawnEnemyShip(Vector2 position)
{
    for (int i = 0; i < ENEMY_SIZE; i++)
    {
        if (!enemyShipActive[i])
        {
            enemyShipActive[i] = true;
            enemyShips[i].position = position;
        }
    }
}

void updateEnemyShips(SDL_Renderer* renderer, float deltaTime)
{
    for (int i = 0; i < ENEMY_SIZE; i++)
    {
        if (enemyShipActive[i])
        {
            enemyShips[i].position.y += deltaTime * 50;
            if (enemyShips[i].hasCollision)
            {
                enemyShips[i].position.x = 100000;
                addScore(20);
                enemyShipActive[i] = false;
                return;
            }
            drawImage(renderer, &enemyShips[i]);
            drawCollider(renderer, enemyShips[i]);
        }
    }
}

// Obsolete
GameObject* getEnemyShips()
{
    return enemyShips;
}
