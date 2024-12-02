#pragma once

#include <iostream>
#include <utility>

namespace MyTemplate
{


/*void fun(int a)
{
    std::cout<<"void fun(int a)"<<'\n';
}*/

void fun(int &a)
{
    std::cout<<"void fun(int &a)"<<'\n';
}


void fun(int &&a)
{
    std::cout<<"void fun(int &&a)"<<'\n';
}
/*
void fun(const int a)
{
    std::cout<<"void fun(const int a)"<<'\n';
}*/

void fun(const int& a)
{
    std::cout<<"void fun(const int& a)"<<'\n';
}

template <typename T>
void test(T && v)
{
    fun(std::forward<T>(v));
}



template <typename T>
typename std::enable_if<(sizeof(T)<= 4), void>::type
foo()
{
    std::cout<<"sizeof(T) = "<<sizeof(T)<<'\n';
}
















}