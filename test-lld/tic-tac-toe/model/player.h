#include <bits/stdc++.h>
#include "user.h"
using namespace std;

class Player{
public:
	user userDetails;
    string symbol;
	bool isWin;
	vector<pair<int, int>> movesList;
public:
    Player();
	Player(int id);
    void move(int i, int j);

    user getUserDetails();
    void setUserDetails(user userDetails_);

    string getSymbol();
    void setSymbol(string symbol_);

};