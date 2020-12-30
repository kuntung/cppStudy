//1. 解决方式1：直接包含.cpp源文件
#include "person.hpp"
//2. 解决方式2：将声明和实现写到同一个文件中，并更改后缀名为.hpp , hpp是约定的名称，并不是强制

void test01(){
    Person<string, int> p("tom", 18);

    p.show_info();
}

int main(){
    test01();


    return 0;
}
