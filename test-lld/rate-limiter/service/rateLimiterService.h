#ifndef RATE_LIMITER_SERVICE_H
#define RATE_LIMITER_SERVICE_H
#include <bits/stdc++.h>
#include "../model/abstractRateLimiter.h"

using namespace std;

class rateLimiterService
{

private:
    abstractRateLimiter *rateLimiterStrategy;

public:
    rateLimiterService(abstractRateLimiter *strategy)
    {
        this->rateLimiterStrategy = strategy;
    }

    bool accessContent(string userId)
    {
        return this->rateLimiterStrategy->grantAccess(userId);
    }
};

#endif
