#include "fpsutils.h"
#include "time.h"
#include "stdio.h"

clock_t start, end;
int counter;

void initFpsutils()
{
    start = end = clock();
    counter = 0;
}

double calculateFps(double deltaTime)
{
    double diff = (double) (clock() - start) / CLOCKS_PER_SEC;
    if (diff > 1)
    {
        printf("fps: %d\n", counter);
        counter = 0;
        start = clock();
    }
    else
    {
        counter++;
    }
    return 0;
}
