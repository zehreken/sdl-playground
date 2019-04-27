#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H

#include "gameObject.h"

bool goUp;
bool goLeft;
bool goDown;
bool goRight;

void initPlayerShip(SDL_Renderer* renderer);
void updatePlayerShip(SDL_Renderer* renderer, float deltaTime);
int getPlayerShipHitPoint();
GameObject* getPlayerShip();
void fire();

#endif
