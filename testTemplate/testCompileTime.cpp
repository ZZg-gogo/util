#include <iostream>

#include "../learn_template/compile_time.hpp"


int main()
{
    if ( MyTemplate::IsPrime1<10>::value)
    {
        std::cout<<"10 Is Prime1"<<'\n';
    }
    else
    {
        std::cout<<"10 Not Prime1"<<'\n';
    }

    if ( MyTemplate::IsPrime1<5>::value)
    {
        std::cout<<"5 Is Prime1"<<'\n';
    }
    else
    {
        std::cout<<"5 Not Prime1"<<'\n';
    }
    

    //constexpr bool r = MyTemplate::IsPrime3(10); 会在编译期间 就会计算为false

    if ( MyTemplate::IsPrime3(10))
    {
        std::cout<<"10 Is Prime1"<<'\n';
    }
    else
    {
        std::cout<<"10 Not Prime1"<<'\n';
    }

    if ( MyTemplate::IsPrime3(5))
    {
        std::cout<<"5 Is Prime1"<<'\n';
    }
    else
    {
        std::cout<<"5 Not Prime1"<<'\n';
    }


    //判断一下 数组大小是否是质数 根据偏特化 进行不同模板的选择
    MyTemplate::MyArray<int, 3> a;
    MyTemplate::MyArray<int, 10> b;

    return 0;
}