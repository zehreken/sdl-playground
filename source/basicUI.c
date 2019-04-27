#include "basicUI.h"
#include "SDL2_ttf/SDL_ttf.h"
#include "timeUtils.h"
#include "constants.h"
#include "playerShip.h"
#include "scoreController.h"

static char scoreString[20];
static char hpString[7];
static TTF_Font* font;
static SDL_Surface* scoreSurface;
static SDL_Texture* scoreTexture;
static SDL_Rect scoreRect;
static SDL_Color color = { 255, 255, 255, 255 };

static SDL_Surface* playerHitPointSurface;
static SDL_Texture* playerHitPointTexture;
static SDL_Rect playerHitPointRect;

static SDL_Surface* infoSurface;
static SDL_Texture* infoTexture;
static SDL_Rect infoRect;

static const float UI_UPDATE_PERIOD = 0.25;
static float updateTimer = 1;

void initBasicUI(SDL_Renderer* renderer)
{
    font = TTF_OpenFont("fonts/emulogic.ttf", 20);
    if (!font)
        printf("Font loading error");
}

void drawStartUI(SDL_Renderer* renderer)
{
    float deltaTime = getDeltaTimeInSeconds();
    updateTimer += deltaTime;
    
    if (updateTimer >= UI_UPDATE_PERIOD)
    {
        updateTimer -= UI_UPDATE_PERIOD;
        
    }
}

void drawPlayUI(SDL_Renderer* renderer)
{
    float deltaTime = getDeltaTimeInSeconds();
    updateTimer += deltaTime;
    
    if (updateTimer >= UI_UPDATE_PERIOD)
    {
        updateTimer -= UI_UPDATE_PERIOD;
    
//        puts(c);
//        strcat(c, b);
        
        sprintf(scoreString, "SCORE:%d", getScore());
        // Free old texture
        SDL_DestroyTexture(scoreTexture);
        scoreSurface = TTF_RenderText_Solid(font, scoreString, color);
        scoreTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);
        // Free old surface
        SDL_FreeSurface(scoreSurface);
        SDL_QueryTexture(scoreTexture, NULL, NULL, &scoreRect.w, &scoreRect.h);
        
        sprintf(hpString, "HP:%d", getPlayerShipHitPoint());
        // Free old texture
        SDL_DestroyTexture(playerHitPointTexture);
        playerHitPointSurface = TTF_RenderText_Solid(font, hpString, color);
        playerHitPointTexture = SDL_CreateTextureFromSurface(renderer, playerHitPointSurface);
        // Free old surface
        SDL_FreeSurface(playerHitPointSurface);
        SDL_QueryTexture(playerHitPointTexture, NULL, NULL, &playerHitPointRect.w, &playerHitPointRect.h);
        playerHitPointRect.x = WIDTH - playerHitPointRect.w;
    }
    
    SDL_RenderCopy(renderer, scoreTexture, NULL, &scoreRect);
    SDL_RenderCopy(renderer, playerHitPointTexture, NULL, &playerHitPointRect);
}

void drawEndGameUI(SDL_Renderer* renderer)
{
    float deltaTime = getDeltaTimeInSeconds();
    updateTimer += deltaTime;
    
    if (updateTimer >= UI_UPDATE_PERIOD)
    {
        updateTimer -= UI_UPDATE_PERIOD;
        
        SDL_DestroyTexture(infoTexture);
        infoSurface = TTF_RenderText_Solid(font, "GAME OVER", color);
        infoTexture = SDL_CreateTextureFromSurface(renderer, infoSurface);
        // Free old surface
        SDL_FreeSurface(infoSurface);
        SDL_QueryTexture(infoTexture, NULL, NULL, &infoRect.w, &infoRect.h);
        infoRect.w *= 2;
        infoRect.h *= 2;
        infoRect.x = (WIDTH - infoRect.w) / 2;
        infoRect.y = (HEIGHT - infoRect.h) / 2;
    }
    
    SDL_RenderCopy(renderer, infoTexture, NULL, &infoRect);
}

void quitBasicUI()
{
    TTF_CloseFont(font);
}
