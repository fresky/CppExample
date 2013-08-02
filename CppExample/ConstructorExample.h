#include "stdafx.h"
#include <iostream>

class Demo
{
public:
    Demo();	
    Demo(int a);	
    ~Demo(void){}
};

Demo::Demo()
{
    std::cout<<"Demo()!"<<std::endl;
}

Demo::Demo(int a)
{
    std::cout<<"Demo(int a), a = "<<a<<std::endl;
}

int intValue = 1;


void Example1()
{
    std::cout<<"Example1 Demo demo(): no object created, only declare a function!"<<std::endl;
    Demo demo();
}


void Example2()
{
    std::cout<<"Example2 Demo(intValue): inValue object created, called the default constructor!"<<std::endl;
    Demo(intValue);
}


void Example3()
{
    std::cout<<"Example3 (Demo(intValue)): a temp object created, called the int constructor!"<<std::endl;
    (Demo(intValue));
}


void Example4()
{
    std::cout<<"Example4 static_cast<Demo>(intValue): a temp object created, called the int constructor!"<<std::endl;
    static_cast<Demo>(intValue);
}

Demo Example5()
{
    std::cout<<"Example5 return Demo(intValue): a temp object created, called the int constructor!"<<std::endl;
    return Demo(intValue);
}

void Example6()
{
    std::cout<<"Example6 void(), Demo(intValue): a temp object created, called the int constructor!"<<std::endl;
    void(), Demo(intValue);
}

void Example7()
{
    std::cout<<"Example7 Demo(+intValue): a temp object created, called the int constructor!"<<std::endl;
    Demo(intValue++);
    std::cout<<intValue<<std::endl;
    Demo(+intValue);
    std::cout<<intValue<<std::endl;
    Demo(++intValue);
    std::cout<<intValue<<std::endl;
}

void ConstructorExample()
{
    Example1();

    Example2();

    Example3();

    Example4();

    Example5();

    Example6();

    Example7();
}