#pragma once

#include <iostream>

namespace MyTemplate
{

/*template <typename T, std::size_t N>
auto test(T (&a)[N])
{
    std::cout <<"N = "<< N <<"  "<< typeid(a).name() << std::endl;
}

template <typename T>
auto test(const T *a)
{
    std::cout <<"T *a = "<< a <<"  "<< typeid(a).name() << std::endl;
}*/


template <typename T, std::size_t N>
auto test(T a[N])
{
    std::cout <<"T [N] = "<< N <<"  "<< typeid(a).name() << std::endl;
}

template <typename T>
auto test(T a[])
{
    std::cout <<"T a[]"<<"  "<< typeid(a).name() << std::endl;
}


template <typename T, int N, int M>
bool less(T (&a)[N], T (&b)[M])
{
    std::cout <<"N = "<< N <<"  "<<"M = "<< M << std::endl;
    for (int i = 0; i < N && i < M; ++i)
    {
        if (a[i] < b[i])
            return true;
        if (b[i] < a[i])
            return false;
    }

    return N < M;
}

}