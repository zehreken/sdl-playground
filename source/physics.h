#ifndef PHYSICS_H
#define PHYSICS_H

#include "stdbool.h"
#include "primitives.h"
#include "gameObject.h"

void solvePhysics(Box2D* boxes, int size);
void solvePhysicsGame(GameObject* a, int size_a, GameObject* b, int size_b);

#endif
