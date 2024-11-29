#include <iostream>

#include "../learn_template/using_typename.hpp"

int main()
{
    MyTemplate::MyclassType<int> a;

    MyTemplate::MyclassStoreType<int> b;


    MyTemplate::MyClass<const char *> d{"123"};
    d.show();
    


    b.push_back(10);


    // error MyTemplate::Test<double> c;
    MyTemplate::Test<int> c;

    return 0;
}