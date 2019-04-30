#include "audioController.h"
#include "SDL2_mixer/SDL_mixer.h"

static Mix_Chunk *start = NULL;
static Mix_Chunk *laser = NULL;
static Mix_Chunk *lose = NULL;

void audioController_init()
{
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
    }
    
    start = Mix_LoadWAV("assets/start.wav");
    if (start == NULL)
    {
        printf("Failed to load start sound effect! SDL_mixer Error: %s\n", Mix_GetError());
    }
    
    laser = Mix_LoadWAV("assets/laser.wav");
    if (laser == NULL)
    {
        printf("Failed to load laser sound effect! SDL_mixer Error: %s\n", Mix_GetError());
    }
    
    lose = Mix_LoadWAV("assets/lose.wav");
    if (lose == NULL)
    {
        printf("Failed to load lose sound effect! SDL_mixer Error: %s\n", Mix_GetError());
    }
}

void audioController_play(int id)
{
    switch(id)
    {
        case 0:
            Mix_PlayChannel(-1, start, 0);
            break;
        case 1:
            Mix_PlayChannel(-1, laser, 0);
            break;
        case 2:
            Mix_PlayChannel(-1, lose, 0);
            break;
    }
}

void audioController_close()
{
    Mix_FreeChunk(start);
    Mix_FreeChunk(laser);
    Mix_FreeChunk(lose);
    
    Mix_Quit();
}
