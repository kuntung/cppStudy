//
// Created by tangkun on 2021/1/18.
//

#ifndef CPPSTUDY_COMPUTER_H
#define CPPSTUDY_COMPUTER_H
#include<iostream>

using namespace std;

class Computer{
public:
    explicit Computer(); //Ĭ�Ϲ��캯��
    explicit Computer(string name, int size); //�вι��캯��

    //����==���������Ϊ�����Զ����������ͣ�find�ʼ��֪����ν��бȽ�
    bool operator==(const string & name) const{
        if(this->m_name == name){
            return true;
        }
        else{
            return false;
        }
    }
    //computer��������
    string m_name;
    int m_size;

};
#endif //CPPSTUDY_COMPUTER_H
