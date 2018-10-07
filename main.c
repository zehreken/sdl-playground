#include "SDL2/SDL.h"

void move(SDL_Renderer* renderer, int i)
{
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(renderer, 320 + i, 200, 300 + i, 240);
    SDL_RenderDrawLine(renderer, 300 + i , 240, 340 + i, 240);
    SDL_RenderDrawLine(renderer, 340 + i, 240, 320 + i, 200);
}

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) == 0)
    {
        SDL_Window* window = NULL;
        SDL_Renderer* renderer = NULL;
        
        if (SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer) == 0)
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
                
                move(renderer, i++);
                if (i > 640) i = 0;
                
                SDL_RenderPresent(renderer);
                
                while (SDL_PollEvent(&event))
                {
                    if (event.type == SDL_QUIT)
                    {
                        done = SDL_TRUE;
                    }
                }
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
