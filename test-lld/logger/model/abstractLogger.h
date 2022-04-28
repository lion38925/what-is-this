#ifndef ABSTRACT_LOGGGER_H
#define ABSTRACT_LOGGGER_H
#include <bits/stdc++.h>
#include "../enums/loggerType.h"

using namespace std;

class abstractLogger
{
private:
    /* data */
    loggerType loggerTypo;
    abstractLogger *nextLogger;

public:
    void setNextLogger(abstractLogger *logger)
    {
        this->nextLogger = logger;
    }
    void logMessage(loggerType logType, string message)
    {

        if (this->loggerTypo == logType)
        {
            this->displayMessage(message);
        }

        if (this->nextLogger != NULL)
        {
            this->nextLogger->logMessage(logType, message);
        }
    }

    virtual void displayMessage(string message) = 0;

    loggerType getLoggerTypo(){ return loggerTypo; }
    void setLoggerTypo(loggerType loggerTypo_) { loggerTypo = loggerTypo_; }
};

#endif