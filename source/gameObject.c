#include "gameObject.h"
#include "SDL2_image/SDL_image.h"

void createGameObject(SDL_Renderer* renderer, GameObject* gameObject, char img[])
{
    gameObject->surface = IMG_Load(img);
    gameObject->texture = SDL_CreateTextureFromSurface(renderer, gameObject->surface);
    SDL_QueryTexture(gameObject->texture, NULL, NULL, &gameObject->rect.w, &gameObject->rect.h);
    gameObject->boxSize.x = gameObject->rect.w;
    gameObject->boxSize.y = gameObject->rect.h;
}

void drawImage(SDL_Renderer* renderer, GameObject* gameObject)
{
    // Offset the rect and collider box so the center is in the center
    gameObject->rect.x = gameObject->position.x - gameObject->rect.w * 0.5;
    gameObject->rect.y = gameObject->position.y - gameObject->rect.h * 0.5;
    gameObject->boxPosition.x = gameObject->position.x - gameObject->boxSize.x * 0.5;
    gameObject->boxPosition.y = gameObject->position.y - gameObject->boxSize.y * 0.5;
    SDL_RenderCopy(renderer, gameObject->texture, NULL, &gameObject->rect);
}

static inline void drawPositionPoint(SDL_Renderer* renderer, GameObject gameObject)
{
    SDL_SetRenderDrawColor(renderer, 255, 0, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawPoint(renderer, gameObject.position.x, gameObject.position.y);
}

void drawCollider(SDL_Renderer* renderer, GameObject gameObject)
{
    ColorRGB color;
    color.r = 255;
    color.g = 255;
    color.b = 255;
    
    if (gameObject.hasCollision)
    {
        color.g = 0;
        color.b = 0;
    }
    
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, SDL_ALPHA_OPAQUE);
    IntVector2 pos = gameObject.boxPosition;
    IntVector2 size = gameObject.boxSize;
    SDL_RenderDrawLine(renderer, pos.x, pos.y, pos.x, pos.y + size.y);
    SDL_RenderDrawLine(renderer, pos.x, pos.y, pos.x + size.x, pos.y);
    SDL_RenderDrawLine(renderer, pos.x + size.x, pos.y, pos.x + size.x, pos.y + size.y);
    SDL_RenderDrawLine(renderer, pos.x, pos.y + size.y, pos.x + size.x, pos.y + size.y);
    
    drawPositionPoint(renderer, gameObject);
}
