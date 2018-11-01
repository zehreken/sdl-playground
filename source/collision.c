#include "collision.h"

bool solveCollision(Box2D *a, Box2D *b)
{
    bool hasCollision = false;
    if (a->position.x < b->position.x + b->size.x &&
        a->position.x + a->size.x > b->position.x &&
        a->position.y < b->position.y + b->size.y &&
        a->position.y + a->size.y > b->position.y)
    {
        // There is collision
        a->color.r = b->color.r = 255;
        a->color.g = a->color.b = b->color.g = b->color.b = 0;
        hasCollision = true;
    }
    else
    {
        a->color.r = a->color.b = b->color.r = b->color.b = 0;
        a->color.g = b->color.g = 255;
    }
    return hasCollision;
}

void solvePhysics(Box2D boxes[], int size)
{
    for (int i = 0; i < 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (solveCollision(&boxes[i], &boxes[j]))
            {
                break;
            }
        }
    }
}
