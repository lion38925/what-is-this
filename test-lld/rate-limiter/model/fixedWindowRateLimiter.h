#ifndef FIXED_WINDOW_RATE_LIMITER_H
#define FIXED_WINDOW_RATE_LIMITER_H
#include <bits/stdc++.h>
#include "abstractRateLimiter.h"

using namespace std;
using namespace chrono;

class fixedWindowRateLimiter : public abstractRateLimiter
{
private:
    /* data */
    map<string, pair<long, long>> userFixedBucket;

public:
    fixedWindowRateLimiter(long interval, long numberOfRequests) : abstractRateLimiter(interval, numberOfRequests)
    {
    }

    bool grantAccess(string userId)
    {
        long currentTimeInMinutes = duration_cast<minutes>( // this is taken  into millseconds
                                        system_clock::now().time_since_epoch())
                                        .count();
        // to get minutes just change duration cast

        if (!this->userFixedBucket.count(userId))
        {
            this->userFixedBucket[userId] = {1, currentTimeInMinutes};
            return true;
        }
        else
        {
            auto userToken = this->userFixedBucket[userId];
            int interval = this->getInterval();
            interval = interval / (60000);
            if (currentTimeInMinutes - userToken.second < interval)
            {
                userToken.first++;
            }
            else
            {
                userToken.first = 1;
                userToken.second = currentTimeInMinutes;
            }
            this->userFixedBucket[userId] = userToken;
            return userToken.first <= this->getNumberOfRequests();
        }

        return false;
    }
};

#endif