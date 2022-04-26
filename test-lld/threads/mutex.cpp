#include <bits/stdc++.h>
using namespace std;


vector<int> vec;
mutex m;

/*

Class mutex is a synchronization primitive that is used to protect shared data from simultaneous access.
A mutex can be locked and unlocked. Once a mutex is locked,
current thread owns mutex until it is not unlocked.
It means that no other thread can execute any instructions from the block of code
surrounded by mutex until thread that owns mutex unlocks it.
If you want to use mutex, you have to include mutex header in the program:
*/

void push()
{
  m.lock();
    for (int i = 0; i != 10; ++i)
    {
      cout << "Push " << i << endl;
      _sleep(500);
      vec.push_back(i);
    }
  m.unlock();
}
void pop()
{
  m.lock();
  for (int i = 0; i != 10; ++i)
  {
    if (vec.size() > 0)
    {
      int val = vec.back();
      vec.pop_back();
      cout << "Pop " << val << endl;
    }
  _sleep(500);
  }
  m.unlock();
}

int main()
{
  //create two threads
  thread pushit(push);
  thread popit(pop);
  if (pushit.joinable())
    pushit.join();
  if (popit.joinable())
    popit.join();
}

/*

there is mutex try lock as well
m.try_lock()
which is non blocking means that if one thread does not gets that lock
will skip and move ahead
*/

  /*
timed_mutex m;
m.try_lock(chrono::seconds(1));   -> for how much time thread will wait to get the lock, if thread waited for
the given time and still could not get the lock then will skip it and move ahead
this_thread::sleep_for(chrono::seconds(2));
  */

 /*
 0. It is very light weight wrapper for owning mutex on scoped basis.
1. It acquires mutex lock the moment you create the object of lock_guard.
2. It automatically removes the lock while goes out of scope.
3. You can not explicitly unlock the lock_guard.
4. You can not copy lock_guard.
 lock_guard<mutex> guard(m)
 */

/*
1. The class unique_lock is a mutex ownership wrapper.
2. It Allows:
    a. Can Have Different Locking Strategies
    b. time-constrained attempts at locking (try_lock_for, try_lock_until)
    c. recursive locking
    d. transfer of lock ownership (move not copy)
    e. condition variables. (See this in coming videos)

Locking Strategies
   TYPE           EFFECTS(S)
1. defer_lock  do not acquire ownership of the mutex.
2. try_to_lock  try to acquire ownership of the mutex without blocking.
3. adopt_lock  assume the calling thread already has ownership of the mutex.

unique_lock<mutex> lock(m);
*/