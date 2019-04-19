#include "game.h"
#include "SDL2_ttf/SDL_ttf.h"
#include "SDL2_image/SDL_image.h"
#include "gameObject.h"
#include "constants.h"
#include "fpsUtils.h"
#include "physics.h"
#include "background.h"
#include "playerShip.h"
#include "laserBeam.h"
#include "timeUtils.h"
#include "enemyShips.h"

//const int BOX_SIZE = 100;
//Box2D boxes[BOX_SIZE];
//SDL_Rect pngRect;

SDL_Window* window;
SDL_Renderer* renderer;

float deltaTime = 0;
float timePerFrame = 0;
float totalTime = 0;

void getInput();
void setInput();

int startGame()
{
    window = NULL;
    renderer = NULL;
    done = SDL_FALSE;
    
//    for (int i = 0; i < BOX_SIZE; i++)
//    {
//        boxes[i].position.x = rand() / (RAND_MAX + 1.0) * WIDTH;
//        boxes[i].position.y = rand() / (RAND_MAX + 1.0) * HEIGHT;
//        boxes[i].size.x = boxes[i].size.y = 10 + (rand() / (RAND_MAX + 1.0)) * 90;
//        boxes[i].color.r = 255;
//        boxes[i].color.g = 255;
//        boxes[i].color.b = 255;
//    }
    
    initTimeUtils();
    
    if (SDL_Init(SDL_INIT_VIDEO) == 0)
    {
        if (SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer) == 0)
        {
            if (TTF_Init() == -1)
                printf("TTF_Init error");
            TTF_Font* font = TTF_OpenFont("fonts/emulogic.ttf", 20);
            if (!font)
                printf("Font loading error");
            
            int IMG_Flag = 0;
            if (IMG_Init(IMG_Flag) == -1)
                printf("IMG_Init error");
            
            // Init background
            initBg(renderer);
			
			// Init player ship
            initPlayerShip(renderer);
            
            // Init laser beams
            initLaserBeam(renderer);
            
            // Init enemy ships
            initEnemyShips(renderer);
            
            SDL_Color color = { 255, 255, 255, 255 };
            SDL_Surface* surface = TTF_RenderText_Solid(font, "testing testing", color);
            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
            SDL_Rect textRect;
            textRect.x = textRect.y = 0;
            SDL_QueryTexture(texture, NULL, NULL, &textRect.w, &textRect.h);
            
            // MAIN LOOP
            while (!done)
            {
                updateTimeUtils();
                deltaTime = getDeltaTimeInSeconds();
                timePerFrame = timePerFrame + deltaTime;
                totalTime += deltaTime;
                calculateFps(deltaTime);
                
                // Background
                updateBg(renderer, deltaTime);
                
                // Update player ship
                updatePlayerShip(renderer, deltaTime);
				
				// Update laser beams
                updateLaserBeam(renderer, deltaTime);
                
                // Update enemy ships
                updateEnemyShips(renderer, deltaTime);
                
                // Text on the top left corner
                SDL_RenderCopy(renderer, texture, NULL, &textRect);
                // Set background color
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                // Draws everything
                SDL_RenderPresent(renderer);
                // Clears everything, I still don't understand how this works
                SDL_RenderClear(renderer);
                
//                solvePhysics(boxes, BOX_SIZE);
//                solvePhysicsGame(gameObjects, LASER_COUNT);
                solvePhysicsGame(getLaserBeams(), 20, getEnemyShips(), 8);
                
                if (timePerFrame < 0.0166666)
                {
                    continue;
                }
                else
                {
                    float f = getAverageFps();
                    char c[50];
                    char b[11] = " totalTime";
                    sprintf(c, "%g", totalTime);
                    strcat(c, b);
                    timePerFrame = 0;
                    surface = TTF_RenderText_Solid(font, c, color);
                    texture = SDL_CreateTextureFromSurface(renderer, surface);
                    SDL_QueryTexture(texture, NULL, NULL, &textRect.w, &textRect.h);
                }
            }
            
            TTF_CloseFont(font);
        }
        
        if (renderer)
        {
            SDL_DestroyRenderer(renderer);
        }
        if (window)
        {
            SDL_DestroyWindow(window);
        }
    }
    
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
    return 0;
}
