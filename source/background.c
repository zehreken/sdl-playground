#include "background.h"

const int BACKGROUND_ROW = 5;
const int BACKGROUND_COLUMN = 4;
GameObject bgObjects[BACKGROUND_ROW * BACKGROUND_COLUMN];

void init_bg(SDL_Renderer* renderer)
{
    for (int i = 0; i < BACKGROUND_ROW; i++)
    {
        for (int j = 0; j < BACKGROUND_COLUMN; j++)
        {
            int index = i * BACKGROUND_COLUMN + j;
            createGameObject(renderer, &bgObjects[index], "assets/purple.png");
            bgObjects[index].rect.x = j * 256;
            bgObjects[index].rect.y = i * 256;
        }
    }
}

void update_bg(SDL_Renderer* renderer, double deltaTime)
{
    for (int i = 0; i < BACKGROUND_ROW; i++)
    {
        for (int j = 0; j < BACKGROUND_COLUMN; j++)
        {
            int index = i * BACKGROUND_COLUMN + j;
            SDL_RenderCopy(renderer, bgObjects[index].texture, NULL, &bgObjects[index].rect);
        }
    }
}
