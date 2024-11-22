#include <iostream>
#include "../base/Timer.hpp"



int main(int argc, char **argv)
{
    ZZG::Timer t;
    ZZG::AutoTimer at(std::cout);

    int n = 50000000;
    while (--n)
    {
        
    }
    
    std::cout<<"time is "<<t.elapsed()<<std::endl;

    return 0;
}