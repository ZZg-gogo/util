#include <iostream>

#include "../learn_template/move_enable_if.hpp"

int main()
{

    int a = 10;
    int &b = a;
    const int& c = a;

    MyTemplate::fun(a);

    MyTemplate::test(a);
    MyTemplate::test(b);
    MyTemplate::test(c);
    MyTemplate::test(20);

    //enable_if
    MyTemplate::foo<char>();
    MyTemplate::foo<int>();
    //ERROR  MyTemplate::foo<double>();

    return 0;
}