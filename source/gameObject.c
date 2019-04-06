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
    
}

void drawImage(SDL_Renderer* renderer, GameObject gameObject)
{
    SDL_RenderCopy(renderer, gameObject.texture, NULL, &gameObject.rect);
}
