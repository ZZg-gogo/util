#pragma once

#include "NoCopyAble.hpp"

namespace ZZG
{



template <typename T>
class Singleton : public NoCopyAble
{

public:
    Singleton() = default;
    ~Singleton() = default;

    T& getInstance()
    {
        static T instance;
        return instance;
    }

private:
    
};




}