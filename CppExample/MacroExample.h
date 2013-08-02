#include "stdafx.h"
#include <iostream>

#define ADDWITHOUTBRACKETS(x,y) x+y
#define ADD(x,y) ((x)+(y))

#define MULTIPLEWITHOUTBRACKETS(x, y) x*y
#define MULTIPLE(x,y) ((x)*(y))

#define INCREASEWITHOUTBRACE(a, b) ++(a);++(b);
#define INCREASE(a, b) {++(a);++(b);}


#define SWAP(x, y) {x=x+y;\
    y=x-y;\
    x=x-y;}


int Add(int x, int y)
{
    return x+y;
}

int Multiple(int x, int y)
{
    return x*y;
}

void Increase(int& x, int& y)
{
    ++x;
    ++y;
}

void Swap(int& x, int& y)
{
    x = x+y;
    y = x-y;
    x = x-y;
}

void ErrorWithoutBracketsForParameter()
{
    std::cout<<"Error Without Brackets For Parameter: #define MULTIPLEWITHOUTBRACKETS(x, y) x*y"<<std::endl;
    std::cout<<"MULTIPLEWITHOUTBRACKETS(1+1,1+2):"<<std::endl<<"Expected: "<<Multiple(1+1,1+2)<<" , Actual: "<<MULTIPLEWITHOUTBRACKETS(1+1,1+2)<<std::endl;
    std::cout<<"Should be: #define ADD(x,y) ((x)+(y))"<<std::endl;
    std::cout<<"MULTIPLE(1+1,1+2):"<<std::endl<<"Expected: "<<Multiple(1+1,1+2)<<" , Actual: "<<MULTIPLE(1+1,1+2)<<std::endl;
    std::cout<<std::endl;
}


void ErrorWithoutBracketsForResult()
{
    std::cout<<"Error Without Brackets For Result: #define ADDWITHOUTBRACKETS(x,y) x+y"<<std::endl;
    std::cout<<"ADDWITHOUTBRACKETS(1,2)*3:"<<std::endl<<"Expected: "<<Add(1,2)*3<<" , Actual: "<<ADDWITHOUTBRACKETS(1,2)*3<<std::endl;
    std::cout<<"Should be: #define MULTIPLEWITHOUTBRACKETS(x, y) x*y"<<std::endl;
    std::cout<<"ADD(1,2)*3:"<<std::endl<<"Expected: "<<Add(1,2)*3<<" , Actual: "<<ADD(1,2)*3<<std::endl;
    std::cout<<std::endl;
}

void ErrorWithoutCurlyBraceForMultiLine()
{
    int a = 1;
    int b = 2;

    std::cout<<"Error Without Curly Brace For MultiLine: #define INCREASEWITHOUTBRACE(a, b) (a)++;(b)++;"<<std::endl;
    std::cout<<"for (int index = 0; index < 2; index++) INCREASEWITHOUTBRACE("<<a<<", "<<b<<")"<<std::endl;
    for (int index = 0; index < 2; index++)
        INCREASEWITHOUTBRACE(a, b);

    std::cout<<"Result: a = "<<a<<", b= "<< b<<std::endl;
    std::cout<<"Should be: #define INCREASE(a, b) {++(a);++(b);}"<<std::endl;
    std::cout<<"for (int index = 0; index < 2; index++) INCREASEWITHOUTBRACE("<<a<<", "<<b<<")"<<std::endl;
    a = 1;
    b = 2;
    for (int index = 0; index < 2; index++)
        INCREASE(a, b);
    std::cout<<"Result: a = "<<a<<", b= "<< b<<std::endl;
    std::cout<<std::endl;
}

void MacroExample()
{
    ErrorWithoutBracketsForParameter();

    ErrorWithoutBracketsForResult();

    ErrorWithoutCurlyBraceForMultiLine();    
}