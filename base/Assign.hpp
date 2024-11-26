#pragma once

#include <utility>
#include <list>
#include <vector>


namespace ZZG
{

namespace ASSIGN
{



template <typename C>
class call_push_back
{
public:
    call_push_back(C& c) :
        c_(c)
    {}

    template <typename T>
    void operator()(T& obj)
    {
        c_.push_back(obj);
    }

    template <typename T>
    void operator()(T&& obj)
    {
        c_.push_back(std::forward<T>(obj));
    }

private:
    C& c_;
};


template <typename C>
class call_insert
{
public:
    call_insert(C& c) :
        c_(c)
    {}

    template <typename T>
    void operator()(T& obj)
    {
        c_.insert(obj);
    }

    template <typename T>
    void operator()(T&& obj)
    {
        c_.insert(std::forward<T>(obj));
    }

private:
    C& c_;
};


struct ForwardNullArguments{};



template <typename Function, typename Argument = ForwardNullArguments>
class ListInserter
{
public:
    ListInserter(Function fun) :
        insert_(fun)
    {}

    ListInserter& operator() (Argument& arg)
    {
        insert_(arg);
        return *this;
    }

    ListInserter& operator() (Argument&& arg)
    {
        insert_(std::move(arg));
        return *this;
    }


    ListInserter& operator() ()
    {
        insert_(Argument());
        return *this;
    }

    ListInserter& operator,(Argument& arg)
    {
        insert_(arg);
        return *this;
    }

    ListInserter& operator,(Argument&& arg)
    {
        insert_(std::move(arg));
        return *this;
    }


    ~ListInserter()=default;
private:
    Function insert_;
};


template <typename Function, typename Argument>
inline ListInserter<Function, Argument> 
MakeInserter(Function f, Argument* arg)
{
    return ListInserter<Function, Argument>{f};
}

template <typename C>
inline ListInserter<call_push_back<C>, typename C::value_type> 
push_back(C& c)
{
    typename C::value_type * p = nullptr;
    return MakeInserter(call_push_back<C>(c), p);
}




/****************************TODO********************************************/
template< class V, class A, class V2 >
inline ListInserter< call_push_back< std::list<V,A> >, V >
operator+=( std::list<V,A>& c, V2 v )
{
    return push_back<std::list<V,A>>(c)( v );
}


template< class V, class A, class V2 >
inline ListInserter< call_push_back< std::list<V,A> >, V >
operator+=( std::vector<V,A>& c, V2 v )
{
    return push_back<std::vector<V,A>>(c)( v );
}


}//end namespace ASSIGN


}//end namespace ZZG