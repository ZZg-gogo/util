#include <iostream>
#include <vector>


#include "../learn_template/template_lib.hpp"


class CallAble
{
public:
    void operator()(int & num)
    {
        std::cout<<"CallAble num = "<<num<<"\n";
        num += 1;
    }
};

class MemberFun
{
public:
    void fun(int& num)
    {
        std::cout<<"MemberFun fun num = "<<num<<"\n";
        num += 1;
    }
};


int main(int argc, char ** argv)
{
    std::vector<int> a(10);

    for (int i = 0; i < a.size(); i++)
    {
        a[i] = i * 10;
    }
    

    auto cb = [](int & num) {
        std::cout<<"num = "<<num<<"\n";
        num += 1;
    };

    MyTemplate::MyForEach(a.begin(), a.end(), cb);

    MyTemplate::MyForEach(a.begin(), a.end(), CallAble());

    MemberFun mFun;
    MyTemplate::MyForEach(a.begin(), a.end(), &MemberFun::fun, mFun);
    

    return 0;
}