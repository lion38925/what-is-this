#include <iostream>
#include "service/gameService.h"
#include <bits/stdc++.h>

using namespace std;

int main(){

    cout << "Enter players name" <<endl;
    string p1, p2;
    cout << "Enter first player name :";
    cin >> p1;
    cout << "Enter second player name :";
    cin >> p2;

    gameService game(p1, p2);
    game.play();
	return 0;
}