#include <iostream>
#include "../base/SharedPtr.hpp"
#include "../base/WeakPtr.hpp"



void del(int *p)
{
    std::cout<<"del(int *p) = "<<*p<<std::endl;
    delete p;

}


int main()
{


    ZZG::SharedPtr<int> a(new int(20), del);

    std::cout<<"count "<<a.useCount()<<std::endl;
    std::cout<<"weekCount "<<a.weekCount()<<std::endl;

    ZZG::WeakPtr<int> weak(a);
    std::cout<<"count "<<a.useCount()<<std::endl;
    std::cout<<"weekCount "<<a.weekCount()<<std::endl;

    if (weak.expired())
    {
        std::cout<<"expired "<<a.useCount()<<std::endl;
    }
    else
    {
        ZZG::SharedPtr<int> b = weak.lock();
        std::cout<<"lock "<<a.useCount()<<std::endl;
        std::cout<<"count "<<a.useCount()<<std::endl;
        std::cout<<"weekCount "<<a.weekCount()<<std::endl;
    }
    

    weak.reset();
    std::cout<<"count "<<a.useCount()<<std::endl;
    std::cout<<"weekCount "<<a.weekCount()<<std::endl;

    return 0;
}