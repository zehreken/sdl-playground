#include "gameObject.h"
#include "SDL2_image/SDL_image.h"

void createGameObject(SDL_Renderer* renderer, GameObject* gameObject, int i)
{
    gameObject->surface = IMG_Load("assets/playerShip1_blue.png");
    gameObject->texture = SDL_CreateTextureFromSurface(renderer, gameObject->surface);
    gameObject->rect.x = gameObject->rect.y = 100 + i * 50;
    gameObject->rect.w = 99;
    gameObject->rect.h = 75;
}

void drawCollider(SDL_Renderer* renderer, GameObject gameObject)
{
    ColorRGB color;
    color.r = 255;
    color.g = 255;
    color.b = 255;
    if (gameObject.hasCollision)
    {
        color.r = 0;
    }
    SDL_Rect rect;
    rect.x = gameObject.position.x;
    rect.y = gameObject.position.y;
    rect.w = gameObject.rect.w;
    rect.h = gameObject.rect.h;
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(renderer, rect.x, rect.y, rect.x, rect.y + rect.h);
    SDL_RenderDrawLine(renderer, rect.x, rect.y, rect.x + rect.w, rect.y);
    SDL_RenderDrawLine(renderer, rect.x + rect.w, rect.y, rect.x + rect.w, rect.y + rect.h);
    SDL_RenderDrawLine(renderer, rect.x, rect.y + rect.h, rect.x + rect.w, rect.y + rect.h);
}

void drawImage(SDL_Renderer* renderer, GameObject gameObject)
{
    gameObject.rect.x = gameObject.position.x;
    gameObject.rect.y = gameObject.position.y;
    SDL_RenderCopy(renderer, gameObject.texture, NULL, &gameObject.rect);
}
