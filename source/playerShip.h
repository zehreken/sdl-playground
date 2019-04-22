#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H

#include "gameObject.h"

void initPlayerShip(SDL_Renderer* renderer);
void updatePlayerShip(SDL_Renderer* renderer, float deltaTime);
int getPlayerShipHitPoint();

#endif
