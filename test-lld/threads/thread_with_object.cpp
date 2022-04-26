#include <bits/stdc++.h>
using namespace std;
/*
You can initialize a thread not only with a function.
You can use for this purpose function object (functor) or a member function of a class.

A functor is an object of a class that overloads operator () – function call operator.

If you want to initialize a thread with an object of a class, this class should overload operator().
It can be done in the following way:

*/
class myfunctor
{

public:
    void operator()()
    {
        cout << "thread created using object";
    }
};

int main()
{
    myfunctor functor;
    thread firstthread(functor);

    firstthread.join();
    return 0;
}