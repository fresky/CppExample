enum MyEnum
{
    a=1
};

void Warning()
{
    int a1 = 1;
    int a2 = 2;
    MyEnum m = MyEnum::a;

    bool b = 1;             // no warning
    b = 2;                  // warning C4305: '=' : truncation from 'int' to 'bool'
    b = a1;                 // warning C4800: 'int' : forcing value to bool 'true' or 'false' (performance warning)    
    b = a2;                 // warning C4800: 'int' : forcing value to bool 'true' or 'false' (performance warning)    
    b = MyEnum::a;          // no warning
    b = m;                  // warning C4800: 'MyEnum' : forcing value to bool 'true' or 'false' (performance warning)    
    b = !!a2;               // no warning
    b = a2!=0;              // no warning
}