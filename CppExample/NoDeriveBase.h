class NoDeriveByPrivateCtor {
    NoDeriveByPrivateCtor(){};
public:
    static NoDeriveByPrivateCtor GetNoDerive(){ return NoDeriveByPrivateCtor();};
    ~NoDeriveByPrivateCtor(){};
};



class NoDeriveByVirtualBase;
class NoDeriveVirtualBase
{
    friend class NoDeriveByVirtualBase;
    NoDeriveVirtualBase(){};
};
class NoDeriveByVirtualBase:private virtual NoDeriveVirtualBase {
public:
    NoDeriveByVirtualBase(){};
    ~NoDeriveByVirtualBase(){};
};

