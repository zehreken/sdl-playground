#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "SDL2/SDL.h"
#include "gameObject.h"

void init_bg(SDL_Renderer* renderer);
void update_bg(double deltaTime);

#endif
