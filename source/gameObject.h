#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "SDL2/SDL.h"
#include "primitives.h"

typedef struct GameObjectTag
{
    Vector2 position;
    IntVector2 boxPosition;
    IntVector2 boxSize;
    SDL_Surface* surface;
    SDL_Texture* texture;
    SDL_Rect rect;
    bool hasCollision;
} GameObject;

void createGameObject(SDL_Renderer* renderer, GameObject* gameObject, char img[]);
void drawImage(SDL_Renderer* renderer, GameObject* GameObject);
void drawCollider(SDL_Renderer* renderer, GameObject gameObject);

#endif
