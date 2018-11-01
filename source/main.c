#include "SDL2/SDL.h"
#include "SDL2_ttf/SDL_ttf.h"
#include "time.h"
#include "stdbool.h"
#include "primitives.h"
#include "constants.h"
#include "collision.h"

//Box2D a, b;

const int BOX_SIZE = 10;
Box2D boxes[BOX_SIZE];

int main(int argc, char* argv[])
{
    srand(time(NULL));
    
    bool goUp = false;
    bool goLeft = false;
    bool goDown = false;
    bool goRight = false;
    
//    a->position.x = a->position.y = b->position.x = b->position.y = 300;
//    a->size.x = a->size.y = b->size.x = b->size.y = 100;
//    a->color.r = 255;
//    b->color.b = 255;
//    boxes[0] = *a;
//    boxes[1] = *b;
    for (int i = 0; i < BOX_SIZE; i++)
    {
        boxes[i].position.x = 100 * i;
        boxes[i].position.y = 100 * i;
        boxes[i].size.x = boxes[i].size.y = 20;
        boxes[i].color.r = 255;
        boxes[i].color.g = 255;
        boxes[i].color.b = 255;
    }
    
    if (SDL_Init(SDL_INIT_VIDEO) == 0)
    {
        SDL_Window* window = NULL;
        SDL_Renderer* renderer = NULL;
        
        if (SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer) == 0)
        {
            
            if (TTF_Init() == -1)
                printf("error");
            TTF_Font* font = TTF_OpenFont("fonts/emulogic.ttf", 8);
            if (!font)
                printf("font loading error");
            SDL_Color color = { 255, 255, 255, 255 };
            SDL_Surface* surface = TTF_RenderText_Solid(font, "testing testing testing testing testing", color);
            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
            SDL_Rect textRect;
            textRect.x = textRect.y = 0;
            SDL_QueryTexture(texture, NULL, NULL, &textRect.w, &textRect.h);
            
            SDL_bool done = SDL_FALSE;
            int i = 0;
            
            while (!done)
            {
                SDL_Event event;
                
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                SDL_RenderClear(renderer);
                
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
                SDL_RenderDrawLine(renderer, 320, 200, 300, 240);
                SDL_RenderDrawLine(renderer, 300, 240, 340, 240);
                SDL_RenderDrawLine(renderer, 340, 240, 320, 200);
                
                drawTriangle(renderer, i++);
                if (i > WIDTH / 2) i = 0;
                
//                drawBox(renderer, a);
//                drawBox(renderer, b);
                for (int i = 0; i < BOX_SIZE; i++)
                {
                    drawBox(renderer, boxes[i]);
                }
                
                drawDots(renderer);
                
                SDL_RenderCopy(renderer, texture, NULL, &textRect);
                SDL_RenderPresent(renderer);
                
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
                        default:
                            break;
                    }
                }
                
                if (goUp)
                    boxes[0].position.y -= SPEED;
                if (goLeft)
                    boxes[0].position.x -= SPEED;
                if (goDown)
                    boxes[0].position.y += SPEED;
                if (goRight)
                    boxes[0].position.x += SPEED;
                
                solvePhysics(boxes, BOX_SIZE);
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
    SDL_Quit();
    return 0;
}