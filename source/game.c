#include "game.h"
#include "SDL2_ttf/SDL_ttf.h"
#include "SDL2_image/SDL_image.h"
#include "gameObject.h"
#include "constants.h"

const int GAME_OBJECT_COUNT = 100;
GameObject gameObjects[GAME_OBJECT_COUNT];
SDL_bool done;

bool goUp;
bool goLeft;
bool goDown;
bool goRight;

void getInput();

void initGame()
{
    window = NULL;
    renderer = NULL;
    done = SDL_FALSE;
    
    goUp = false;
    goLeft = false;
    goDown = false;
    goRight = false;
    
    for (int i = 0; i < GAME_OBJECT_COUNT; i++)
    {
        gameObjects[i].position.x = rand() / (RAND_MAX + 1.0) * WIDTH;
        gameObjects[i].position.y = rand() / (RAND_MAX + 1.0) * HEIGHT;
        gameObjects[i].boxSize.x = gameObjects[i].boxSize.y = 10 *  (rand() / (RAND_MAX + 1.0)) * 90;
    }
    
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
            
            SDL_Color color = { 255, 255, 255, 255 };
            SDL_Surface* surface = TTF_RenderText_Solid(font, "testing testing", color);
            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
            SDL_Rect textRect;
            textRect.x = textRect.y = 0;
            SDL_QueryTexture(texture, NULL, NULL, &textRect.w, &textRect.h);
            
            SDL_RenderCopy(renderer, texture, NULL, &textRect);
            SDL_RenderPresent(renderer);
            
            while (!done)
            {
                getInput();
            }
        }
    }
}

void getInput()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_w)
                {
                    goUp = true;
                }
                if (event.key.keysym.sym == SDLK_a)
                {
                    goLeft = true;
                }
                if (event.key.keysym.sym == SDLK_s)
                {
                    goDown = true;
                }
                if (event.key.keysym.sym == SDLK_d)
                {
                    goRight = true;
                }
                break;
            case SDL_KEYUP:
                if (event.key.keysym.sym == SDLK_w)
                {
                    goUp = false;
                }
                if (event.key.keysym.sym == SDLK_a)
                {
                    goLeft = false;
                }
                if (event.key.keysym.sym == SDLK_s)
                {
                    goDown = false;
                }
                if (event.key.keysym.sym == SDLK_d)
                {
                    goRight = false;
                }
                break;
            case SDL_QUIT:
                done = SDL_TRUE;
                break;
        }
    }
}

void drawFPS()
{
//    float f = getAverageFps();
//    char c[50];
//    sprintf(c, "%g", deltaTime);
//    strcat(c, " deltaTime");
//    timePerFrame = 0;
//    surface = TTF_RenderText_Solid(font, c, color);
//    texture = SDL_CreateTextureFromSurface(renderer, surface);
}

void updateGame()
{
//    drawCollider(renderer, gameObjects);
//    drawImage(renderer, gameObjects[i]);
}
