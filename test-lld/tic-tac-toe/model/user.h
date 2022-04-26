#ifndef USERR_H
#define USERR_H
#include <bits/stdc++.h>
using namespace std;

class user
{
private:
    string name;
    string rank;
    string id;
    /* data */
    
public:
    string getId();
    void setId(string id_);

    string getRank();
    void setRank(string rank_);

    string getName();
    void setName(string name_);
};


#endif