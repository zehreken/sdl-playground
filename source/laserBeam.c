#include "laserBeam.h"
#include "constants.h"

static const int LASER_BEAM_SIZE = 20;
static GameObject laserBeams[LASER_BEAM_SIZE];
static bool laserBeamActive[LASER_BEAM_SIZE];
static GameObject enemyLaserBeams[LASER_BEAM_SIZE];
static bool enemyLaserBeamActive[LASER_BEAM_SIZE];

void initLaserBeam(SDL_Renderer* renderer)
{
    for (int i = 0; i < LASER_BEAM_SIZE; i++)
    {
        createGameObject(renderer, &laserBeams[i], "assets/laserBlue07.png");
        laserBeamActive[i] = false;
        
        createGameObject(renderer, &enemyLaserBeams[i], "assets/laserRed04.png");
        enemyLaserBeamActive[i] = false;
    }
}

void fireLaserBeam(Vector2 position, bool isEnemy)
{
    for (int i = 0; i < LASER_BEAM_SIZE; i++)
    {
        if (!isEnemy && !laserBeamActive[i])
        {
            laserBeamActive[i] = true;
            laserBeams[i].position = position;
            return;
        }
        else if (isEnemy && !enemyLaserBeamActive[i])
        {
            enemyLaserBeamActive[i] = true;
            enemyLaserBeams[i].position = position;
            return;
        }
    }
}

void updateLaserBeam(SDL_Renderer* renderer, float deltaTime)
{
    for (int i = 0; i < LASER_BEAM_SIZE; i++)
    {
        if (laserBeamActive[i])
        {
            laserBeams[i].position.y -= deltaTime * 600;
            if (laserBeams[i].position.y < 0 || laserBeams[i].hasCollision)
            {
                laserBeamActive[i] = false;
                laserBeams[i].position.x = -10000;
            }
            drawImage(renderer, &laserBeams[i]);
            drawCollider(renderer, laserBeams[i]);
        }
        if (enemyLaserBeamActive[i])
        {
            enemyLaserBeams[i].position.y += deltaTime * 600;
            if (enemyLaserBeams[i].position.y > HEIGHT || enemyLaserBeams[i].hasCollision)
            {
                enemyLaserBeamActive[i] = false;
                enemyLaserBeams[i].position.x = -10000;
            }
            drawImage(renderer, &enemyLaserBeams[i]);
            drawCollider(renderer, enemyLaserBeams[i]);
        }
    }
}

GameObject* getLaserBeams()
{
    return laserBeams;
}
