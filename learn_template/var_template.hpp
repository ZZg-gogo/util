#pragma once

#include <iostream>

namespace MyTemplate
{

//递归出口
void MyPrint()
{

}

template <typename T , typename... TYPES>
void MyPrint(T firstArg, TYPES... args)
{
    std::cout<<firstArg<<'\n';
    MyPrint(args...);
}



template <typename T>
T MyAdd(T v)
{
    return v;
}


template <typename T, typename... TYPES>
T MyAdd(T firstArg, TYPES... args)
{
    return firstArg + MyAdd(args...);
}


//sizeof...
template <typename T, typename... TYPES>
void MySize(T firstArg, TYPES... args)
{
    std::cout<<firstArg<<'\n';

    std::cout<<"sizeof...(TYPES) = "<<sizeof...(TYPES)<<'\n';
    std::cout<<"sizeof...(args) = "<<sizeof...(args)<<'\n';
}


template<typename... Args>
auto MyAdd1(Args... args)
{
    return (args + ...);
}


}