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

    //更新预约记录
    void updateOrder();
    pair<string, string> readOrder(const string & orderInfo); //读取每一条数据的函数
    void showOrder(int i); //显示某一条预约记录

    string getRoomName(int roomId); //根据机房编号获取机房名字

    int m_Size;    //记录预约条数
    int m_roomCnt; //记录机房个数

    //记录所有预约信息的容器 key为记录条数，value具体记录键值对信息
    map<int, map<string, string>> m_orderData;
    map<int, string> map_roomName; //机房容器


};


#endif //CPPSTUDY_ORDERFILE_H
