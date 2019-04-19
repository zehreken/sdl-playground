#ifndef LASERBEAM_H
#define LASERBEAM_H

#include "SDL2/SDL.h"

void initLaserBeam(SDL_Renderer* renderer);
void fireLaserBeam();
void updateLaserBeam(SDL_Renderer* renderer, double deltaTime);

#endif
