#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
void push()
{
  for (int i = 0; i != 10; ++i)
  {
    cout << "Push " << i << endl;
    _sleep(500);
    vec.push_back(i);
  }
}
void pop()
{
  for (int i = 0; i != 10; ++i)
  {
    if (vec.size() > 0)
    {
      int val = vec.back();
      vec.pop_back();
      cout << "Pop "<< val << endl;
    }
  _sleep(500);
  }
}

/*

As you can see, there is a global vector vec of integer values.
Two threads push and pop try to access this vector simultaneously:
the first thread pushes an element to the vector and the second one tries to pop an element from the vector.

The access to the vector is not synchronized.
Threads are accessing vector non-continuously.
Because of simultaneous access to shared data many errors can appear.
*/
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