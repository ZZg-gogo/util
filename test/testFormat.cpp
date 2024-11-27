#include <iostream>

#include "../base/Format.hpp"


int main()
{
    ZZG::Format f("%%%%%%%%%");

    ZZG::Format d("\thello world");


    ZZG::Format s("hello %s\n %d \t  world");
    s%"66666";
    s%"你好";


    ZZG::Format e("你好 这里是 %s市\n \t time=%s  age=%d");
    e%"深圳"%"2024年11月27日16:53:39"%18;

    std::cout<<f<<std::endl;
    std::cout<<d<<std::endl;
    std::cout<<s<<std::endl;
    std::cout<<e<<std::endl;


    e%"sdfafafafa";
    std::cout<<e<<std::endl;
    return 0;
}