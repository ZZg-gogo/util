#pragma once


#include <iostream>

namespace MyTemplate
{

template <typename T>
class MyClass
{
public:
    MyClass() : 
        value_()
    {}

    MyClass(const T& v) :
        value_(v)
    {}


    friend void test(const MyClass<T>& obj)
    {
        std::cout << "call" << std::endl;
    }

    //当在类里面进行友元声明的时候
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const MyClass<U>& obj);

    //直接在类里面进行定义的时候 则不用
    /*
    friend std::ostream& operator<< (std::ostream& os, const MyClass<T>& obj)
    {
        os << obj.value_;
        return os;
    }
    */
private:
    T value_;
};


//必须用一个不同于模板参数的类型
template <typename U>
std::ostream& operator<< (std::ostream& os, const MyClass<U>& obj)
{
    os << obj.value_;
    return os;
}





}