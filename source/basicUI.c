#include "basicUI.h"
#include "SDL2_ttf/SDL_ttf.h"
#include "timeUtils.h"

static TTF_Font* font;
static SDL_Surface* surface;
static SDL_Texture* texture;
static SDL_Rect textRect;
static SDL_Color color = { 255, 0, 255, 255 };

void initBasicUI(SDL_Renderer* renderer)
{
    if (TTF_Init() == -1)
        printf("TTF_Init error");
    font = TTF_OpenFont("fonts/emulogic.ttf", 20);
    if (!font)
        printf("Font loading error");
    
    surface = TTF_RenderText_Solid(font, "testing testing", color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    textRect.x = textRect.y = 0;
    SDL_QueryTexture(texture, NULL, NULL, &textRect.w, &textRect.h);
}

void updateBasicUI(SDL_Renderer* renderer)
{
    float deltaTime = getDeltaTimeInSeconds();
    
//    float f = getAverageFps();
    char c[50];
    char b[11] = " totalTime";
    sprintf(c, "%g", deltaTime);
    strcat(c, b);
    surface = TTF_RenderText_Solid(font, c, color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_QueryTexture(texture, NULL, NULL, &textRect.w, &textRect.h);
    
    SDL_RenderCopy(renderer, texture, NULL, &textRect);
}

void closeFont()
{
    TTF_CloseFont(font);
}

void quitBasicUI()
{
//    TTF_CloseFont(font);
    TTF_Quit();
}
