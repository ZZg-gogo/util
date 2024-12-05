#pragma once


#include <utility>

namespace MyTemplate
{

template <typename T>
struct IsPointer
{
    static constexpr bool value = false;
};


template <typename T>
struct IsPointer<T *>
{
    static constexpr bool value = true;
};


template <typename T>
struct IsPointer<const T *>
{
    static constexpr bool value = true;
};


template <typename T>
struct IsPointer<const volatile T *>
{
    static constexpr bool value = true;
};

template <typename T>
struct MyAddTraits
{
    using Type = T;
};

template <>
struct MyAddTraits<char>
{
    using Type = int;
};


template <>
struct MyAddTraits<short>
{
    using Type = int;
};

template <>
struct MyAddTraits<float>
{
    using Type = double;
};



template <typename T>
auto MyAdd(T* start, T *end)
{
    using Type = typename MyAddTraits<T>::Type;

    Type sum{};

    while (start != end)
    {
        sum += *start;
        ++start;
    }
    

    return sum;
}



template <typename T>
struct IsConst
{
    static constexpr bool value = false;
};


template <typename T>
struct IsConst<const T>
{
    static constexpr bool value = true;
};


template <typename T>
struct RemoveReferenceT
{
    using type = T;
};

template <typename T>
struct RemoveReferenceT<T&>
{
    using type = T;
};

template <typename T>
struct RemoveReferenceT<T&&>
{
    using type = T;
};

template <typename T>
using RemoveReference = typename RemoveReferenceT<T>::type;

template <typename T>
struct RemoveConstT
{
    using type = T;
};

template <typename T>
struct RemoveConstT<const T>
{
    using type = T;
};

template <typename T>
struct RemoveConstT<const volatile T>
{
    using type = T;
};

template <typename T>
struct RemoveConstT<const T&>
{
    using type = T&;
};

/*
template <typename T>
struct RemoveConstT<const T&>
{
    using type = T;
};


template <typename T>
struct RemoveConstT<const volatile T&>
{
    using type = T;
};*/

template <typename T>
using RemoveConst = typename RemoveConstT<T>::type;


template<typename T>
struct RemoveCRT : RemoveConstT<typename RemoveReferenceT<T>::type>
{
};

template <typename T>
using RemoveCR = RemoveReference<RemoveConst<T>>;


template<typename T>
struct DecayT : RemoveCRT<T>
{

};

template <typename R, typename... Args>
struct DecayT<R(Args...)>
{
    using type = R(*)(Args...);
};

//处理C语言中的可变参数
template <typename R, typename... Args>
struct DecayT<R(Args..., ...)>
{
    using type = R(*)(Args..., ...);
};

template <typename T>
using Decay = DecayT<T>::type;


template <typename T1, typename T2>
struct IsSameT
{
    static const constexpr bool value = false;
};


template <typename T>
struct IsSameT<T, T>
{
    static const constexpr bool value = true;
};

template <typename T1, typename T2>
constexpr bool IsSame = IsSameT<T1, T2>::value;


//判断某一个类型是否有默认构造函数
template <typename T>
struct IsDefaultConstructibleT
{

    template<typename U, typename = decltype(U())>
    static constexpr bool test(void *)
    {
        return true;
    }

    template<typename U>
    static constexpr bool  test(...)
    {
        return false;
    }

    static constexpr bool value = test<T>(nullptr);
};


//判断两个类型是否能够互相转换
template <typename FROM, typename TO>
struct IsConvertHelp 
{
    static void aux(TO) {}

    template <typename F, typename T, typename = decltype(aux(std::declval<F>()))>
    static std::true_type test(void *) 
    {
        return std::true_type{};
    }

    template <typename F, typename T>
    static std::false_type test(...) 
    {
        return std::false_type{};
    }

    using Type = decltype(test<FROM, TO>(nullptr));
};

template <typename ...>
using VoidT = void;

//是否有size_type 这个类型
template <typename, typename = VoidT<>>
struct HasSizeTypeT : std::false_type
{
    
};

template <typename T>
struct HasSizeTypeT<T, VoidT<typename T::size_type>> : std::true_type
{
    
};










}
