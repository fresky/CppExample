#include <iostream>

struct Base
{
    virtual ~Base(){ }
    virtual void foo(int a=0) { std::cout << "base: " << a << std::endl; }
};

struct Derived : public Base
{
    virtual ~Derived() { }
    virtual void foo(int a=1) { std::cout << "derived: " << a << std::endl; }
};

void DefaultParameter()
{
    Base* derived = new Derived();
    derived->foo();    // prints "derived: 0"
    delete derived;
}