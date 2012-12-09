#include "stdafx.h"
#include <iostream>

using namespace std;
static const int ArrayCount = 5;
class A
{
public:
    int aa;
    A(){ cout<<"A"<<" "; aa=1;};
    ~A(){cout<<"~A"<<" ";aa=-1;};
};

class B:public A
{
public:
    int bb;
    B(){cout<<"B"<<" ";bb=2;}
    ~B(){cout<<"~B"<<" ";bb=-2;}
};

class C
{
public:
    int cc;
    C(){ cout<<"C"<<" "; cc=3;};
    virtual ~C(){cout<<"~C"<<" ";cc=-3;};
};
class D:public C
{
public:
    int dd;
    D(){cout<<"D"<<" ";dd=4;}
    ~D(){cout<<"~D"<<" ";dd=-4;}
};

void NoArrayPolymorphismForNoVirtual()
{
    cout<<endl<<"NoArrayPolymorphismForNoVirtual:"<<endl;

    cout<<"size of A: "<<sizeof(A)<<endl;
    cout<<"size of B: "<<sizeof(B)<<endl;
    A* aarray = new B[ArrayCount];

    cout<<endl<<endl<<"aa value of A* is:"<<endl;
    for (int i = 0; i < ArrayCount; i++)
    {
        cout<<aarray[i].aa<<", ";
    }
    cout<<endl;

    B* baaray = (B*)aarray;
    cout<<endl<<"aa value of B* is:"<<endl;
    for (int i = 0; i < ArrayCount; i++)
    {
        cout<<baaray[i].aa<<", ";
    }
    cout<<endl<<endl;

    delete[] aarray;
    cout<<endl<<endl<<"After delete[]"<<endl;

    cout<<endl<<"aa value of A* is:"<<endl;
    for (int i = 0; i < ArrayCount; i++)
    {
        cout<<aarray[i].aa<<", ";
    }
    cout<<endl;
    baaray = (B*)aarray;
    cout<<endl<<"aa value of B* is:"<<endl;
    for (int i = 0; i < ArrayCount; i++)
    {
        cout<<baaray[i].aa<<", ";
    }
}


void NoArrayPolymorphismForVirtual()
{
    cout<<endl<<"NoArrayPolymorphismForVirtual:"<<endl;

    cout<<"size of C: "<<sizeof(C)<<endl;
    cout<<"size of D: "<<sizeof(D)<<endl;
    C* carray = new D[ArrayCount];

    cout<<endl<<endl<<"cc value of C* is:"<<endl;
    for (int i = 0; i < ArrayCount; i++)
    {
        cout<<carray[i].cc<<", ";
    }
    cout<<endl;

    D* daaray = (D*)carray;
    cout<<endl<<"cc value of D* is:"<<endl;
    for (int i = 0; i < ArrayCount; i++)
    {
        cout<<daaray[i].cc<<", ";
    }
    cout<<endl<<endl;

    delete[] carray;
    cout<<endl<<endl<<"After delete[]"<<endl;

    cout<<endl<<"cc value of C* is:"<<endl;
    for (int i = 0; i < ArrayCount; i++)
    {
        cout<<carray[i].cc<<", ";
    }
    cout<<endl;
    daaray = (D*)carray;
    cout<<endl<<"cc value of D* is:"<<endl;
    for (int i = 0; i < ArrayCount; i++)
    {
        cout<<daaray[i].cc<<", ";
    }
}

void NoArrayPolymorphismExample()
{
    NoArrayPolymorphismForNoVirtual();
    NoArrayPolymorphismForVirtual();
}
