#include "exactExpense.h"

bool exactExpense::validateExpense()
{
    return true;
};

void exactExpense::calculateSplitAmount()
{
    map<string, double> splitAmountUsers = this->getSplitAmount();
    int size = splitAmountUsers.size();
    double totalAmountPaid = this->getAmountPaid();
    double equalAmountPaid = totalAmountPaid / size;
    for (auto userSplit : splitAmountUsers)
    {
        userSplit.second = equalAmountPaid;
    }
    setSplitAmount(splitAmountUsers);
}

