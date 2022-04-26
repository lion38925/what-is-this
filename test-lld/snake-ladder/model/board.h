#ifndef BOARD
#define BOARD
#include <bits/stdc++.h>
#include "snake.h"
#include "ladder.h"
#include "player.h"
using namespace std;

class Board
{
private:
    int boardsize;
    int numberOfSnakes;
    int numberOfLadders;
    unordered_map<int, Snake *> snakeList;
    unordered_map<int, Ladder *> ladderList;

public:
    Board(int numberOfSankes, int numberOfLadder, unordered_map<int, Snake *> snakeList, unordered_map<int, Ladder *> ladderList);

    Board(int boardsize, int numberOfSankes, int numberOfLadder, unordered_map<int, Snake *> snakeList, unordered_map<int, Ladder *> ladderList);

    int geteExpectedPosition(Player *player, int score);

    void updatePosition(Player *player, int score);
};

#endif