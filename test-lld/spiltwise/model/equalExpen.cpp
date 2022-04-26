#include "equalExpen.h"

bool equalExpense::validateExpense()
{
    return true;
};

void equalExpense::calculateSplitAmount()
{
    map<string, double> splitAmountUsers = this->getSplitAmount();
    int size = splitAmountUsers.size();
    double totalAmountPaid = this->getAmountPaid();
    double equalAmountPaid = totalAmountPaid / size;
    for (auto userSplit : splitAmountUsers)
    {
        splitAmountUsers[userSplit.first]= equalAmountPaid;
    }
    setSplitAmount(splitAmountUsers);
}
