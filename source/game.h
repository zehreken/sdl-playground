#ifndef GAME_H
#define GAME_H

#include "SDL2/SDL.h"

// Variables
SDL_Window* window;
SDL_Renderer* renderer;

// Methods
int startGame();
void updateGame();

#endif
