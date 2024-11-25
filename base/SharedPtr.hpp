#pragma once

#include <memory>
#include <atomic>
#include <functional>

#include "EnableSharedFromThis.hpp"

namespace ZZG
{


template <typename T>
struct IsEnableSharedFromThis : std::is_base_of<EnableSharedFromThis<T>, T> {};


template <typename T>
class WeakPtr;

template <typename T>
class SharedPtr
{
public:
    using Deleter = std::function<void (T *)>;

public:
    //强弱引用计数的数量
    struct SharedInfo
    {
        std::atomic_int64_t strongCount;
        std::atomic_int64_t weekCount;
        Deleter del;
        T * data;
        SharedInfo(T* p, Deleter d = std::default_delete<T>()) :
            strongCount(1),
            weekCount(0),
            del(d),
            data(p)
        {}


    };

public:
    SharedPtr() :
        info_(new SharedInfo(nullptr))
    {}

    SharedPtr(T * data) :
        info_(new SharedInfo(data))
    {
        setupEnableSharedFromThis();
    }

    SharedPtr(T * data, Deleter del) :
        info_(new SharedInfo(data, del))
    {
        setupEnableSharedFromThis();
    }

    SharedPtr(const SharedPtr& other) :
        info_(other.info_)
    {
        ++info_->strongCount;
        setupEnableSharedFromThis();
    }

    SharedPtr(SharedPtr&& other) :
        info_(other.info_)
    {
        other.info_ = nullptr;
        setupEnableSharedFromThis();
    }

    SharedPtr& operator=(const SharedPtr& other)
    {
        if (this != &other)
        {
            reset();
            info_ = other.info_;
            ++info_->strongCount; // 增加新对象的强引用计数

            setupEnableSharedFromThis();
        }
        

        return *this;
    }

    SharedPtr& operator=(SharedPtr&& other)
    {
        if (this != &other)
        {
            reset();
            info_ = other.info_;

            other.info_ = nullptr;

            setupEnableSharedFromThis();
        }
        return *this;
    }

    void reset()
    {
        if (info_)
        {
            if (--info_->strongCount == 0) // 减少强引用计数
            {
                if (info_->data)
                {
                    info_->del(info_->data); // 释放资源
                    info_->data = nullptr;
                }

                if (info_->weekCount == 0 ) // 如果弱引用也为 0，删除控制块
                {
                    delete info_;
                    info_ = nullptr;
                }
            }
        }
    }



    void reset(T * data)
    {
        Deleter del = info_->del;
        reset();
        info_ = new SharedInfo(data, del);
    }

    T * get()
    {
        return info_->data ;
    }


    T* operator->()
    {
        return info_->data;
    }

    T& operator*()
    {
        return *info_->data;
    }

    operator bool() const
    {
        return info_->data ? true : false;
    }

    int64_t useCount() const
    {
        return info_->strongCount;
    }
    
    int64_t weekCount() const
    {
        return info_->weekCount;
    }

    ~SharedPtr()
    {
        reset();
    }


private:
    SharedPtr(SharedInfo *info) :
        info_(info)
    {}

    // 检查是否继承自 EnableSharedFromThis 并设置弱引用
    void setupEnableSharedFromThis() 
    {
        if constexpr (std::is_base_of<EnableSharedFromThis<T>, T>::value) 
        {
            if (info_ && info_->data) {
                static_cast<EnableSharedFromThis<T>*>(info_->data)->setOwner(*this);
            }
        }
    }

private:
    friend class WeakPtr<T>;
    SharedInfo *info_;
};




 
}