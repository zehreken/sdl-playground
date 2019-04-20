#include "laserBeam.h"

static const int LASER_BEAM_SIZE = 20;
static GameObject laserBeams[LASER_BEAM_SIZE];
static bool laserBeamActive[LASER_BEAM_SIZE];

void initLaserBeam(SDL_Renderer* renderer)
{
    for (int i = 0; i < LASER_BEAM_SIZE; i++)
    {
        createGameObject(renderer, &laserBeams[i], "assets/laserBlue07.png");
        laserBeamActive[i] = false;
    }
}

void fireLaserBeam(Vector2 position)
{
    for (int i = 0; i < LASER_BEAM_SIZE; i++)
    {
        if (!laserBeamActive[i])
        {
            laserBeamActive[i] = true;
            laserBeams[i].position = position;
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
            drawCollider(renderer, laserBeams[i]);
            drawImage(renderer, &laserBeams[i]);
        }
    }
}

GameObject* getLaserBeams()
{
    return laserBeams;
}
