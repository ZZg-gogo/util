#include <iostream>


#include "../base/SharedPtr.hpp"


void del(int *p)
{
    std::cout<<"del(int *p) = "<<*p<<std::endl;
    delete p;

}

int main()
{

    ZZG::SharedPtr<int> a(new int(20), del);

    std::cout<<*a<<std::endl;


    ZZG::SharedPtr<int> b;

    if (b)
    {
        std::cout<<"b 有值"<<std::endl;
    }
    else
    {
        std::cout<<"b 是空指针"<<std::endl;
    }

    b = a;

    std::cout<<"useCount = "<<b.useCount()<<std::endl;

    int *p = new int(99);
    ZZG::SharedPtr<int> c(new int(30), del);

    ZZG::SharedPtr<int> d = std::move(c);

    

    std::cout<<"main end"<<std::endl;


    ZZG::SharedPtr<int> e(new int(30), del);
    e.reset( new int(888888));
    return 0;
}
