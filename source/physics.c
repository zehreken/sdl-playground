#include "physics.h"

static void solveCollision(Box2D* a, Box2D* b)
{
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
