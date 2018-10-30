#include "primitives.h"
#include "constants.h"

void drawTriangle(SDL_Renderer* renderer, int i)
{
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(renderer, 320 + i, 200, 300 + i, 240);
    SDL_RenderDrawLine(renderer, 300 + i , 240, 340 + i, 240);
    SDL_RenderDrawLine(renderer, 340 + i, 240, 320 + i, 200);
}

void drawBox(SDL_Renderer* renderer, Box2D box2D)
{
    IntVector2 pos = box2D.position;
    IntVector2 size = box2D.size;
    ColorRGB color = box2D.color;
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(renderer, pos.x - size.x / 2, pos.y - size.y / 2, pos.x - size.x / 2, pos.y + size.y / 2); // left
    SDL_RenderDrawLine(renderer, pos.x - size.x / 2, pos.y - size.y / 2, pos.x + size.x / 2, pos.y - size.y / 2); // top
    SDL_RenderDrawLine(renderer, pos.x + size.x / 2, pos.y - size.y / 2, pos.x + size.x / 2, pos.y + size.y / 2); // right
    SDL_RenderDrawLine(renderer, pos.x - size.x / 2, pos.y + size.y / 2, pos.x + size.x / 2, pos.y + size.y / 2); // bottom
}

void drawDots(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
    for (int i = 0; i < WIDTH; i++)
    {
        int rnd = (rand() / (RAND_MAX + 1.0)) * HEIGHT;
        SDL_RenderDrawPoint(renderer, i, rnd);
    }
}
