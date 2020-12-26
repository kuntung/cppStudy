//创建一个基类，用于定义职工最基本的属性、方法
// Created by tangkun on 2020/12/25.
//

#ifndef CPPSTUDY_WORKER_H
#define CPPSTUDY_WORKER_H
#include<iostream>
#include<string>

using namespace std;

class Worker{
public:
    //显示个人信息
    virtual void show_info() = 0; //纯虚函数
    //获取岗位名称
    virtual string get_deptName() = 0;

    virtual string get_workType() = 0;
    int m_id; //职工编号
    string m_name; //职工姓名
    int m_DeptId; //职工所在部门名称编号
 };
#endif //CPPSTUDY_WORKER_H
