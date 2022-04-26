#ifndef EXPENSE_SERVICE_H
#define EXPENSE_SERVICE_H

#include <bits/stdc++.h>
#include <iostream>
#include "../model/expense.h"
#include "../model/equalExpen.h"
#include "../model/exactExpense.h"
#include "../model/user.h"
#include "../enums/expenseType.h"
#include "../exceptions/validtionException.h"

using namespace std;

class expenseService {

private:

    map<string, expenseType> expenseTypeMapping;

public:

    expenseService();
    expense * createExpense(string expenseType);
    expense * initializeExpense(expense *);

};


#endif