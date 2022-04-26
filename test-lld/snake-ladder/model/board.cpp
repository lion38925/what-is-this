#include "board.h"
#include "player.h"
#include "ladder.h"
#include "snake.h"
using namespace std;

Board::Board(int numberOfSankes, int numberOfLadder, unordered_map<int, Snake *> snakeList, unordered_map<int, Ladder *> ladderList)
{
    this->numberOfSnakes = numberOfSankes;
    this->numberOfLadders = numberOfLadder;
    this->snakeList = snakeList;
    this->ladderList = ladderList;
}

Board::Board(int boardsize, int numberOfSankes, int numberOfLadder, unordered_map<int, Snake *> snakeList, unordered_map<int, Ladder *> ladderList)
{
    this->boardsize = boardsize;
    this->numberOfSnakes = numberOfSankes;
    this->numberOfLadders = numberOfLadder;
    this->snakeList = snakeList;
    this->ladderList = ladderList;
}

int Board::geteExpectedPosition(Player *player, int score)
{
    int currentPosition = player->getPlayerCurrentPosition();
    int expectedPosition = currentPosition + score;

    bool isSnakeOrLadder = true;
    int jump;

    while (isSnakeOrLadder)
    {
        if ((this->snakeList).find(expectedPosition) == (this->snakeList).end())
        {
            if ((this->ladderList).find(expectedPosition) == (this->ladderList).end())
            {
                isSnakeOrLadder = false;
            }
            else
            {
                jump = (this->ladderList[expectedPosition])->getLadderTail();
                expectedPosition = expectedPosition + jump;
                isSnakeOrLadder = true;
            }
        }

        if (isSnakeOrLadder || (this->ladderList).find(expectedPosition) == (this->ladderList).end())
        {
            if ((this->snakeList).find(expectedPosition) == (this->snakeList).end())
            {
                isSnakeOrLadder = false;
            }
            else
            {
                jump = (this->snakeList[expectedPosition])->getSnakeTail();
                expectedPosition = expectedPosition + jump;
                isSnakeOrLadder = true;
            }
        }
    }

    return expectedPosition;
}

void Board::updatePosition(Player *player, int score)
{
    int currentPosition = player->getPlayerCurrentPosition();
    int expectedPosition = this->geteExpectedPosition(player, score);

    if (expectedPosition > 100)
    {
        expectedPosition = currentPosition;
    }

    cout << player->getPlayerName() << " rolled " << score << " and moved from " << currentPosition << " to " << expectedPosition << endl;
    player->setPlayerCurrentPosition(expectedPosition);
}