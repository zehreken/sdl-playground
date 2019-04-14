#include "background.h"

const int BACKGROUND_WIDTH = 4;
GameObject bgObjects[4];

void init_bg(SDL_Renderer* renderer)
{
    for (int i = 0; i < BACKGROUND_WIDTH; i++)
    {
        createGameObject(renderer, &bgObjects[i], "assets/blue.png");
        bgObjects[i].rect.x = i * 256;
    }
}

void update_bg(SDL_Renderer* renderer, double deltaTime)
{
    for (int i = 0; i < BACKGROUND_WIDTH; i++)
    {
        SDL_RenderCopy(renderer, bgObjects[0].texture, NULL, &bgObjects[i].rect);
    }
}
