#include <iostream>
#include <vector>

#include "../learn_template/my_traits.hpp"

void fun()
{

}


void fun1(...)
{

}

struct NoDefault
{
    NoDefault() = delete;
};


int main(int argc, char **argv)
{
    auto i = MyTemplate::IsPointer<int>::value;

    i = MyTemplate::IsPointer<int*>::value;

    i = MyTemplate::IsPointer<const int*>::value;


    i = MyTemplate::IsConst<int * const>::value;
    i = MyTemplate::IsConst< int>::value;


    const int cNum = 20;


    int a[] = {1,2,3,4,5};

    char szBuf[] = "qwewqeqeqeqeq";


    for (int i = 0; i < sizeof(a)/sizeof(int); i++)
    {
        
    }

    std::cout<<MyTemplate::MyAdd(a, a+5)<<'\n';
    std::cout<<MyTemplate::MyAdd(szBuf, szBuf+sizeof(szBuf)/sizeof(char))<<'\n';
    

    int num = 99;
    MyTemplate::RemoveConst<const int> c;

    MyTemplate::RemoveConst<const int&> d = num;

    MyTemplate::RemoveReference <const int&> e = 20;

    MyTemplate::RemoveReference <int&> f;

    MyTemplate::RemoveCR<const int &> g;

    
    using VVFun = void(void);
    MyTemplate::DecayT<VVFun>::type h = fun;

    using VMFun = void(...);
    MyTemplate::DecayT<VMFun>::type j = fun1;


    if(MyTemplate::IsSame<int, int>)
    {
        std::cout<<"IsSame<int, int>"<<'\n';
    } 

    if(!MyTemplate::IsSame<int, char>)
    {
        std::cout<<"not IsSame<int, char>"<<'\n';
    } 


    if(MyTemplate::IsDefaultConstructibleT<int>::value)
    {
        std::cout<<"IsDefaultConstructibleT int"<<'\n';
    } 
    

    if(!MyTemplate::IsDefaultConstructibleT<NoDefault>::value)
    {
        std::cout<<"NoNONO IsDefaultConstructibleT NoDefault"<<'\n';
    } 

    MyTemplate::IsConvertHelp<int, NoDefault>::Type::value;
    
    MyTemplate::IsConvertHelp<int, double>::Type::value;


    MyTemplate::HasSizeTypeT<std::vector<int>>::value;
    MyTemplate::HasSizeTypeT<NoDefault>::value;
    
    return 0;
}