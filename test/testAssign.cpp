#include <iostream>
#include <list>
#include "../base/Assign.hpp"

int main()
{

    using namespace ZZG::ASSIGN;


    std::list<int> l;

    l += 1,2,3,4,5;

    push_back(l)(7)(8)(9);

    std::cout<<"size = "<<l.size()<<std::endl;



    std::vector<int> v;
    v += 10,9,8,7,6,5;

    for (auto &i: v)
    {
        std::cout<<"num = "<<i<<std::endl;
    }
    

    return 0;
}