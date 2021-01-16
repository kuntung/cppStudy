//
// Created by tangkun on 2021/1/16.
//

#ifndef CPPSTUDY_MANAGER_H
#define CPPSTUDY_MANAGER_H
#include<iostream>
#include"identity.h"

using namespace std;

class Manager:public Identity{
public:
    explicit Manager(); //Ĭ�Ϲ���
    explicit Manager(string name, string pwd); //�вι���

    //�˵�����
    virtual void openMenu();

    void addPerson(); //����˺�
    void showPerson(); //�鿴�˺�
    void showComputer(); //�鿴������Ϣ
    void cleanFile(); //���ԤԼ��¼

};
#endif //CPPSTUDY_MANAGER_H
