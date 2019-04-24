#ifndef LASERBEAM_H
#define LASERBEAM_H

#include "SDL2/SDL.h"
#include "gameObject.h"

void initLaserBeam(SDL_Renderer* renderer);
void fireLaserBeam(Vector2 position, bool isEnemy);
void updateLaserBeam(SDL_Renderer* renderer, float deltaTime);
GameObject* getLaserBeams();
GameObject* getEnemyLaserBeams();

#endif
