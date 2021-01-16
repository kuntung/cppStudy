//
// Created by tangkun on 2021/1/16.
//

#ifndef CPPSTUDY_STUDENT_H
#define CPPSTUDY_STUDENT_H

#include<iostream>
#include"identity.h"

using namespace std;

class Student : public Identity {
public:
    //默认构造
    explicit Student(); //默认构造
    explicit Student(int id, string name, string pwd); //有参构造，参数：学号，姓名，密码

    //菜单界面
    virtual void openMenu();

    void applyOrder();    //申请预约
    void showMyOrder();    //查看自身预约
    void showAllOrder();    //查看所有预约
    void cancelOrder();    //取消预约
    //学生成员属性
    int m_id;
};

#endif //CPPSTUDY_STUDENT_H
