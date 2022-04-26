#include "dice.h"
using namespace std;

Dice::Dice()
{
    this->numberOfDice = 1;
}

Dice::Dice(int numberOfDice)
{
    this->numberOfDice = numberOfDice;
}

int Dice::getScore()
{
    int totalScore = 0, presentScore;

    for (int i = 0; i < this->numberOfDice; i++)
    {
        presentScore = 1 + (rand() % 6);
        totalScore += presentScore;
    }

    return totalScore;
}
