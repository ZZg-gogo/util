#include <iostream>

#include "../base/Optional.hpp"


ZZG::Optianal<int> Div(int num1, int num2)
{
    if (num2 == 0)
    {
        return ZZG::nullopt;
    }
    
    return num1/num2;
}

int main()
{
    auto opt = Div(10, 0);

    if (opt.hasValue())
    {
        std::cout<<"value is "<<opt.value()<<std::endl;
    }
    else
    {
        std::cout<<"div 0"<<std::endl;
    }

    
    ZZG::Optianal<int> a(50);
    std::cout<<"a value is "<<a.value()<<std::endl;

    opt.swap(a);
    if (opt.hasValue())
    {
        std::cout<<"value is "<<opt.value()<<std::endl;
    }
    else
    {
        std::cout<<"div 0"<<std::endl;
    }

    opt.emplace(100);
    std::cout<<"value is "<<opt.value()<<std::endl;

    opt.reset();
    if (opt.hasValue())
    {
        std::cout<<"value is "<<opt.value()<<std::endl;
    }
    else
    {
        std::cout<<"div 0"<<std::endl;
    }

    return 0;
}