#ifndef DICE
#define DICE
#include <bits/stdc++.h>
using namespace std;

class Dice
{
private:
    int numberOfDice;

public:
    Dice();

    Dice(int numberOfDice);

    int getScore();
};

#endif