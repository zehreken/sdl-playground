#include "game.h"
#include "SDL2_ttf/SDL_ttf.h"
#include "SDL2_image/SDL_image.h"
#include "gameObject.h"
#include "constants.h"

const int GAME_OBJECT_COUNT = 100;
GameObject gameObjects[GAME_OBJECT_COUNT];

void initGame()
{
    window = NULL;
    renderer = NULL;
    
    if (SDL_Init(SDL_INIT_VIDEO) == 0)
    {
        if (SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer) == 0)
        {
            if (TTF_Init() == -1)
                printf("TTF_Init error");
            TTF_Font* font = TTF_OpenFont("fonts/emulogic.ttf", 8);
            if (!font)
                printf("Font loading error");
            
            int IMG_Flag = 0;
            if (IMG_Init(IMG_Flag) == -1)
                printf("IMG_Init error");
            
            SDL_bool done = SDL_FALSE;
            int i = 0;
            
            while (!done)
            {
                SDL_Event event;
                while (SDL_PollEvent(&event))
                {
                    switch (event.type)
                    {
                        case SDL_QUIT:
                            done = SDL_TRUE;
                            break;
                    }
                }
            }
        }
        
        for (int i = 0; i < GAME_OBJECT_COUNT; i++)
        {
            gameObjects[i].position.x = rand() / (RAND_MAX + 1.0) * WIDTH;
            gameObjects[i].position.y = rand() / (RAND_MAX + 1.0) * HEIGHT;
            gameObjects[i].boxSize.x = gameObjects[i].boxSize.y = 10 *  (rand() / (RAND_MAX + 1.0)) * 90;
        }
    }
}

void updateGame()
{
//    drawCollider(renderer, gameObjects);
//    drawImage(renderer, gameObjects[i]);
}
