#ifndef SLIDING_FIXED_WINDOW_RATE_LIMITER_H
#define SLIDING_FIXED_WINDOW_RATE_LIMITER_H
#include <bits/stdc++.h>
#include "abstractRateLimiter.h"

using namespace std;
using namespace chrono;

class slidingFixedWindowRateLimiter : public abstractRateLimiter
{
private:
    /* data */
    map<string, map<long, long>> slidingFixedWindow;

public:
    slidingFixedWindowRateLimiter(long interval, long numberOfRequests) : abstractRateLimiter(interval, numberOfRequests)
    {
    }

    bool grantAccess(string userId)
    {
        long currentTimeInSeconds = duration_cast<seconds>( // this is taken  into millseconds
                                        system_clock::now().time_since_epoch())
                                        .count();
        // to get minutes just change duration cast

        cout << currentTimeInSeconds << "\n";

        if (!this->slidingFixedWindow.count(userId))
        {
            map<long, long> tempMap;
            tempMap[currentTimeInSeconds] = 1;
            this->slidingFixedWindow[userId] = tempMap;
            return true;
        }
        else
        {
            map<long, long> userSlidingWindows = this->slidingFixedWindow[userId];
            int interval = this->getInterval();
            interval = interval / (1000);
            int totalRequest = 0;
            for (auto userToken : userSlidingWindows)
            {
                if (currentTimeInSeconds - userToken.first < interval)
                {
                    totalRequest += userToken.second;
                }
            }

            if (totalRequest <= this->getNumberOfRequests())
            {
                userSlidingWindows[currentTimeInSeconds]++;
                this->slidingFixedWindow[userId] = userSlidingWindows;
                return true;
            }

            return false;
        }

        return false;
    }
};

#endif