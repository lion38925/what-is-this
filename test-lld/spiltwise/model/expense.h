#ifndef EXPENSE_H
#define EXPENSE_H
#include <bits/stdc++.h>
using namespace std;
#include "user.h"

class expense
{
private:
    string expense_id;
    double amountPaid;
    string paidBy;
    map<string, double> splitAmount;

    /* data */
public:

    virtual bool validateExpense() = 0;
    virtual void calculateSplitAmount() = 0;
    string getExpenseId();
    void setExpenseId(string expenseId_);
    double getAmountPaid();
    void setAmountPaid(double amountPaid_);

    string getPaidBy();
    void setPaidBy(string paidBy_);

    map<string, double> getSplitAmount();
    void setSplitAmount(map<string, double> splitAmount_);
    
};




#endif