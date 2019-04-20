#include "physics.h"

void solveCollisionGame(GameObject* a, GameObject* b)
{
    if (a->boxPosition.x < b->boxPosition.x + b->boxSize.x &&
        a->boxPosition.x + a->boxSize.x > b->boxPosition.x &&
        a->boxPosition.y < b->boxPosition.y + b->boxSize.y &&
        a->boxPosition.y + a->boxSize.y > b->boxPosition.y)
    {
        a->hasCollision = true;
        b->hasCollision = true;
    }
}

void solvePhysicsGame(GameObject* a, int size_a, GameObject* b, int size_b)
{
    for (int i = 0; i < size_a; i++)
    {
        a[i].hasCollision = false;
    }
    for (int i = 0; i < size_b; i++)
    {
        b[i].hasCollision = false;
    }
    
    for (int i = 0; i < size_a; i++)
    {
        for (int j = 0; j < size_b; j++)
        {
            solveCollisionGame(&a[i], &b[j]);
        }
    }
}
