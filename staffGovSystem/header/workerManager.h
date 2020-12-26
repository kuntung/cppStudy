//
// Created by tangkun on 2020/12/25.
//

#ifndef CPPSTUDY_WORKERMANAGER_H
#define CPPSTUDY_WORKERMANAGER_H
#include<iostream>
#include "header/worker.h"
#include "header/employee.h"
#include "header/boss.h"
#include "header/manager.h"
#include <fstream>

#define FILENAME "workerFile.txt"

using namespace std;

class WorkerManager{
public:
    WorkerManager();//构造函数
    ~WorkerManager();//析构函数
    void show_menu(); //显示界面
    void exit_system(); //退出系统
    void add_Emp();//添加职工
    void save(); //保存文件
    int get_EmpNum(); //统计已有职工人数
    void init_Emp(); //初始化员工
    void show_Emp(); //显示员工信息
    void del_Emp(int id); //根据职工编号删除员工
    void del_Emp(string name); //重载函数，根据姓名删除员工
    int IsExit(int id); //判断某位员工是否存在，如果存在则返回其在数组中的位置，不存在则返回-1
    int IsExit(string name); //判断某位员工是否存在，如果存在则返回其在数组中的位置，不存在则返回-1



    int m_EmpNum; //记录文件中的人数个数
    Worker ** m_EmpArray; //员工数组的指针,指向worker父类的指针的指针
    bool m_FileIsEmpty; //标志文件是否为空



};
#endif //CPPSTUDY_WORKERMANAGER_H
