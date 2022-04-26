#ifndef PLAYER
#define PLAYER
#include <bits/stdc++.h>
using namespace std;

class Player
{
private:
    int id;
    string name;
    int currentPosition;

public:
    Player(int id, string name);

    int getPlayerID();

    string getPlayerName();
    int getPlayerCurrentPosition();

    void setPlayerCurrentPosition(int nextPosition);

    bool checkWin();
};
#endif