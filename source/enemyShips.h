#ifndef ENEMYSHIPS_H
#define ENEMYSHIPS_H

#include "gameObject.h"

void initEnemyShips(SDL_Renderer* renderer);
void spawnEnemyShip(Vector2 position);
void updateEnemyShips(SDL_Renderer* renderer, float deltaTime);
GameObject* getEnemyShips();

#endif
