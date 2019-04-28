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
#include "enemyController.h"
#include "basicUI.h"

SDL_Window* window;
SDL_Renderer* renderer;

static void getInput();
void start();
void play(float);
void gameOver();

int startGame()
{
    window = NULL;
    renderer = NULL;
    done = SDL_FALSE;
    
    initTimeUtils();
    
    if (SDL_Init(SDL_INIT_VIDEO) == 0)
    {
        if (SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer) == 0)
        {
            if (TTF_Init() == -1)
                printf("TTF_Init error");
            int IMG_Flag = 0;
            if (IMG_Init(IMG_Flag) == -1)
                printf("IMG_Init error");
            
            // Init basic UI
            initBasicUI(renderer);
            
            // Init background
            initBg(renderer);
			
			// Init player ship
            initPlayerShip(renderer);
            
            // Init laser beams
            initLaserBeam(renderer);
            
            // Init enemy ships
            initEnemyShips(renderer);
            
            // Init enemy controller
            initEnemyController();
            
            // MAIN LOOP
            while (!done)
            {
                // Handle input
                getInput();
                
                updateTimeUtils();
                float deltaTime = getDeltaTimeInSeconds();
//                calculateFps(deltaTime);
                
                // Background
                updateBg(renderer, deltaTime);
                
                switch (gameState)
                {
                    case START:
                        start();
                        break;
                    case PLAY:
                        play(deltaTime);
                        break;
                    case GAME_OVER:
                        gameOver();
                        break;
                }
                
                
                
                // Set background color
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                
                // Draws everything
                SDL_RenderPresent(renderer);
                
                // Clears everything, I still don't understand how this works
                SDL_RenderClear(renderer);
                
//                solvePhysics(boxes, BOX_SIZE);
//                solvePhysicsGame(gameObjects, LASER_COUNT);
                solvePhysicsGame(getLaserBeams(), 20, getEnemyShips(), 20);
                solvePhysicsGame(getEnemyLaserBeams(), 20, getPlayerShip(), 1);
//                solvePhysicsGame(getEnemyShips(), 20, getPlayerShip(), 1);
                
                SDL_Delay(10);
                
//                if (timePerFrame < 0.0166666)
//                {
//                    continue;
//                }
//                else
//                {
//                    float f = getAverageFps();
//                    char c[50];
//                    char b[11] = " totalTime";
//                    sprintf(c, "%g", totalTime);
//                    strcat(c, b);
//                    timePerFrame = 0;
//                    surface = TTF_RenderText_Solid(font, c, color);
//                    texture = SDL_CreateTextureFromSurface(renderer, surface);
//                    SDL_QueryTexture(texture, NULL, NULL, &textRect.w, &textRect.h);
//                }
            }
            
            quitBasicUI();
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

static void getInput()
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
                if (event.key.keysym.sym == SDLK_SPACE)
                {
                    fire();
                }
                if (event.key.keysym.sym == SDLK_q)
                {
                    switch (gameState)
                    {
                        case START:
                            gameState = PLAY;
                            break;
                        case PLAY:
                            gameState = GAME_OVER;
                            break;
                        case GAME_OVER:
                            gameState = START;
                            break;
                    }
                }
                if (event.key.keysym.sym == SDLK_o)
                {
                    if (gameState == START || gameState == GAME_OVER)
                    {
                        // Reset game
                        gameState = PLAY;
                    }
                }
                break;
            case SDL_QUIT:
                done = SDL_TRUE;
                break;
        }
    }
}

void endGame()
{
    gameState = GAME_OVER;
}

void start()
{
    drawStartUI(renderer);
}

void play(float deltaTime)
{
    // Update enemy ships
    updateEnemyShips(renderer, deltaTime);
    
    // Update laser beams
    updateLaserBeam(renderer, deltaTime);
    
    // Update player ship
    updatePlayerShip(renderer, deltaTime);
    
    // Update enemy controller
    updateEnemyController(deltaTime);
    
    // In game UI
    drawPlayUI(renderer);
}

void gameOver()
{
    drawEndGameUI(renderer);
}
