#include "userRepository.h"

void userRepository::addUserIn(user user_)
{
    this->userMap[user_.getId()] = user_;
}
user userRepository::getUserById(string id)
{

    if (this->userMap.count(id))
    {
        return this->userMap[id];
    }
}

bool userRepository::userExist(string id)
{
    if (this->userMap.count(id))
    {
        return true;
    }

    return false;
}