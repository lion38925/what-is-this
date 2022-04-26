#include <bits/stdc++.h>
using namespace std;

void threadfunc(){
    cout<<"this is first basic thead";
}

int main(){
    thread firstthread(threadfunc);
    /*

This function detaches a thread from the parent thread.
It allows parent and child threads to be executed independently from each other. 
After the call of detach() function, the threads are not synchronized in any way:
    */
    firstthread.detach();

    _sleep(1000000);
    return 0;
}