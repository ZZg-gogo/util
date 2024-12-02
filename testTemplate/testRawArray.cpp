#include <iostream>

#include "../learn_template/raw_array.hpp"


int main()
{
    int a[] = {1,2,3,4,5};
    int b[] = {4,5};
    const int c[] = {1,2,3,4,5};
    MyTemplate::less(a, b);

    MyTemplate::test(a);
    MyTemplate::test(&a[0]);
    return 0;
}