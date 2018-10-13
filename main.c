#include "SDL2/SDL.h"
#include "time.h"
#include "stdbool.h"

const int WIDTH = 640;
const int HEIGHT = 480;
const float SPEED = 1;

struct Vector2
{
    float x;
    float y;
};
struct Vector2 pos;

void drawTriangle(SDL_Renderer* renderer, int i)
{
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(renderer, 320 + i, 200, 300 + i, 240);
    SDL_RenderDrawLine(renderer, 300 + i , 240, 340 + i, 240);
    SDL_RenderDrawLine(renderer, 340 + i, 240, 320 + i, 200);
}

void drawSquare(SDL_Renderer* renderer, int size, struct Vector2 pos)
{
    SDL_SetRenderDrawColor(renderer, 255, 0, 55, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(renderer, pos.x - size / 2, pos.y - size / 2, pos.x - size / 2, pos.y + size / 2); // left
    SDL_RenderDrawLine(renderer, pos.x - size / 2, pos.y - size / 2, pos.x + size / 2, pos.y - size / 2); // top
    SDL_RenderDrawLine(renderer, pos.x + size / 2, pos.y - size / 2, pos.x + size / 2, pos.y + size / 2); // right
    SDL_RenderDrawLine(renderer, pos.x - size / 2, pos.y + size / 2, pos.x + size / 2, pos.y + size / 2); // bottom
}

void drawDots(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
    for (int i = 0; i < WIDTH; i++)
    {
        int rnd = (rand() / (RAND_MAX + 1.0)) * HEIGHT;
        SDL_RenderDrawPoint(renderer, i, rnd);
    }
}

int main(int argc, char* argv[])
{
    pos.x = 0;
    pos.y = 0;
    srand(time(NULL));
    
    bool goUp = false;
    bool goLeft = false;
    bool goDown = false;
    bool goRight = false;
    if (SDL_Init(SDL_INIT_VIDEO) == 0)
    {
        SDL_Window* window = NULL;
        SDL_Renderer* renderer = NULL;
        
        if (SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer) == 0)
        {
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
                
//                for (int i = 0; i < 100; i++)
//                {
//                    struct Vector2 pos;
//                    pos.x = (rand() / (RAND_MAX + 1.0)) * WIDTH;
//                    pos.y = (rand() / (RAND_MAX + 1.0)) * HEIGHT;
//                    drawSquare(renderer, 100, pos);
//                }
                
                drawSquare(renderer, 100, pos);
                
                drawDots(renderer);
                
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
                    pos.y -= SPEED;
                if (goLeft)
                    pos.x -= SPEED;
                if (goDown)
                    pos.y += SPEED;
                if (goRight)
                    pos.x += SPEED;
            }
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
    SDL_Quit();
    return 0;
}
