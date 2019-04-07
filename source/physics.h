#ifndef PHYSICS_H
#define PHYSICS_H

#include "stdbool.h"
#include "primitives.h"

void solveCollision(Box2D *a, Box2D *b);
void solvePhysics(Box2D *boxes, int size);
void solvePhysicsGame();

#endif
