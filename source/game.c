#include "game.h"
#include "SDL2_ttf/SDL_ttf.h"
#include "SDL2_image/SDL_image.h"
#include "gameObject.h"
#include "constants.h"
#include "time.h"
#include "fpsutils.h"
#include "physics.h"
#include "background.h"
#include "playerShip.h"
#include "laserBeam.h"

const int LASER_COUNT = 20;
GameObject gameObjects[LASER_COUNT];

const int BOX_SIZE = 100;
Box2D boxes[BOX_SIZE];
SDL_Rect pngRect;

SDL_Window* window;
SDL_Renderer* renderer;

double deltaTime;

void getInput();
void setInput();

double totalTime = 0;

int startGame()
{
    window = NULL;
    renderer = NULL;
    done = SDL_FALSE;
    
    clock_t start, end;
    start = clock();
    double timePerFrame = 0;
    
//    for (int i = 0; i < BOX_SIZE; i++)
//    {
//        boxes[i].position.x = rand() / (RAND_MAX + 1.0) * WIDTH;
//        boxes[i].position.y = rand() / (RAND_MAX + 1.0) * HEIGHT;
//        boxes[i].size.x = boxes[i].size.y = 10 + (rand() / (RAND_MAX + 1.0)) * 90;
//        boxes[i].color.r = 255;
//        boxes[i].color.g = 255;
//        boxes[i].color.b = 255;
//    }
    
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
            
            initBg(renderer);
			
			// Init playerShip
            initPlayerShip(renderer);
            
            // Init laserbeams
            initLaserBeam(renderer);
            
            SDL_Color color = { 255, 255, 255, 255 };
            SDL_Surface* surface = TTF_RenderText_Solid(font, "testing testing", color);
            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
            SDL_Rect textRect;
            textRect.x = textRect.y = 0;
            SDL_QueryTexture(texture, NULL, NULL, &textRect.w, &textRect.h);
            
            // MAIN LOOP
            while (!done)
            {
                deltaTime = (double) (clock() - start) / CLOCKS_PER_SEC;
                totalTime += deltaTime;
                start = clock();
                timePerFrame = timePerFrame + deltaTime;
                calculateFps(deltaTime);
                
                // Background
                updateBg(renderer, deltaTime);
                
                // Boxes
                for (int i = 0; i < BOX_SIZE; i++)
                {
                    drawBox(renderer, boxes[i]);
                }
                
                // Update playerShip
                updatePlayerShip(renderer);
				
				// Draw lasers
                updateLaserBeam(renderer, deltaTime);
                
                // Text on the top left corner
                SDL_RenderCopy(renderer, texture, NULL, &textRect);
                // Set background color
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                // Draws everything
                SDL_RenderPresent(renderer);
                // Clears everything, I still don't understand how this works
                SDL_RenderClear(renderer);
                
                getInput();
                setInput();
                solvePhysics(boxes, BOX_SIZE);
                solvePhysicsGame(gameObjects, LASER_COUNT);
                
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

//void setInput()
//{
//    float deltaTime = 0.001;
//    if (goUp)
//    {
//        boxes[0].position.y -= deltaTime * SPEED;
//        playerShip.position.y -= deltaTime * SPEED;
////        gameObjects[0].rect.y -= 1;
//    }
//    if (goLeft)
//    {
//        boxes[0].position.x -= deltaTime * SPEED;
//        playerShip.position.x -= deltaTime * SPEED;
////        gameObjects[0].rect.x -= 1;
//    }
//    if (goDown)
//    {
//        boxes[0].position.y += deltaTime * SPEED;
//        playerShip.position.y += deltaTime * SPEED;
////        gameObjects[0].rect.y += 1;
//    }
//    if (goRight)
//    {
//        boxes[0].position.x += deltaTime * SPEED;
//        playerShip.position.x += deltaTime * SPEED;
////        gameObjects[0].rect.x += 1;
//    }
//}

//void getInput()
//{
//    SDL_Event event;
//    while (SDL_PollEvent(&event))
//    {
//        switch (event.type)
//        {
//            case SDL_KEYDOWN:
//                if (event.key.keysym.sym == SDLK_w)
//                {
//                    goUp = true;
//                }
//                if (event.key.keysym.sym == SDLK_a)
//                {
//                    goLeft = true;
//                }
//                if (event.key.keysym.sym == SDLK_s)
//                {
//                    goDown = true;
//                }
//                if (event.key.keysym.sym == SDLK_d)
//                {
//                    goRight = true;
//                }
//                break;
//            case SDL_KEYUP:
//                if (event.key.keysym.sym == SDLK_w)
//                {
//                    goUp = false;
//                }
//                if (event.key.keysym.sym == SDLK_a)
//                {
//                    goLeft = false;
//                }
//                if (event.key.keysym.sym == SDLK_s)
//                {
//                    goDown = false;
//                }
//                if (event.key.keysym.sym == SDLK_d)
//                {
//                    goRight = false;
//                }
//                break;
//            case SDL_QUIT:
//                done = SDL_TRUE;
//                break;
//        }
//    }
//}

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
