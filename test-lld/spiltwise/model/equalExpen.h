#ifndef EQUAL_EXPENSE_H
#define EQUAL_EXPENSE_H
#include <bits/stdc++.h>
#include "expense.h"
#include "user.h"

using namespace std;

class equalExpense : public expense
{
private:
    /* data */
public:

    bool validateExpense();
    void calculateSplitAmount();
    
};




#endif