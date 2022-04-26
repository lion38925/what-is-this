#ifndef EXACT_EXPENSE_H
#define EXACT_EXPENSE_H
#include <bits/stdc++.h>
#include "expense.h"
#include "user.h"

using namespace std;

class exactExpense : public expense
{
private:
    /* data */
public:

    bool validateExpense();
    void calculateSplitAmount();
    
};




#endif