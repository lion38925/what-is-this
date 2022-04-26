#include <bits/stdc++.h>
using namespace std;

mutex mu;
condition_variable cv;
deque<int> q;
int max_buffer_size = 10;

void producer(int value)
{
    for (int i = 0; i < value; i++)
    {
        unique_lock<mutex> lc(mu);
        cv.wait(lc, []()
                { return q.size() < max_buffer_size; }); // this condition or predicate is used to check that if
                //  this condition is true only then it will go ahead other wise it will wait
        q.push_back(i);
        cout << "data entered in queue " << i << "\n";
        lc.unlock();
        cv.notify_one();
    }
}

void consumer()
{
    while (true)
    {
        unique_lock<mutex> lc(mu);
        cv.wait(lc, []()
                { return q.size()>0; });
        cout << "data consumed from queue " << q.back() << "\n";
        q.pop_back();
        lc.unlock();
        cv.notify_one();
    }
}

/*
THE PROBLEM STATEMENT:
 1. Producer will produce and consumer will consume with synchronization of a common buffer.
 2. Until producer thread produces any data consumer thread can't consume.
 3. Threads will use condition_variable to notify each other.
 4. We need mutex if we use condition_variable because CV waits on mutex.
 5. This is one of the example of producer consumer there are many.

PRODUCER thread steps:
 1. lock mutex, if success then go ahead otherwise wait for mutex to get free.
 2. check if buffer is full and if it is full then unlock mutex and sleep, if not then go ahead and produce.
 3. insert item in buffer.
 4. unlock mutex. 
 5. notify consumer.

CONSUMER thread steps:
 1. lock mutex, if success then go ahead otherwise wait for mutex to get free.
 2. check if buffer is empty and if it is, then unlock the mutex and sleep, if not thean go ahead and consume.
 3. consume item from buffer.
 4. unlock mutex.
 5. notify producer.

*/
int main()
{
    thread produerThread(producer, 100);
    thread consumerThread(consumer);
    produerThread.join();
    consumerThread.join();
    return 0;
}