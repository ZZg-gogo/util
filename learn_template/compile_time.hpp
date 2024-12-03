#pragma once

#include <iostream>

namespace MyTemplate
{

template <uint64_t p, uint64_t d>
struct DoIsPrime1
{
    //从 d-d-1 进行递归
    static constexpr bool value = (p%d != 0) && DoIsPrime1<p, d-1>::value;
};


//递归出口
template <uint64_t p>
struct DoIsPrime1<p, 2>
{
    static constexpr bool value = (p%2 != 0);
};

template <uint64_t p>
struct IsPrime1
{
    static constexpr bool value = DoIsPrime1<p, p/2>::value;
};


constexpr bool IsPrime3(uint64_t p)
{
    for (uint64_t i = 2; i <= p/2; ++i)
    {
        if (p % i == 0)
        {
            return false;
        }
    }

    return true;
}


template <std::size_t SZ, bool = IsPrime3(SZ)>
struct SizeHelper
{};


template <std::size_t SZ>
struct SizeHelper<SZ, true>
{
    SizeHelper()
    {
        std::cout<<"SizeHelper<SZ, true>"<<'\n';
    }
};

template <std::size_t SZ>
struct SizeHelper<SZ, false>
{
    SizeHelper()
    {
        std::cout<<"SizeHelper<SZ, false>"<<'\n';
    }
};

//判断一下 数组大小是否是质数
template <typename T, std::size_t SZ>
class MyArray
{
public:
    SizeHelper<SZ> helper_;
};



}