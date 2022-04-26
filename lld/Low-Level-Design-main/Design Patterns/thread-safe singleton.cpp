#include<bits/stdc++.h>
using namespace std;

class Singleton
{
private:
    static Singleton* pinstance_;
    static mutex mutex_;
protected:
    Singleton(const string value) {
        value_ = value;
    }
    ~Singleton() {}
    string value_;
public:
    Singleton(Singleton &other) = delete; //singleton cannot be cloned.
    void operator=(const Singleton &) = delete; //should not be assignable.

    static Singleton* getInstance(const string& value);

    void someBuisnessLogic() {
        //any operation u want to do.
    }

    string value() const {
        return value_;
    }
};
// Static methods should be defined outside the class.
Singleton* Singleton::pinstance_ = nullptr;
mutex Singleton::mutex_;

Singleton* Singleton::getInstance(const string& value) {
    lock_guard<mutex> lock(mutex_);
    if (pinstance_ == nullptr)
        pinstance_ = new Singleton(value);
    return pinstance_;
}


void ThreadFoo() {
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton* singleton = Singleton::getInstance("FOO");
    std::cout << singleton->value() << "\n";
}

void ThreadBar() {
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton* singleton = Singleton::getInstance("BAR");
    std::cout << singleton->value() << "\n";
}


int32_t main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::cout << "If you see the same value, then singleton was reused (yay!\n" <<
              "If you see different values, then 2 singletons were created (booo!!)\n\n" <<
              "RESULT:\n";
    std::thread t1(ThreadFoo);
    std::thread t2(ThreadBar);
    t1.join();
    t2.join();

    return 0;
}