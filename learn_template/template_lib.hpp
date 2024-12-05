#pragma once

#include <functional>

namespace MyTemplate
{


template <typename Begin, typename End, typename Callback>
void MyForEach(Begin start, End end, Callback cb)
{

    for (; end != start; ++start)
    {
        cb(*start);
    }
}


template <typename Iter, typename Callback, typename... Args>
void MyForEach(Iter start, Iter end, Callback cb, Args... args)
{

    for (; end != start; ++start)
    {
        std::invoke(cb, args..., *start);
    }
}



}