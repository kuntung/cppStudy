//1. �����ʽ1��ֱ�Ӱ���.cppԴ�ļ�
#include "person.hpp"
//2. �����ʽ2����������ʵ��д��ͬһ���ļ��У������ĺ�׺��Ϊ.hpp , hpp��Լ�������ƣ�������ǿ��

void test01(){
    Person<string, int> p("tom", 18);

    p.show_info();
}

int main(){
    test01();


    return 0;
}
