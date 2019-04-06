#include "gameObject.h"
#include "SDL2_image/SDL_image.h"

void createGameObject(SDL_Renderer* renderer, GameObject gameObject)
{
    gameObject.surface = IMG_Load("assets/playerShip1_blue.png");
    gameObject.texture = SDL_CreateTextureFromSurface(renderer, gameObject.surface);
    gameObject.rect.x = gameObject.rect.y = 400;
    gameObject.rect.w = 99;
    gameObject.rect.h = 75;
}

void drawCollider(SDL_Renderer* renderer, GameObject gameObject)
{
    ColorRGB color;
    color.r = 255;
    color.g = 255;
    color.b = 255;
    SDL_Rect pos = gameObject.rect;
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(renderer, pos.x, pos.y, pos.x, pos.y + pos.h);
    SDL_RenderDrawLine(renderer, pos.x, pos.y, pos.x + pos.w, pos.y);
    SDL_RenderDrawLine(renderer, pos.x + pos.w, pos.y, pos.x + pos.w, pos.y + pos.h);
    SDL_RenderDrawLine(renderer, pos.x, pos.y + pos.h, pos.x + pos.w, pos.y + pos.h);
}

void drawImage(SDL_Renderer* renderer, GameObject gameObject)
{
    SDL_RenderCopy(renderer, gameObject.texture, NULL, &gameObject.rect);
}
