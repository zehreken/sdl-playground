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
    else
    {
//        a->hasCollision = false;
//        b->hasCollision = false;
    }
}

void solvePhysicsGame(GameObject* a, int size_a, GameObject* b, int size_b)
{
//    a[0].hasCollision = false; // What is this for?
    for (int i = 0; i < size_a; i++)
    {
        for (int j = 0; j < size_b; j++)
        {
//            a[i].hasCollision = false;
//            b[j].hasCollision = false;
            if (i == 0 && j == 4)
                printf("[physics.c] %d %f\n", a[0].rect.h, b[4].position.x);
            solveCollisionGame(&a[i], &b[j]);
        }
    }
}
