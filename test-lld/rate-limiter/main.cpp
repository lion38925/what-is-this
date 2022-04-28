#include <bits/stdc++.h>
#include "service/rateLimiterService.h"
#include "model/tokenRateLimiter.h"
#include "model/fixedWindowRateLimiter.h"
#include "model/slidingFixedWindowRateLimiter.h"
using namespace std;

int main()
{
    abstractRateLimiter *rateLimiter = new tokenRateLimiter(60000, 5);
    abstractRateLimiter *fixedRateLimiter = new fixedWindowRateLimiter(60000, 5);
    abstractRateLimiter *slidingfixedRateLimiter = new slidingFixedWindowRateLimiter(60000, 5);
    int start = 0;
    while (start)
    {
        rateLimiterService rateLimiterService(rateLimiter);
        string userId;
        cout << "enter the user id for which you want to access";
        cin >> userId;
        bool accessAllowed = rateLimiterService.accessContent(userId);

        if (accessAllowed)
        {
            cout << "yay access if granted go ahead"
                 << "\n";
        }
        else
        {
            cout << "access denied"
                 << "\n";
        }
        cout << "do you want to continue"
             << "\n";
        cin >> start;
    }

    start = 0;
    while (start)
    {
        rateLimiterService rateLimiterServiceFixed(fixedRateLimiter);
        string userId;
        cout << "enter the user id for which you want to access";
        cin >> userId;
        bool accessAllowed = rateLimiterServiceFixed.accessContent(userId);

        if (accessAllowed)
        {
            cout << "yay access if granted go ahead"
                 << "\n";
        }
        else
        {
            cout << "access denied"
                 << "\n";
        }

        // cout << "do you want to continue"
        //      << "\n";
        // cin >> start;
    }

    
    start = 1;
    while (start)
    {
        rateLimiterService rateLimiterServiceFixed(slidingfixedRateLimiter);
        string userId;
        cout << "enter the user id for which you want to access sliding fixed rate limiter";
        cin >> userId;
        bool accessAllowed = rateLimiterServiceFixed.accessContent(userId);

        if (accessAllowed)
        {
            cout << "yay access if granted go ahead"
                 << "\n";
        }
        else
        {
            cout << "access denied"
                 << "\n";
        }

        // cout << "do you want to continue"
        //      << "\n";
        // cin >> start;
    }

    return 0;
}