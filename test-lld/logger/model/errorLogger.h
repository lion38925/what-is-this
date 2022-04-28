#ifndef ERROR_LOGGER_H
#define ERROR_LOGGER_H
#include <bits/stdc++.h>
#include "abstractLogger.h"

using namespace std;

class errorLogger : public abstractLogger
{
private:
    /* data */
public:
    errorLogger(){
        this->setLoggerTypo(loggerType::ERROR);
    }
    void displayMessage(string message)
    {
        cout << "error Logger it is"<<"\n"<<message<<"\n";
    }
};

#endif