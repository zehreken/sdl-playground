#include "laserBeam.h"
#include "gameObject.h"

static const int LASER_BEAM_SIZE = 20;
GameObject laserBeams[LASER_BEAM_SIZE];

void initLaserBeam(SDL_Renderer* renderer)
{
    for (int i = 0; i < LASER_BEAM_SIZE; i++)
    {
        createGameObject(renderer, &laserBeams[i], "assets/laserBlue07.png");
    }
}

void fireLaserBeam()
{
    
}

void updateLaserBeam(SDL_Renderer* renderer)
{
    for (int i = 0; i < LASER_BEAM_SIZE; i++)
    {
        drawCollider(renderer, laserBeams[i]);
        drawImage(renderer, laserBeams[i]);
    }
}
