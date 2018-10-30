#include <iostream>
#include <SDL2/SDL.h>

using namespace std;
int main(int, char**)
{
    cout << "Main starts here" << endl;
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        cout << "SDL_Init Error: " << SDL_GetError() << endl;
        return 1;
    }
    
    SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    if (win == nullptr)
    {
        cout << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
        SDL_Quit();
        return 1;
    }
    
    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == nullptr)
    {
        SDL_DestroyWindow(win);
        cout << "SDL_CreateRenderer Error: " << SDL_GetError() << endl;
        SDL_Quit();
        return 1;
    }
    
    SDL_bool done = SDL_FALSE;
    
    while (!done)
    {
        SDL_Event event;
        SDL_SetRenderDrawColor(ren, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(ren);
        
        SDL_SetRenderDrawColor(ren, 255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawLine(ren, 320, 200, 300, 240);
        SDL_RenderDrawLine(ren, 300, 240, 340, 240);
        SDL_RenderDrawLine(ren, 340, 240, 320, 200);
        SDL_RenderPresent(ren);
        
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                done = SDL_TRUE;
            }
        }
    }
    //SDL_Delay(3000);
    SDL_Quit();
    return 0;
}
