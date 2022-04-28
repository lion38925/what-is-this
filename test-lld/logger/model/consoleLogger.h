#ifndef CONSOLE_LOGGER_H
#define CONSOLE_LOGGER_H
#include <bits/stdc++.h>
#include "abstractLogger.h"

using namespace std;

class consoleLogger : public abstractLogger
{
private:
    /* data */
public:

    consoleLogger(){
        this->setLoggerTypo(loggerType::CONSOLE);
    }
    void displayMessage(string message)
    {
        cout << "console Logger it is"<<"\n"<<message<<"\n";
    }
};

#endif