#include <bits/stdc++.h>
#include "model/user.h"
#include "model/expense.h"
#include "model/equalexpen.h"
#include "service/expenseService.h"
#include "service/expenseManager.h"
using namespace std;

int main()
{

    expenseManager ex;
    user user1("first", "firs@first.in", "9999999998", "u1");
    ex.addUser(user1);
    user user2("second", "firs@first.in", "9999999997", "u2");

    ex.addUser(user2);
    user user3("third", "firs@first.in", "9999999996", "u3");

    ex.addUser(user3);
    user user4("fourth", "firs@first.in", "9999999995", "u4");

    ex.addUser(user4);
    user user5("fifth", "firs@first.in", "9999999994", "u5");

    ex.addUser(user5);
    while (true)
    {
        string first;
        cin >> first;

        if (first == "EXPENSE")
        {
            string code;
            cout << "enter code"
                 << "\n";
            getline(cin, code);
            try
            {
                ex.addExpense(code);
            }
            catch (exception &e)
            {
                cout << "exception occured Please try again";
            }
        }
        else if (first == "SHOW")
        {
            string userid;
            cin >> userid;
            ex.showBalance(userid);
        }
    }

    return 0;
}