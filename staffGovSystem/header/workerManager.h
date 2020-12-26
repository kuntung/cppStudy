//
// Created by tangkun on 2020/12/25.
//

#ifndef CPPSTUDY_WORKERMANAGER_H
#define CPPSTUDY_WORKERMANAGER_H
#include<iostream>
#include "header/worker.h"
using namespace std;

class WorkerManager{
public:
    WorkerManager();//构造函数
    ~WorkerManager();//析构函数
    void show_menu(); //显示界面
    void exit_system(); //退出系统
    void add_Emp();//添加职工
    int m_EmpNum; //记录文件中的人数个数
    Worker ** m_EmpArray; //员工数组的指针

};
#endif //CPPSTUDY_WORKERMANAGER_H
