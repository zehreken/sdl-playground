#include "physics.h"

void solveCollisionGame(GameObject* a, GameObject* b)
{
    if (a->position.x < b->position.x + b->rect.w &&
        a->position.x + a->rect.w > b->position.x &&
        a->position.y < b->position.y + b->rect.h &&
        a->position.y + a->rect.h > b->position.y)
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
