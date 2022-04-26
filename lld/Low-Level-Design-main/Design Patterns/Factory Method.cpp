#include<bits/stdc++.h>
using namespace std;
#define int long long int

//Product interface, all concrete products must implement.
class Product
{
public:
    virtual ~Product() {}
    virtual string Operation() const = 0;
};

class ConcreteProduct1 : public Product
{
public:
    string Operation() const override {
        return "{Result of ConcreteProduct1.}";
    }
};

class ConcreteProduct2 : public Product
{
public:
    string Operation() const override {
        return "{Result of ConcreteProduct2.}";
    }
};


//Creator (Factory Class):

/**
 * The Creator class declares the factory method that is supposed to return an
 * object of a Product class. The Creator's subclasses usually provide the
 * implementation of this method.
 */
class Creator
{
public:
    virtual ~Creator() {};
    virtual Product* FactoryMethod() const = 0;
    /**
    * Also note that, despite its name, the Creator's primary responsibility is
    * not creating products. Usually, it contains some core business logic that
    * relies on Product objects, returned by the factory method. Subclasses can
    * indirectly change that business logic by overriding the factory method and
    * returning a different type of product from it.
    */
    string someOperation() const {
        //call the factory to create a product object.
        Product *obj = this->FactoryMethod();
        string result = "Creator: The same creator's code has just worked with " + obj->Operation();
        delete obj;
        return result;
    }
};

//Concrete Creators:
class ConcreteCreator1 : public Creator
{
public:
    Product* FactoryMethod() const override {
        return new ConcreteProduct1();
    }
};

class ConcreteCreator2: public Creator
{
public:
    Product* FactoryMethod() const {
        return new ConcreteProduct2();
    }
};


//Client (User calls)
void clientCode(const Creator& creator) {
    cout << "Client: I'm not aware of the creator's class, but it still works.\n"
         << creator.someOperation() << endl;
}

int32_t main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << "App: Launched with the ConcreteCreator1.\n";
    Creator* creator = new ConcreteCreator1();
    clientCode(*creator);
    cout << endl;

    cout << "App: Launched with the ConcreteCreator2.\n";
    Creator* creator2 = new ConcreteCreator2();
    clientCode(*creator2);

    delete creator;
    delete creator2;
    return 0;
}