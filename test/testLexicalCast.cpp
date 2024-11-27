#include <iostream>
#include <string>
#include "../base/LexicalCast.hpp"


class Person
{
public:
    Person() :
        name_("zzh"),
        age_(-1)
    {}

    Person(const std::string& str, int age) :
        name_(str),
        age_(age)
    {}

    friend std::ostream& operator<<(std::ostream& os, const Person& p)
    {
        os << p.name_ << " " << p.age_;  // 使用空格作为分隔符
        return os;
    }

    // 重载 >> 操作符，用于从流中读取数据到 Person
    friend std::istream& operator>>(std::istream& is, Person& p) 
    {
        is>>p.name_>>p.age_;
        return is;
    }


    std::string name_;
    int age_;

};



int main()
{


    std::string st("zzh 100");

    std::stringstream ss(st);

    std::string str1;
    ss>>str1; 
    std::cout<<"str1 = "<<str1<<std::endl;

    auto i = ZZG::LexicalCast<int>("123456");

    std::string str("123456");
    ZZG::LexicalCast<int>(str);

    std::cout<<i<<std::endl;


    auto s = ZZG::LexicalCast<std::string>(Person{"zzh", 100});

    std::cout<<s<<std::endl;


    auto p = ZZG::LexicalCast<Person>(s);

    std::cout<<"name = "<<p.name_<<"  age ="<<p.age_<<std::endl;

    return 0;
}