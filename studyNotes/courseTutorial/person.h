//
// Created by tangkun on 2020/12/30.
//

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
#endif //CPPSTUDY_PERSON_H
