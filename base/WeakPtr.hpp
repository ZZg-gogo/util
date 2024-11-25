#pragma once

#include "SharedPtr.hpp"

namespace ZZG
{

template <typename T>
class WeakPtr
{
public:
    using SharedInfo = typename SharedPtr<T>::SharedInfo ;
public:
    WeakPtr(const SharedPtr<T>& s) :
        info_(s.info_)
    {
        ++info_->weekCount;
    }

    WeakPtr(const WeakPtr& w) :
         info_(w.info_)
    {
        ++info_->weekCount;
    }

    SharedPtr<T> lock()
    {
        if (info_ && info_->strongCount > 0)
        {
            ++info_->strongCount;
            return SharedPtr<T>(info_);
        }

        return SharedPtr<T>();
    }


    int64_t useCount() const
    {
        return info_->strongCount;
    }
    
    int64_t weekCount() const
    {
        return info_->weekCount;
    }

    bool expired()
    {
        return info_->strongCount ? false : true;
    }


    void reset()
    {
        if (info_)
        {
            if (0 == --info_->weekCount  && 0 == info_->strongCount)
            {
                delete info_;
                info_ = nullptr;
            }
            
        }

        info_ = nullptr;
    }

    ~WeakPtr()
    {
        reset();
    }

private:
    SharedInfo * info_;
};


}