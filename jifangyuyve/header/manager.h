//
// Created by tangkun on 2021/1/16.
//

#ifndef CPPSTUDY_MANAGER_H
#define CPPSTUDY_MANAGER_H
#include<iostream>
#include"identity.h"
#include"globalFile.h"
#include<vector>
#include"student.h"
#include"teacher.h"
#include "computer.h"
#include<fstream>
#include<algorithm>

using namespace std;

class Manager:public Identity{
public:
    explicit Manager(); //默认构造
    explicit Manager(string name, string pwd); //有参构造

    //菜单界面
    virtual void openMenu();
    void clientMenu();
    void computerMenu();

    //功能函数
    void initVector(); //初始化容器
    bool checkRepeat(int id, int type); //去重函数封装
    bool checkRepeat(const string& name); //重载的去重函数，用来判断机房名字是否重复
    void clientAction(); //账号管理接口
    void computerAction(); //机房管理接口

    void addPerson(); //添加账号
    void showPerson(); //查看账号
    void showComputer(); //查看机房信息
    void manageComputer(); //修改机房信息
    void addComputerRoom(); //添加机房信息
    void editComputerRoom(); //修改机房信息
    void cleanFile(const string & filename); //清空预约记录
    void editFile(int type); //修改文件
    void editClient(int type); //修改学生和教师账户信息
    //容器
    vector<Student> vStu;
    vector<Teacher> vTea;
    vector<Computer> vCom;


};
#endif //CPPSTUDY_MANAGER_H
