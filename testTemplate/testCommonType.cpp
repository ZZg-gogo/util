#include <iostream>

#include "../learn_template/common_type.hpp"

int main()
{

    MyTemplate::common_type<int, double>::type  i;

    std::cout<<typeid(i).name()<<std::endl;


    MyTemplate::common_type<double, float>::type  j;

    std::cout<<typeid(j).name()<<std::endl;


    MyTemplate::common_type<int, char>::type  k;

    std::cout<<typeid(k).name()<<std::endl;


    MyTemplate::common_type<int, int>::type  l;

    std::cout<<typeid(l).name()<<std::endl;

    MyTemplate::common_type_t<double, char> h;

    return 0;
}