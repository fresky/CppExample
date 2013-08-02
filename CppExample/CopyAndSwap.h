#include <algorithm> 
#include <iostream>

class DynamicArray
{
public:
    DynamicArray(size_t size=0):
        m_Size(size),
        m_Array(size?new int[size]:0)
    {
            std::cout<<"ctor........."<<std::endl;
    }
    DynamicArray(DynamicArray& copy):
        m_Size(copy.m_Size),
        m_Array(copy.m_Size?new int[copy.m_Size]:0)
    {
        std::copy(copy.m_Array, copy.m_Array+copy.m_Size,this->m_Array);
        std::cout<<"copy........"<<std::endl;
    };
    DynamicArray& operator=(DynamicArray assign)
    {
        std::swap(assign.m_Size, m_Size);
        std::swap(assign.m_Array,m_Array);
        std::cout<<"assign......."<<std::endl;
        return *this;
    };
    ~DynamicArray()
    {
        delete[] m_Array;
        std::cout<<"deleting"<<std::endl;
    };

private:
    size_t m_Size;
    int* m_Array;
};

void CopyAndSwapExample()
{
    DynamicArray d1;
    DynamicArray d2(d1);
    d2=d1;
}
