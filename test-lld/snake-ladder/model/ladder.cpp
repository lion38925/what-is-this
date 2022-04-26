#include "ladder.h"

Ladder::Ladder(int head, int tail)
{
    this->head = head;
    this->tail = tail;
}

int Ladder::getLadderHead()
{
    return this->head;
}

int Ladder::getLadderTail()
{
    return this->tail;
}