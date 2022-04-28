#ifndef ABSTRACT_RATE_LIMITER_H
#define ABSTRACT_RATE_LIMITER_H
#include <bits/stdc++.h>
using namespace std;

class abstractRateLimiter
{
private:
    /* data */
    long interval;
    long numberOfRequests;

public:
    abstractRateLimiter(long interval_, long nofR)
    {
        this->interval = interval_;
        this->numberOfRequests = nofR;
    }

    virtual bool grantAccess(string userId) = 0;

    long getInterval() const { return interval; }

    long getNumberOfRequests() const { return numberOfRequests; }

};

#endif