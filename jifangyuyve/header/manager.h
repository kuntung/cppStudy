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
    explicit Manager(); //默认构造
    explicit Manager(string name, string pwd); //有参构造

    //菜单界面
    virtual void openMenu();

    void addPerson(); //添加账号
    void showPerson(); //查看账号
    void showComputer(); //查看机房信息
    void cleanFile(); //清空预约记录

};
#endif //CPPSTUDY_MANAGER_H
