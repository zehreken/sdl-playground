#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include "SDL2/SDL.h"
#include "stdbool.h"

typedef struct ColorRGBTag
{
    int r;
    int g;
    int b;
} ColorRGB;

typedef struct IntVector2Tag
{
    int x;
    int y;
} IntVector2;

typedef struct TriangleTag
{
    IntVector2 position;
    int size;
    ColorRGB color;
} Triangle;

typedef struct Box2DTag
{
    IntVector2 position;
    IntVector2 size;
    ColorRGB color;
    bool hasCollision;
} Box2D;

void drawTriangle(SDL_Renderer* renderer, int i);
void drawBox(SDL_Renderer* renderer, Box2D box2D);
void drawDots(SDL_Renderer* renderer);

#endif
