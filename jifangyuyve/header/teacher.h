//
// Created by tangkun on 2021/1/16.
//

#ifndef CPPSTUDY_TEACHER_H
#define CPPSTUDY_TEACHER_H

#include<iostream>
#include"identity.h"
#include"orderFile.h"
#include"student.h"
#include<vector>

using namespace std;

class Teacher : public Identity {
public:
    explicit Teacher(); //Ĭ�Ϲ���
    explicit Teacher(int empId, string name, string pwd); //�вι���

    //����==�����
    bool operator==(const int & id) const{
        if(this->m_empId == id){
            return true;
        }
        else{
            return false;
        }
    }
    //չʾ�˵�
    virtual void openMenu();

    //��ʦ����
    void showAllOrder(); //�鿴����ԤԼ
    void validOrder(); //���ԤԼ

    //��ʦ����
    int m_empId;
};

#endif //CPPSTUDY_TEACHER_H
