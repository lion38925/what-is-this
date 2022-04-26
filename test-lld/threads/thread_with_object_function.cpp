#include <bits/stdc++.h>
using namespace std;
/*
If you want to initialize a thread with a public member function of a class,
you have to specify the identifier of this function and pass an object of the class,
which defines this member function:

*/
class myfunctor
{

public:
    void publicfunction()
    {
        cout << "thread created using public function";
    }
};

int main()
{
    myfunctor functor;
    thread firstthread(myfunctor::publicfunction, functor);

    firstthread.join();
    return 0;
}