#include "enemyController.h"
#include "enemyShips.h"
#include "constants.h"

static const float SPAWN_PERIOD = 1;
static float spawnTimer = 0;

void initEnemyController()
{
}

void updateEnemyController(float deltaTime)
{
    spawnTimer += deltaTime;
    if (spawnTimer >= SPAWN_PERIOD)
    {
        spawnTimer -= SPAWN_PERIOD;
        Vector2 position = {(rand() / (RAND_MAX + 1.0)) * WIDTH, 0};
        spawnEnemyShip(position);
    }
}
