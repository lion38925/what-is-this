#ifndef LOGGER_SERVICE_H
#define LOGGER_SERVICE_H
#include <bits/stdc++.h>
#include "loggerManager.h"

using namespace std;

class loggerService
{

private:
    static loggerService *instance; // wasted around 1 hour here was doing loggerService * instance
    static loggerManager *logManagerInst;
    static abstractLogger *loggerChain;
    loggerService() = default; // need to remember this as well

    /* there are 3 ways to create a pointer
    loggerService* instance;  // this one is preffered always use this one
    loggerService * instance;
    loggerService *instance;


    */

public:
    static loggerService *getLatestInstance();

    void info(string message)
    {
        this->loggit(loggerType::CONSOLE, message);
    }
    void debug(string message)
    {
        this->loggit(loggerType::DEBUG, message);
    }
    void error(string message)
    {
        this->loggit(loggerType::ERROR, message);
    }

    void loggit(loggerType logType, string message)
    {
        loggerChain->logMessage(logType, message);
    }
};

loggerService *loggerService::instance = nullptr;
loggerManager *loggerService::logManagerInst;
abstractLogger *loggerService::loggerChain;
loggerService *loggerService::getLatestInstance()
{
    if (instance == NULL)
    {
        instance = new loggerService();
        logManagerInst = new loggerManager();
        loggerChain = logManagerInst->dochaining();
    }
    return instance;
}
#endif
