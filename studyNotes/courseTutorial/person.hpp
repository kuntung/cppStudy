#ifndef CPPSTUDY_PERSON_H
#define CPPSTUDY_PERSON_H
#include<iostream>
#include<string>

using namespace std;

template<class T1, class T2>
class Person{
public:
    Person(T1 name, T2 age);

    void show_info();
    T1 m_name;
    T2 m_age;
};

//类模板声明定义
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
    this->m_name = name;
    this->m_age = age;
}

template<class T1, class T2>
void Person<T1, T2>:: show_info()
{
    cout<<"name："<< this->m_name <<"age:"<<this->m_age;

}
#endif //CPPSTUDY_PERSON_H