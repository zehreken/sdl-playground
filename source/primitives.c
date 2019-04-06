#include "primitives.h"
#include "constants.h"

void drawBox(SDL_Renderer* renderer, Box2D box2D)
{
    Vector2 pos = box2D.position;
    IntVector2 size = box2D.size;
    if (box2D.hasCollision)
    {
        box2D.color.r = 255;
        box2D.color.g = box2D.color.b = 0;
    }
    else
    {
        box2D.color.r = box2D.color.b = 0;
        box2D.color.g = 255;
    }
    ColorRGB color = box2D.color;
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, SDL_ALPHA_OPAQUE);
//    SDL_RenderDrawLine(renderer, pos.x - size.x / 2, pos.y - size.y / 2, pos.x - size.x / 2, pos.y + size.y / 2); // left
//    SDL_RenderDrawLine(renderer, pos.x - size.x / 2, pos.y - size.y / 2, pos.x + size.x / 2, pos.y - size.y / 2); // top
//    SDL_RenderDrawLine(renderer, pos.x + size.x / 2, pos.y - size.y / 2, pos.x + size.x / 2, pos.y + size.y / 2); // right
//    SDL_RenderDrawLine(renderer, pos.x - size.x / 2, pos.y + size.y / 2, pos.x + size.x / 2, pos.y + size.y / 2); // bottom
    SDL_RenderDrawLine(renderer, pos.x, pos.y, pos.x, pos.y + size.y);
    SDL_RenderDrawLine(renderer, pos.x, pos.y, pos.x + size.x, pos.y);
    SDL_RenderDrawLine(renderer, pos.x + size.x, pos.y, pos.x + size.x, pos.y + size.y);
    SDL_RenderDrawLine(renderer, pos.x, pos.y + size.y, pos.x + size.x, pos.y + size.y);
}

void drawDots(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, SDL_ALPHA_OPAQUE);
    for (int i = 0; i < WIDTH; i++)
    {
        int rnd = (rand() / (RAND_MAX + 1.0)) * HEIGHT;
        SDL_RenderDrawPoint(renderer, i, rnd);
    }
}
