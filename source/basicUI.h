#ifndef BASICUI_h
#define BASICUI_h

#include "SDL2/SDL.h"

void initBasicUI();
void drawStartUI(SDL_Renderer*);
void drawPlayUI(SDL_Renderer*);
void drawEndGameUI(SDL_Renderer*);
void quitBasicUI();

#endif
