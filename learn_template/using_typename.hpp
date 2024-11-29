#pragma once

#include <vector>

namespace MyTemplate
{



template <typename T>
class MyClass
{
public:
    using type = T;
    using storeType = std::vector<T>;

    MyClass(const char *)
    {

    }
    void show()
    {
        std::cout<<typeid(value_).name()<<std::endl;
    }

    T value_;
};

template <typename T>
using MyclassType = typename MyClass<T>::type;

template <typename T>
using MyclassStoreType = typename MyClass<T>::storeType;

//推断指引
template <typename T>
MyClass(const char *) -> MyClass<std::string>;




//对模板参数进行约束
template <typename T>
concept ClassNeedInt = std::is_integral<T>::value;

template <typename T>  requires ClassNeedInt<T>
class Test  
{
public:

private:
    T value_;
};

}