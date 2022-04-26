#include <bits/stdc++.h>
using namespace std;
#include "snake.h"

Snake::Snake(int head, int tail)
{
    this->head = head;
    this->tail = tail;
}

int Snake::getSnakeHead()
{
    return this->head;
}

int Snake::getSnakeTail()
{
    return this->tail;
}