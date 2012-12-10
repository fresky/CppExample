class OverLoadBase
{
public:
    int DoSomething() {return 0;};
};

class OverLoadSub : public OverLoadBase
{
public:
    int DoSomething(int x) {return 1;};
};

void TestOverLoadSub()
{
    OverLoadSub b;
    b.OverLoadBase::DoSomething();    //Why this?
    //b.DoSomething();    //compiler error, because is not overload
    // this will be OK if remove the DoSomething method in the OverLoadSub
}