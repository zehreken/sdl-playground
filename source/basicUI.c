#include "basicUI.h"
#include "SDL2_ttf/SDL_ttf.h"
#include "timeUtils.h"
#include "constants.h"
#include "playerShip.h"

static char c[50];
static char b[11] = " totalTime";
static TTF_Font* font;
static SDL_Surface* surface;
static SDL_Texture* texture;
static SDL_Rect textRect;
static SDL_Color color = { 255, 255, 255, 255 };

static SDL_Surface* playerHitPointSurface;
static SDL_Texture* playerHitPointTexture;
static SDL_Rect playerHitPointRect;

static const float UI_UPDATE_PERIOD = 1;
static float updateTimer = 0;

void initBasicUI(SDL_Renderer* renderer)
{
    font = TTF_OpenFont("fonts/emulogic.ttf", 20);
    if (!font)
        printf("Font loading error");
    
    surface = TTF_RenderText_Solid(font, "testing testing", color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    textRect.x = textRect.y = 0;
    SDL_QueryTexture(texture, NULL, NULL, &textRect.w, &textRect.h);
}

void updateBasicUI(SDL_Renderer* renderer)
{
    float deltaTime = getDeltaTimeInSeconds();
    updateTimer += deltaTime;
    
    if (updateTimer >= UI_UPDATE_PERIOD)
    {
        updateTimer -= UI_UPDATE_PERIOD;
//        float f = getAverageFps();
    
        sprintf(c, "DeltaTime: %f", deltaTime);
//    puts(c);
//    strcat(c, b);
        
        // Free old texture
        SDL_DestroyTexture(texture);
        surface = TTF_RenderText_Solid(font, c, color);
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
        SDL_QueryTexture(texture, NULL, NULL, &textRect.w, &textRect.h);
    
//    playerHitPointSurface = TTF_RenderText_Solid(font, getPlayerHitPoint(), color);
//    playerHitPointTexture = SDL_CreateTextureFromSurface(renderer, playerHitPointSurface);
//    SDL_QueryTexture(playerHitPointTexture, NULL, NULL, &playerHitPointRect.w, &playerHitPointRect.h);
//    playerHitPointRect.x = WIDTH - playerHitPointRect.w;
//    playerHitPointRect.y = HEIGHT - playerHitPointRect.h;
    }
    
    SDL_RenderCopy(renderer, texture, NULL, &textRect);
}

void quitBasicUI()
{
    TTF_CloseFont(font);
}
