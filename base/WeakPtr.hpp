#pragma once



namespace ZZG
{

template <typename T>
class SharedPtr;

template <typename T>
class WeakPtr
{
public:
    using SharedInfo = typename SharedPtr<T>::SharedInfo ;
public:
    WeakPtr() :
        info_(nullptr)
    {}

    WeakPtr(const SharedPtr<T>& s) :
        info_(s.info_)
    {
        ++info_->weekCount;
    }

    WeakPtr(const WeakPtr& w) :
         info_(w.info_)
    {
        if (info_)
        {
            ++info_->weekCount;
        }
    }


    WeakPtr& operator=(const SharedPtr<T>& other)
    {
        if (info_ != other.info_)
        {
            reset();

            info_ = other.info_;

            if (info_)
            {
                ++info_->weekCount;
            }
            
        }
        

        return *this;
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
        return info_ ? info_->strongCount : 0;
    }
    
    int64_t weekCount() const
    {
        return info_ ? info_->weekCount : 0;
    }

    bool expired()
    {
        return (info_ && info_->strongCount) ? false : true;
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