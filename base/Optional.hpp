#pragma once

namespace ZZG
{

struct null_opt_t
{
    struct Tag
    {
    };

    explicit constexpr null_opt_t(Tag t) {}
};

inline constexpr null_opt_t nullopt{null_opt_t::Tag{}};

template <typename T>
class Optianal
{
public:
    // 构造函数
    Optianal() : hasValue_(false)
    {
    }

    Optianal(null_opt_t n) : hasValue_(false)
    {
    }

    Optianal(T v) : hasValue_(true),
                    value_(v)
    {
    }

    Optianal(const Optianal &other) : hasValue_(other.hasValue_),
                                        value_(other.value_)
    {
    }

    Optianal(Optianal &&other) : hasValue_(other.hasValue_),
                                    value_(std::move(other.value_))
    {
        other.hasValue_ = false;
    }

    Optianal<T> &operator=(const Optianal &other)
    {
        if (this != &other)
        {
            hasValue_ = other.hasValue_;
            value_ = other.value_;
        }

        return *this;
    }

    Optianal<T> &operator=(Optianal &&other)
    {
        if (this != &other)
        {
            hasValue_ = other.hasValue_;
            value_ = std::move(other.value_);
            other.hasValue_ = false;
        }

        return *this;
    }

    ~Optianal() = default;

    void emplace(T v)
    {
        hasValue_ = true;
        value_ = v;
    }

    void emplace(null_opt_t)
    {
        hasValue_ = false;
    }

    explicit operator bool() const
    {
        return hasValue_;
    }

    void swap(Optianal &other) noexcept
    {
        std::swap(other.hasValue_, hasValue_);
        std::swap(other.value_, value_);
    }

    void reset()
    {
        hasValue_ = false;
    }

    bool hasValue() const
    {
        return hasValue_;
    }

    T &value()
    {
        return value_;
    }

    T &operator*()
    {
        return value_;
    }

    bool operator==(const Optianal &other)
    {
        if (hasValue_ != other.hasValue_)
        {
            return false; // 一个有值，另一个没有值
        }

        if (hasValue_)
        {
            return value_ == other.value_; // 两者都有值时，比较值
        }
        
        return true; // 两者都没有值时，相等
    }

    bool operator!=(const Optianal &other)
    {
        return !(*this == other);
    }

    T valueOr()
    {
        if (hasValue_)
        {
            return value_;
        }

        return T();
    }

private:
    bool hasValue_;
    T value_;
};

}