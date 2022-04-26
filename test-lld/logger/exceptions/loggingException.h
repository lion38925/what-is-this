#ifndef LOGGING_EXCEPTION.H
#define LOGGING_EXCEPTION
#include <bits/stdc++.h>
using namespace std;

class loggingException : public exception
{
private:
    /* data */
    string text;

public:
    loggingException(string s)
    {
        this->text = s;
    };
    ~loggingException() throw(){};

    const char *what() const throw() { return text.c_str(); };
};

#endif