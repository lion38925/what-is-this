#include <bits/stdc++.h>
using namespace std;
/*
If you want to initialize a thread with a public member function of a class,
you have to specify the identifier of this function and pass an object of the class,
which defines this member function:

*/
void myfunc(string k, int value){
    cout<< "thread function with params : "<<k<<"and "<<value<<"\n";
}

class myFunctor {

    public:
     void operator()(string k, int value){

        cout<< "thread function of object with params : "<<k<<"and "<<value<<"\n";
     }
};

/*

When you pass arguments to the member function of a class,
you have to specify arguments in the same order as they are listed in the parameter
list of the function. It is done after the second parameter of the thread constructor:

*/

int main()
{
    thread firstthread(myfunc, "19 april 2022 ",2);

    firstthread.join();
    myFunctor functor;

    thread theadwithobject(functor, "19th april 2022 ", 3);
    theadwithobject.join();
    return 0;
}