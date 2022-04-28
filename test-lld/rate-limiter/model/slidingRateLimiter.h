#ifndef SLIDING_RATE_LIMITER_H
#define SLIDING_RATE_LIMITER_H
#include <bits/stdc++.h>
#include "abstractRateLimiter.h"

using namespace std;

class slidingRateLimiter : public abstractRateLimiter
{
private:
    /* data */
    map<string, pair<long, long>> userTokenBucket;

public:
    slidingRateLimiter(long interval, long numberOfRequests) : abstractRateLimiter(interval, numberOfRequests)
    {
    }

    bool grantAccess(string userId)
    {

        return false;
    }
};

#endif