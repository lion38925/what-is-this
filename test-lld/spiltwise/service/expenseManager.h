#ifndef EXPENSE_MANAGER_SERVICE_H
#define EXPENSE_MANAGER_SERVICE_H
#include <bits/stdc++.h>
#include <iostream>
#include "../model/user.h"
#include "../model/expense.h"
#include "../model/equalexpen.h"
#include "expenseService.h"
#include "../repository/userRepository.h"
#include "../repository/expenseRepository.h"
using namespace std;

class expenseManager {

private:

    userRepository userRepo;
    expenseRepository expRepo;
    expenseService expenseServiceExecutor;

public:

    expenseManager();
    void addUser(user user);
    void addExpense(string expenseString);
    void showBalance(string userId);
    void showBalances();

};

#endif