#include <bits/stdc++.h>
using namespace std;

void threadfunc(){
    cout<<"this is first basic thead";
}

int main(){
    thread firstthread(threadfunc);
    /* if we will not write this function then will get
    terminate called without an active exception but still will print the
    above line 
    
    The runtime exits the scope, only after that thread finishes executing.
    This is achieved by joining with that thread.
    Note the language, it is the outer scope that joins with that thread.
    The runtime leaves the thread to run on its own.
    So, the program will exit the scope, whether this thread finished executing or not.
    This thread executes and exits by itself. This is achieved by detaching the thread.
    This could lead to issues, for example, if the thread refers to variables in that outer scope.
*/
    firstthread.join();
    return 0;
}