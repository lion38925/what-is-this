#include "expenseManager.h"

void expenseManager::showBalance(string userId)
{
    map<string, map<string, double>> sheet = this->expRepo.getbalancesheet(userId);

    // need to update the balance sheet;
    if (!sheet.count(userId))
    {
        cout<<"no data exist";
        
    }
    else
    {
        map<string, double> tempMap = sheet[userId];
        for (auto kit : tempMap)
        {
            cout<<userId<<" "<<kit.first<<" "<< kit.second<<"\n";
        }
    }
}
void expenseManager::showBalances()
{
}
void expenseManager::addExpense(string expenseString)
{
    expense* newExpense = NULL;

    try{
        newExpense = this->expenseServiceExecutor.createExpense(expenseString);
    }catch(validationException& e){
        cout<<"\n"<<e.what()<<"\n";
        throw e;
    }
    if(newExpense == NULL){
        cout<<"newExpense is null"<<"\n";
    }
    this->expenseServiceExecutor.initializeExpense(newExpense);
    map<string, map<string, double>> sheet = this->expRepo.getbalancesheet();

    string paidB = newExpense->getPaidBy();

    // need to update the balance sheet;
    map<string, double> tempMap;
    if (!sheet.count(paidB))
    {
        cout<<"manager";
        for (auto kit : newExpense->getSplitAmount())
        {
            tempMap[kit.first] = kit.second;
        }
    }
    else
    {
        tempMap = sheet[paidB];
        for (auto kit : newExpense->getSplitAmount())
        {
            tempMap[kit.first] += kit.second;
        }
    }
    sheet[paidB] = tempMap;

    for (auto kit : newExpense->getSplitAmount())
    {
        map<string, double> temppit;    
        if (!sheet.count(kit.first))
        {
            temppit[paidB] = -1 * kit.second;
        }
        else
        {
            temppit = sheet[kit.first];
            temppit[paidB] += -1 * kit.second;
        }
        sheet[kit.first] = temppit;
    }
    this->expRepo.updateBalanceSheet(sheet);
};
void expenseManager::addUser(user user)
{
    if (this->userRepo.userExist(user.getId()) )
    {
        cout << "user already exist ";
    }
    else
    {
        this->userRepo.addUserIn(user);
    }
}
expenseManager::expenseManager(){
};