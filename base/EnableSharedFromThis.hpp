#pragma once

#include "WeakPtr.hpp"

namespace ZZG
{


template <typename T>
class EnableSharedFromThis
{

public:
    EnableSharedFromThis() = default;
    virtual ~EnableSharedFromThis() = default;


    SharedPtr<T> sharedFromThis()
    {
        if (!weak_.expired())
        {
            return weak_.lock();
        }
        
        return SharedPtr<T>();
    }

public:
    void setOwner(const SharedPtr<T> & other)
    {
        if (weak_.expired())
        {
            weak_ = other;
        }
        
    }

private:
    WeakPtr<T> weak_;
};







}