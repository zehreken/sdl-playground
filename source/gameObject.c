#include "gameObject.h"
#include "SDL2_image/SDL_image.h"

void initGameObject(SDL_Renderer* renderer, GameObject gameObject)
{
    gameObject.surface = IMG_Load("assets/playerShip1_blue.png");
    gameObject.texture = SDL_CreateTextureFromSurface(renderer, gameObject.surface);
    gameObject.rect.w = 99;
    gameObject.rect.h = 75;
}

void drawCollider(SDL_Renderer* renderer, GameObject gameObject)
{
    
}

void drawImage(SDL_Renderer* renderer, GameObject gameObject)
{
    
}
