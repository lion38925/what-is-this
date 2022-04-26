#include "player.h"
using namespace std;

Player::Player(int id, string name)
{
    this->id = id;
    this->name = name;
    this->currentPosition = 0;
}

int Player::getPlayerID()
{
    return this->id;
}

string Player::getPlayerName()
{
    return this->name;
}

int Player::getPlayerCurrentPosition()
{
    return this->currentPosition;
}

void Player::setPlayerCurrentPosition(int nextPosition)
{
    this->currentPosition = nextPosition;
}

bool Player::checkWin()
{
    if (this->currentPosition == 100)
        return true;
    else
        return false;
}