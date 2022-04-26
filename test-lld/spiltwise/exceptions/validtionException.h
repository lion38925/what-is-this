#ifndef VALIDATION_EXCEPTION_h
#define VALIDATION_EXCEPTION_h
#include <bits/stdc++.h>
using namespace std;

class validationException : public exception
{
public:
    std::string s;
    validationException(string ss) : s(ss) {}
    ~validationException() throw() {} // Updated
    const char *what() const throw() { return s.c_str(); }
};

#endif