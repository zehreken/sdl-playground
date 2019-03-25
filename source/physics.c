#include "physics.h"

void solveCollision(Box2D *a, Box2D *b)
{
    bool hasCollision = false;
    if (a->position.x < b->position.x + b->size.x &&
        a->position.x + a->size.x > b->position.x &&
        a->position.y < b->position.y + b->size.y &&
        a->position.y + a->size.y > b->position.y)
    {
        // There is collision
        a->hasCollision = true;
        b->hasCollision = true;
    }
    else
    {
        b->hasCollision = false;
    }
}

void solvePhysics(Box2D boxes[], int size)
{
    boxes[0].hasCollision = false;
    for (int i = 0; i < 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            solveCollision(&boxes[i], &boxes[j]);
        }
    }
}
