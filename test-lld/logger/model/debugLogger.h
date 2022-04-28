#ifndef DEBUG_LOGGER_H
#define DEBUG_LOGGER_H
#include <bits/stdc++.h>
#include "abstractLogger.h"

using namespace std;

class debugLogger : public abstractLogger
{
private:
    /* data */
public:
    debugLogger(){
        this->setLoggerTypo(loggerType::DEBUG);
    }
    void displayMessage(string message)
    {
        cout << "debug Logger it is"<<"\n"<<message<<"\n";
    }
};

#endif