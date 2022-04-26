#ifndef LADDER
#define LADDER
#include <bits/stdc++.h>
using namespace std;

class Ladder
{
    private:
        int head;
        int tail;

    public:
        Ladder(int head, int tail);
        int getLadderHead();
        int getLadderTail();

};

#endif