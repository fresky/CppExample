#include "stdafx.h"
#include <iostream>

using namespace std;
class SubException;
class BaseException
{
public:
    BaseException(){ cout<<"BaseExeption"<<endl; };
    BaseException(BaseException& ){cout<<"BaseExeption Copy from BaseException"<<endl;};
    BaseException(SubException& ){cout<<"BaseExeption Copy from SubException"<<endl;};
    ~BaseException(){cout<<"~BaseExeption"<<endl;};
    virtual void PrintMessage(){cout<<"I'm BaseException"<<endl;}
};

class SubException:public BaseException
{
public:
    SubException(){cout<<"SubException"<<endl;}
    SubException(SubException& ):BaseException(){cout<<"SubException Copy from SubException"<<endl;};
    ~SubException(){cout<<"~SubException"<<endl;}
    virtual void PrintMessage(){cout<<"I'm SubException"<<endl;}
};

void CatchBaseObject(bool throwbase)
{
    cout<<"==================="<<endl<<"CatchBaseObject "<<(throwbase?"ThrowBase":"ThrowSub")<<endl;
    try
    {
        throwbase? throw BaseException(): throw SubException();
    }
    catch (BaseException e)
    {
    	e.PrintMessage();
    }
}
void CatchSubObject(bool throwbase)
{
    cout<<"==================="<<endl<<"CatchSubObject "<<(throwbase?"ThrowBase":"ThrowSub")<<endl;
    try
    {
        throwbase? throw BaseException(): throw SubException();
    }
    catch (SubException e)
    {
        e.PrintMessage();
    }
}

void CatchBaseRef(bool throwbase)
{
    cout<<"==================="<<endl<<"CatchBaseRef "<<(throwbase?"ThrowBase":"ThrowSub")<<endl;
    try
    {
        throwbase? throw BaseException(): throw SubException();
    }
    catch (BaseException& e)
    {
        e.PrintMessage();
    }
}
void CatchSubRef(bool throwbase)
{
    cout<<"==================="<<endl<<"CatchSubRef "<<(throwbase?"ThrowBase":"ThrowSub")<<endl;
    try
    {
        throwbase? throw BaseException(): throw SubException();
    }
    catch (SubException& e)
    {
        e.PrintMessage();
    }
}

void CatchBasePointer(bool throwbase)
{
    cout<<"==================="<<endl<<"CatchBasePointer "<<(throwbase?"ThrowBase":"ThrowSub")<<endl;
    try
    {
        throwbase? throw &BaseException(): throw &SubException();
    }
    catch (BaseException* e)
    {
        e->PrintMessage();
    }
}
void CatchSubPointer(bool throwbase)
{
    cout<<"==================="<<endl<<"CatchSubPointer "<<(throwbase?"ThrowBase":"ThrowSub")<<endl;
    try
    {
        throwbase? throw &BaseException(): throw &SubException();
    }
    catch (SubException* e)
    {
        e->PrintMessage();
    }
}

void CatchBaseObjectForThrowSubAndThrowAgain()
{
    cout<<"==================="<<endl<<"CatchBaseObjectForThrowSubAndThrowAgain "<<endl;
    try
    {
        try
        {
            throw SubException();
        }
        catch (BaseException e)
        {
            e.PrintMessage();
            throw;
        }
    }
    catch (SubException e)
    {
    	e.PrintMessage();
    }
}

void CatchBaseObjectForThrowSubAndThrowItAgain()
{
    cout<<"==================="<<endl<<"CatchBaseObjectForThrowSubAndThrowItAgain "<<endl;
    try
    {
        try
        {
            throw SubException();
        }
        catch (BaseException e)
        {
            e.PrintMessage();
            throw e;
        }
    }
    catch (SubException e)
    {
        e.PrintMessage();
    }
}

void ExceptionArgumentExample()
{
    CatchBaseObject(true);
    CatchBaseObject(false);
    //CatchSubObject(true); // this will not catch the exception
    CatchSubObject(false);
    
    CatchBaseRef(true);
    CatchBaseRef(false);
    //CatchSubRef(true); // this will not catch the exception
    CatchSubRef(false);
    
    CatchBasePointer(true);
    CatchBasePointer(false);
    //CatchSubPointer(true); // this will not catch the exception
    CatchSubPointer(false);
    
    CatchBaseObjectForThrowSubAndThrowAgain();
    //CatchBaseObjectForThrowSubAndThrowItAgain();//this will not catch the exception
}