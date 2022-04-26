#include "expenseService.h"

expenseService::expenseService(){
    this->expenseTypeMapping["EQUAL"] = expenseType::EQUAL_EXPENSE;
    this->expenseTypeMapping["EXACT"] = expenseType::EXACT_EXPENSE;
}

expense* expenseService::createExpense(string expenseString)
{
    stringstream ss(expenseString);

    vector<string> sv;

    string word;
    while (ss >> word)
    {
        sv.push_back(word);
    }

    string stringUserpaid = sv[0];
    double amount = stod(sv[1]);
    long count = stoi(sv[2]);
    string etype = sv[2 + count + 1];

    if(!this->expenseTypeMapping.count(etype)){
        
        validationException vde("invalid expense type entered");
        throw vde;
    }
    expenseType exType = this->expenseTypeMapping[etype];
    map<string, double> mp;
    int i = 3;
    while (i < count + 3)
    {
        mp[sv[i]] = 0.0;
        i++;
    }


    expense* pit = new equalExpense();
    expense* eit = new equalExpense();
    switch (exType)
    {
    case expenseType::EQUAL_EXPENSE :
        eit->setAmountPaid(amount);
        eit->setPaidBy(stringUserpaid);
        eit->setSplitAmount(mp);
        cout<<"created Expense";
        return eit;
        break;
    }

    return pit;
};

expense *expenseService::initializeExpense(expense *exT)
{
    exT->validateExpense();
    exT->calculateSplitAmount();
    return exT;
};
