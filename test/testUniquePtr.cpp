#include <iostream>

#include "../base/UniquePtr.hpp"



void del(int * p)
{
    std::cout<<"del = "<<*p<<std::endl;
    delete p;
}


int main(int argc, char** argv)
{


    auto lambda = [](int *p) {
        std::cout<<"lambda del"<<std::endl;
        delete [] p;
    };

    ZZG::UniquePtr<int, decltype(&del)> a(new int(10), del);
    std::cout<<"a = "<<*a<<std::endl;

    a.reset(new int(999));
    std::cout<<"a = "<<*a<<std::endl;

    *a = 1000;
    std::cout<<"a = "<<*a<<std::endl;

    ZZG::UniquePtr<int, decltype(lambda)> b(new int(10), lambda);


    ZZG::UniquePtr<int, decltype(&del)> c(new int(250), del);

    a = std::move(c);

    return 0;
}