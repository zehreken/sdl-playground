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
} GameObject;

void init();
void drawBox();
void drawImage();

#endif
