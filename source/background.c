#include "background.h"

const int BACKGROUND_ROW = 5;
const int BACKGROUND_COLUMN = 4;
const int BACKGROUND_SPEED = 400;
GameObject bgObjects[BACKGROUND_ROW][BACKGROUND_COLUMN];

void initBg(SDL_Renderer* renderer)
{
    for (int i = 0; i < BACKGROUND_ROW; i++)
    {
        for (int j = 0; j < BACKGROUND_COLUMN; j++)
        {
            createGameObject(renderer, &bgObjects[i][j], "assets/purple.png");
            bgObjects[i][j].position.x = bgObjects[i][j].rect.x = j * bgObjects[i][j].rect.w;
            bgObjects[i][j].position.y = bgObjects[i][j].rect.y = (i - 1) * bgObjects[i][j].rect.h;
        }
    }
}

void updateBg(SDL_Renderer* renderer, double deltaTime)
{
    for (int i = 0; i < BACKGROUND_ROW; i++)
    {
        for (int j = 0; j < BACKGROUND_COLUMN; j++)
        {
            if (bgObjects[i][j].position.y >= 768)
            {
                int nextRow = i + 1 == BACKGROUND_ROW ? 0 : i + 1;
                bgObjects[i][j].position.y = bgObjects[nextRow][j].position.y - 256;
            }
            
            bgObjects[i][j].position.y += deltaTime * BACKGROUND_SPEED;
            bgObjects[i][j].rect.y = bgObjects[i][j].position.y;
            
            SDL_RenderCopy(renderer, bgObjects[i][j].texture, NULL, &bgObjects[i][j].rect);
        }
    }
}
