#ifndef EXPENSE_REPOSITORY_H
#define EXPENSE_REPOSITORY_H

#include <bits/stdc++.h>
using namespace std;


class expenseRepository
{
private:
    /* data */
    map<string, map<string,double>>balanceSheet;


public:
   void updateBalanceSheet(map<string, map<string,double>> sheet);
   map<string, map<string,double>> getbalancesheet(string id);
   map<string, map<string,double>> getbalancesheet();


};

#endif