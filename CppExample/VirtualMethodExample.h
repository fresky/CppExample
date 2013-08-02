using namespace std;
class Parent
{
public:
    Parent()
    {
        cout<<"Parent ctor!"<<endl;
        Print();
    }
    virtual ~Parent(){};
    virtual void Print()
    {
        cout<<"Parent print!"<<endl;
    }
};

class Child:public Parent
{
public:
    Child()
    {
        childField = 10;
        cout<<"Child ctor! "<<childField<<endl;
    }
    ~Child(){};
    void Print()
    {
        cout<<"Child print!  "<<childField<<endl;
    }

private:
    int childField;
};

void VirtualMethodExample()
{
    Child s;
}