
#include <bits/stdc++.h>
using namespace std;

vector<int> myVec{};
counting_semaphore<1> prepareSignal(0);              // (1)

void prepareWork() {

    this_thread::sleep_for(chrono::seconds(1));    
    myVec.insert(myVec.end(), {0, 1, 0, 3});
    std::cout << "Sender: Data prepared."  << '\n';
    prepareSignal.release();                              // (2)
}

void completeWork() {

    std::cout << "Waiter: Waiting for data." << '\n';
    prepareSignal.acquire();                              // (3)
    myVec[2] = 2;
    std::cout << "Waiter: Complete the work." << '\n';
    for (auto i: myVec) std::cout << i << " ";
    std::cout << '\n';
    
}
/*
The std::counting_semaphore prepareSignal (1) can have the values 0 oder 1.
In the concrete example, it's initialized with 0 (line 1).
This means, that the call prepareSignal.release() sets the value to 1 (line 2)
and unblocks the call prepareSignal.acquire()
*/
int main() {

    std::cout << '\n';

    std::thread t1(prepareWork);
    std::thread t2(completeWork);

    t1.join();
    t2.join();

    std::cout << '\n';
  
}