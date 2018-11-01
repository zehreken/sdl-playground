#ifndef COLLISION_H
#define COLLISION_H

#include "stdbool.h"
#include "primitives.h"

bool solveCollision(Box2D *a, Box2D *b);
void solvePhysics(Box2D *boxes, int size);

#endif
