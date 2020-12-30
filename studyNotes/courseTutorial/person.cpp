//
// Created by tangkun on 2020/12/30.
//

#include "person.h"

//类模板成员函数类外实现
//1. 构造函数的类外实现
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
    this->m_name = name;
    this->m_age = age;
}

//2. 成员函数的类外实现
template<class T1, class T2>
void Person<T1, T2>:: show_info()
{
    cout<<"name："<< this->m_name <<"age:"<<this->m_age;

}