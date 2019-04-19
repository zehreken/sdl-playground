#include "fpsUtils.h"
#include "time.h"
#include "stdio.h"
#define CACHE_SIZE 10

int counter;
float acc;
int fpsCache[CACHE_SIZE];

void initFpsUtils()
{
    counter = 0;
    acc = 0;
}

int ind = 0;
void addToCache(int counter)
{
    fpsCache[ind] = counter;
    ind++;
    if (ind == CACHE_SIZE)
        ind = 0;
}

float getAverageFps()
{
    float sum = 0;
    for (int i = 0; i < CACHE_SIZE; i++)
    {
        sum += fpsCache[i];
    }

    return sum / CACHE_SIZE;
}

float calculateFps(float deltaTime)
{
    acc = acc + deltaTime;
    if (acc > 1)
    {
        printf("[fpsUtils.c] fps: %d\n", counter);
        addToCache(counter);
        counter = 0;
        acc = acc - 1;
    }
    else
    {
        counter++;
    }
    return 0;
}


