#include "SDL2/SDL.h"
#include "time.h"
#include "stdbool.h"
#include "primitives.h"

const int WIDTH = 640;
const int HEIGHT = 480;
const float SPEED = 1;

Box2D a, b;

void drawTriangle(SDL_Renderer* renderer, int i)
{
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(renderer, 320 + i, 200, 300 + i, 240);
    SDL_RenderDrawLine(renderer, 300 + i , 240, 340 + i, 240);
    SDL_RenderDrawLine(renderer, 340 + i, 240, 320 + i, 200);
}

void drawBox(SDL_Renderer* renderer, Box2D box2D)
{
    IntVector2 pos = box2D.position;
    IntVector2 size = box2D.size;
    ColorRGB color = box2D.color;
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(renderer, pos.x - size.x / 2, pos.y - size.y / 2, pos.x - size.x / 2, pos.y + size.y / 2); // left
    SDL_RenderDrawLine(renderer, pos.x - size.x / 2, pos.y - size.y / 2, pos.x + size.x / 2, pos.y - size.y / 2); // top
    SDL_RenderDrawLine(renderer, pos.x + size.x / 2, pos.y - size.y / 2, pos.x + size.x / 2, pos.y + size.y / 2); // right
    SDL_RenderDrawLine(renderer, pos.x - size.x / 2, pos.y + size.y / 2, pos.x + size.x / 2, pos.y + size.y / 2); // bottom
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

void solveCollision()
{
    if (a.position.x < b.position.x + b.size.x &&
        a.position.x + a.size.x > b.position.x &&
        a.position.y < b.position.y + b.size.y &&
        a.position.y + a.size.y > b.position.y)
    {
        a.color.r = b.color.r = 255;
        a.color.g = a.color.b = b.color.g = b.color.b = 0;
    }
    else
    {
        a.color.r = a.color.b = b.color.r = b.color.b = 0;
        a.color.g = b.color.g = 255;
    }
}

int main(int argc, char* argv[])
{
    srand(time(NULL));
    
    bool goUp = false;
    bool goLeft = false;
    bool goDown = false;
    bool goRight = false;
    
    a.position.x = a.position.y = b.position.x = b.position.y = 300;
    a.size.x = a.size.y = b.size.x = b.size.y = 100;
    a.color.r = 255;
    b.color.b = 255;
    
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
                
                drawBox(renderer, a);
                drawBox(renderer, b);
                
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
                    a.position.y -= SPEED;
                if (goLeft)
                    a.position.x -= SPEED;
                if (goDown)
                    a.position.y += SPEED;
                if (goRight)
                    a.position.x += SPEED;
                
                solveCollision();
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
