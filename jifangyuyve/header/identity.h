//
// Created by tangkun on 2021/1/16.
//

#ifndef CPPSTUDY_IDENTITY_H
#define CPPSTUDY_IDENTITY_H
#include<iostream>

using namespace std;

class Identity{//��ݳ������
public:
    virtual void openMenu()=0; //�����˵������麯��������Ҫ�ṩ����ʵ��

    //�û���
    string m_name;
    string m_pwd;
};
#endif //CPPSTUDY_IDENTITY_H
