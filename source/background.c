#include "background.h"

GameObject bgObject;

void init_bg(SDL_Renderer* renderer)
{
    createGameObject(renderer, &bgObject, "assets/blue.png", 0);
}

void update_bg(double deltaTime)
{
    
}
