#pragma once


#include <iostream>
#include <sstream>

namespace ZZG
{

template <typename Target, typename Source>
Target LexicalCast(const Source& s)
{
    Target t;


    if constexpr (std::is_same<Target, std::string>::value) 
    {
        std::stringstream ss;
        ss << s;
        return ss.str();
    }

    std::stringstream ss;
    ss << s;
    ss >> t;
    if (ss.fail())
    {
         throw std::runtime_error("LexicalCast failed: invalid conversion");
    }

    return t;
};


template <typename Target>
Target LexicalCast(const std::string& s)
{
    Target t;

    std::stringstream ss(s);
    ss >> t;

    if (ss.fail())
    {
        throw std::runtime_error("LexicalCast std::string failed: invalid conversion");
    }

    return t;
};





}