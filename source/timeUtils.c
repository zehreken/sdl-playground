#include "timeUtils.h"
#include "SDL2/SDL.h"

static unsigned int now, previousTime;
static unsigned int deltaTime;

void initTimeUtils()
{
    now = previousTime = 0;
}

void updateTimeUtils()
{
    now = SDL_GetTicks();
    deltaTime = now - previousTime;
    previousTime = now;
}

unsigned int getDeltaTime()
{
    return deltaTime;
}

float getDeltaTimeInSeconds()
{
    return (float)deltaTime / 1000;
}
