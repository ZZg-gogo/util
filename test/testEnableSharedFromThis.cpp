#include <iostream>


#include "../base/SharedPtr.hpp"


class Test : public ZZG::EnableSharedFromThis<Test>
{


};


int main()
{

    ZZG::SharedPtr<Test> t(new Test, [](Test*){
        std::cout<<"删除了"<<std::endl;
    });

    std::cout<<"useCount  "<<t.useCount()<<"  p = "<<t.get()<<std::endl;

    ZZG::SharedPtr<Test> a = t->sharedFromThis();
    std::cout<<"useCount   "<<t.useCount()<<"  p = "<<a.get()<<std::endl;

    
    return 0;
}