#include <bits/stdc++.h>
#include "service/logger.h"
using namespace std;

int main()
{
    loggerService* loggingUnit = loggerService::getLatestInstance();
    loggingUnit->info("this is for info logger");
    loggingUnit->debug("this is for debug logger");
    loggingUnit->error("this is for error logger");


    return 0;
}