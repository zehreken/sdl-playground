#include "scoreController.h"

static int score;
static int highScore;

void initScoreController()
{
    score = 0;
}

void scoreController_reset()
{
    score = 0;
}

void addScore(int value)
{
    score += value;
    if (score > highScore)
    {
        highScore = score;
    }
}

int getScore()
{
    return score;
}

int getHighScore()
{
    return highScore;
}
