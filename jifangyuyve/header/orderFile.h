//
// Created by tangkun on 2021/1/21.
//

#ifndef CPPSTUDY_ORDERFILE_H
#define CPPSTUDY_ORDERFILE_H
#include<iostream>
#include<fstream>
#include<map>
#include"globalFile.h"
#include<string>
#include "computer.h"


using namespace std;

class OrderFile{
public:
    explicit OrderFile();

    //����ԤԼ��¼
    void updateOrder();
    pair<string, string> readOrder(const string & orderInfo); //��ȡÿһ�����ݵĺ���
    void showOrder(int i); //��ʾĳһ��ԤԼ��¼

    string getRoomName(int roomId); //���ݻ�����Ż�ȡ��������

    int m_Size;    //��¼ԤԼ����
    int m_roomCnt; //��¼��������

    //��¼����ԤԼ��Ϣ������ keyΪ��¼������value�����¼��ֵ����Ϣ
    map<int, map<string, string>> m_orderData;
    map<int, string> map_roomName; //��������


};


#endif //CPPSTUDY_ORDERFILE_H
