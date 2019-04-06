#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "SDL2/SDL.h"
#include "primitives.h"

typedef struct GameObjectTag
{
    Vector2 position;
    IntVector2 boxSize;
    SDL_Surface* surface;
    SDL_Texture* texture;
    SDL_Rect rect;
} GameObject;

void createGameObject(SDL_Renderer* renderer, GameObject* gameObject, int i);
void drawCollider(SDL_Renderer* renderer, GameObject gameObject);
void drawImage(SDL_Renderer* renderer, GameObject GameObject);

#endif
