//
// Created by tangkun on 2021/1/16.
//

#ifndef CPPSTUDY_TEACHER_H
#define CPPSTUDY_TEACHER_H

#include<iostream>
#include"identity.h"

using namespace std;

class Teacher : public Identity {
public:
    explicit Teacher(); //默认构造
    explicit Teacher(int empId, string name, string pwd); //有参构造

    //展示菜单
    virtual void openMenu();

    //教师功能
    void showAllOrder(); //查看所有预约
    void validOrder(); //审核预约

    //教师属性
    int m_empId;
};

#endif //CPPSTUDY_TEACHER_H
