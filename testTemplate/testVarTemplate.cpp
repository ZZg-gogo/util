#include <iostream>

#include "../learn_template/var_template.hpp"

int main()
{
    MyTemplate::MyPrint(10, 10.36, "asdadada");


    std::cout<<"ret = "<<MyTemplate::MyAdd(10, 20 , 30)<<'\n';


    std::string a("Hello ");
    std::string b("World");
    std::string c("!");

    std::cout<<"ret = "<<MyTemplate::MyAdd(a, b , c)<<'\n';


    MyTemplate::MySize(666, 777, 888, 999);



    // ERROR 右折叠 auto r = MyTemplate::MyAdd1(std::string{"111"}, "2222", "3333");
    auto r = MyTemplate::MyAdd1("2222", "3333", std::string{"111"});
    std::cout<<"MyAdd1 ret = "<<r<<'\n';
    return 0;
}