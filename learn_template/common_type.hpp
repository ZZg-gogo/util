#pragma once

#include <type_traits>

namespace MyTemplate
{


template <typename T1, typename T2>
struct common_type
{
    using type = decltype(true ? std::declval<T1>() : std::declval<T2>());
};

template <typename T>
struct common_type <T, T>
{
    using type = T;
};

template <typename T1, typename T2>
using common_type_t = typename common_type<T1, T2>::type;


}