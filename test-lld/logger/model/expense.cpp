#include "expense.h"

string expense::getExpenseId() { return expense_id; };
void expense::setExpenseId(string expenseId_) { expense_id = expenseId_; };
double expense::getAmountPaid() { return amountPaid; };
void expense::setAmountPaid(double amountPaid_) { amountPaid = amountPaid_; };

string expense::getPaidBy() { return paidBy; };
void expense::setPaidBy(string paidBy_) { paidBy = paidBy_; };

map<string, double> expense::getSplitAmount() { return this->splitAmount; };
void expense::setSplitAmount(map<string, double> splitAmount_) { splitAmount = splitAmount_; };
