#ifndef LOGGER_MANAGER_SERVICE_H
#define LOGGER_MANAGER_SERVICE_H
#include <bits/stdc++.h>
#include "../model/abstractLogger.h"
#include "../model/consoleLogger.h"
#include "../model/debugLogger.h"
#include "../model/errorLogger.h"
using namespace std;

class loggerManager {

private:

public:

    abstractLogger * dochaining(){
        abstractLogger * cl = new consoleLogger();
        abstractLogger * dl = new debugLogger();
        abstractLogger * el = new errorLogger();
        cl->setNextLogger(dl);
        dl->setNextLogger(el);
        el->setNextLogger(NULL);

        return cl;
    }

};

#endif