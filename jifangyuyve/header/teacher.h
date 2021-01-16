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
    explicit Teacher(); //Ĭ�Ϲ���
    explicit Teacher(int empId, string name, string pwd); //�вι���

    //չʾ�˵�
    virtual void openMenu();

    //��ʦ����
    void showAllOrder(); //�鿴����ԤԼ
    void validOrder(); //���ԤԼ

    //��ʦ����
    int m_empId;
};

#endif //CPPSTUDY_TEACHER_H
