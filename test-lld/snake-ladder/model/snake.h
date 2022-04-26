#ifndef SNAKE_H
#define SNAKE_H
#include <bits/stdc++.h>
using namespace std;

class Snake
{
    private:
        int head;
        int tail;

    public:
        Snake(int head, int tail);
        int getSnakeHead();
        int getSnakeTail();

};

#endif
