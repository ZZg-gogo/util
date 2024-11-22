#pragma once

#include <memory>
#include "NoCopyAble.hpp"

namespace ZZG
{

template <typename T, typename Deleter = std::default_delete<T>>
class UniquePtr : NoCopyAble
{
public:
    UniquePtr() : 
        obj_(nullptr),
        del_(Deleter())
    {}


    UniquePtr(T * obj) : 
        obj_(obj),
        del_(Deleter())
    {}

    UniquePtr(T * obj, Deleter del) : 
    obj_(obj),
    del_(del)
    {}

    UniquePtr(UniquePtr&& other) :
        obj_(other.obj_),
        del_(std::move(other.del_))
    {
        other.obj_ = nullptr;
    }

    UniquePtr& operator=(UniquePtr&& other)
    {
        if (&other != this)
        {
            reset(nullptr);
            obj_ = other.obj_;
            del_ = std::move(other.del_);
            other.obj_ = nullptr;
        }
        

        return *this;
    }

    ~UniquePtr()
    {
        reset(nullptr);
    }

    T* release()
    {

        T* o = obj_;
        obj_ = nullptr;

        return o;
    }

    void reset(T * obj)
    {
        if (obj_)
        {
            del_(obj_);
        }
        
        obj_ = obj;
    }

    T* get()
    {
        return obj_;
    }

    T& operator *()
    {
        return *obj_;
    }

    T* operator ->()
    {
        return obj_;
    }

    explicit operator bool() const
    {
        return nullptr != obj_;
    }

    void swap(UniquePtr& b)
    {
        std::swap(b.del_, del_);
        std::swap(b.obj_, obj_);
    }

private:
    T * obj_;       //被管理的对象
    Deleter del_;   //对象删除器
};


}