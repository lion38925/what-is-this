#include <bits/stdc++.h>
#include <iostream>
#include "../model/board.h"
class gameService{
	Player p1;
	Player p2;
    int moves;
    bool won = false;
    Board board;

public:
    gameService(std::string &p1_name, std::string &p2_name);
    void play();
    void generateReport();
};
