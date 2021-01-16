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
    //Ĭ�Ϲ���
    explicit Student(); //Ĭ�Ϲ���
    explicit Student(int id, string name, string pwd); //�вι��죬������ѧ�ţ�����������

    //�˵�����
    virtual void openMenu();

    void applyOrder();    //����ԤԼ
    void showMyOrder();    //�鿴����ԤԼ
    void showAllOrder();    //�鿴����ԤԼ
    void cancelOrder();    //ȡ��ԤԼ
    //ѧ����Ա����
    int m_id;
};

#endif //CPPSTUDY_STUDENT_H
