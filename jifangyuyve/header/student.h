//
// Created by tangkun on 2021/1/16.
//

#ifndef CPPSTUDY_STUDENT_H
#define CPPSTUDY_STUDENT_H

#include<iostream>
#include"identity.h"
#include "computer.h"
#include "globalFile.h"
#include<vector>
#include<fstream>
#include"orderFile.h"

using namespace std;

class Student : public Identity {
public:
    //Ĭ�Ϲ���
    explicit Student(); //Ĭ�Ϲ���
    explicit Student(int id, string name, string pwd); //�вι��죬������ѧ�ţ�����������

    //����==�����������ʵ��find��ƥ�����
    bool operator==(const int& id) const{
        if(this->m_id == id){
            return true;
        }
        else{
            return false;
        }
    }
    //�˵�����
    virtual void openMenu();

    void applyOrder();    //����ԤԼ
    void showMyOrder();    //�鿴����ԤԼ
    void showAllOrder();    //�鿴����ԤԼ
    void cancelOrder();    //ȡ��ԤԼ
    //ѧ����Ա����
    int m_id;
    vector<Computer> svCom; //��������
};

#endif //CPPSTUDY_STUDENT_H
