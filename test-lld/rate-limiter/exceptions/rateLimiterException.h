#ifndef RATE_LIMITER_EXCEPTION_H
#define RATE_LIMITER_EXCEPTION_H
#include <bits/stdc++.h>
using namespace std;

class rateLimiterException : public exception
{
private:
    /* data */
    string message;

public:
    rateLimiterException(string text) : message(text){};
    ~rateLimiterException() throw(){};

    const char* what() const throw() { return message.c_str(); }
};

#endif