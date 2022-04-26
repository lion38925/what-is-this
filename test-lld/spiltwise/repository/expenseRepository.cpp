#include "expenseRepository.h"

void expenseRepository::updateBalanceSheet(map<string, map<string, double>> sheet)
{
    this->balanceSheet = sheet;
}
map<string, map<string, double>> expenseRepository::getbalancesheet(string id)
{
    return this->balanceSheet;
}
map<string, map<string, double>> expenseRepository::getbalancesheet()
{
    return this->balanceSheet;
}