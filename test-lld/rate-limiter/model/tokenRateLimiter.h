#ifndef TOKEN_RATE_LIMITER_H
#define TOKEN_RATE_LIMITER_H
#include <bits/stdc++.h>
#include "abstractRateLimiter.h"

using namespace std;
using namespace std::chrono;

class tokenRateLimiter : public abstractRateLimiter
{
private:
    /* data */
    map<string, pair<long, long>> userTokenBucket;

public:
    tokenRateLimiter(long interval, long numberOfRequests) : abstractRateLimiter(interval, numberOfRequests)
    {
    }

    bool grantAccess(string userId)
    {
        long currentTime = duration_cast<milliseconds>(             // this is taken  into millseconds
            system_clock::now().time_since_epoch()).count();

        if (!this->userTokenBucket.count(userId))
        {
            this->userTokenBucket[userId] = {this->getNumberOfRequests() - 1, currentTime};
            return true;
        }
        else
        {
            auto userToken = this->userTokenBucket[userId];
            if (currentTime - userToken.second <= this->getInterval())
            {
                if (userToken.first <= 0)
                {
                    return false;
                }
            }
            else
            {
                userToken.first = this->getNumberOfRequests();
            }
            userToken.first = userToken.first - 1;
            userToken.second = currentTime;
            this->userTokenBucket[userId] = userToken;
        }

        return true;
    }
};

#endif