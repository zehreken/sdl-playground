#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "SDL2/SDL.h"
#include "gameObject.h"

void initBg(SDL_Renderer* renderer);
void updateBg(SDL_Renderer* renderer, float deltaTime);

#endif
