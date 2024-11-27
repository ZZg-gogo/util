#pragma once

#include <iostream>
#include <string>
#include <sstream>

namespace ZZG
{


class Format
{

public:
    Format(const std::string& str) :
        index_(0), 
        needFormatCount_(0),
        formatCount_(0),
        format_(str)
    {
        init();
    }

    Format(const char *p) :
        index_(0),
        needFormatCount_(0),
        formatCount_(0),
        format_(p)
    {
        init();
    }

    template <typename T>
    Format& operator%(const T& obj)
    {
        while (index_ < format_.length())
        {
            if (format_[index_] == '%' && (index_+1) < format_.length() && format_[index_+1] != '%')
            {
                index_++;
                char c = format_[index_];
                
                std::stringstream ss;
                ss << obj;
                output_ += ss.str();
               
                index_++;


                formatCount_++;

                if (formatCount_ == needFormatCount_)
                {
                    output_ += format_.substr(index_, format_.size()-1);
                }
                

                break;
            }
            else
            {
                output_ += format_[index_];
                index_++;
            }
            
            
        }
        

        return *this;
    }


    friend std::ostream& operator<<(std::ostream& os, const Format& f)
    {
        os << f.output_;

        return os;
    }

    ~Format() =default;

private:
    void init()
    {
        bool flag = false;
        int i = 0;
        while (i < format_.length())
        {
            if (format_[i] == '%' && (i+1) < format_.length() && format_[i+1] != '%')
            {
                if (!flag)
                {
                    index_ = i;
                }
                
                flag = true;
                needFormatCount_++;
            }
            else if (!flag)
            {
                output_ += format_[i];
                
            }
            i++;
        }
    }

private:
    int index_;
    int needFormatCount_;
    int formatCount_;
    std::string format_;

    std::string output_;
};





}