#include "fpsutils.h"
#include "time.h"
#include "stdio.h"

int counter;
double acc;

void initFpsutils()
{
    counter = 0;
    acc = 0;
}

double calculateFps(double deltaTime)
{
    acc = acc + deltaTime;
    if (acc > 1)
    {
        printf("fps: %d\n", counter);
        counter = 0;
        acc = acc - 1;
    }
    else
    {
        counter++;
    }
    return 0;
}
