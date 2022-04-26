/*
1. Condition variables allow us to synchronize threads via notifications.
   a. notify_one();
   b. notify_all();
2. You need mutex to use condition variable
3. Condition variable is used to synchronize two or more threads.
4. Best use case of condition variable is Producer/Consumer problem.
5. Condition variables can be used for two purposes:
    a. Notify other threads
    b. Wait for some condition
*/
#include <iostream>
#include <condition_variable>
#include <thread>
#include <chrono>
using namespace std::chrono_literals;
 
std::condition_variable cv;
std::mutex cv_m;
 
void waits()
{
    std::unique_lock<std::mutex> lk(cv_m);
    std::cout << "Waiting... \n";
    cv.wait(lk);
    std::cout << "...finished waiting; i == "<< '\n';
}
 
void signals()
{
    //std::this_thread::sleep_for(200ms);
    std::unique_lock<std::mutex> lit(cv_m); // remember to use unique lock here do not use any other lock
    std::cout<<"inside signal"<<"\n";
    lit.unlock();
    cv.notify_one();

}
 
int main()
{
    std::thread t1(waits), t2(signals);
    t1.join(); 
    t2.join();
}