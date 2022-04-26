#ifndef USER_REPOSITORY_H
#define USER_REPOSITORY_H

#include <bits/stdc++.h>
#include "../model/user.h"
using namespace std;


class userRepository
{
private:
    /* data */
    map<string, user> userMap;


public:
   void addUserIn(user user_);
   user getUserById(string id);
   bool userExist(string id);


};

#endif