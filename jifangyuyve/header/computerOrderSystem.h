//
// Created by tangkun on 2021/1/16.
//

#ifndef CPPSTUDY_COMPUTERORDERSYSTEM_H
#define CPPSTUDY_COMPUTERORDERSYSTEM_H
#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>
#include <header/teacher.h>
#include <header/manager.h>
#include "header/student.h"
#include"header/identity.h"
#include"header/globalFile.h"

class OrderManager{
public:
    explicit OrderManager(); //构造函数

    //初始化功能
    void init();
    //菜单功能
    static void show_menu();
    void managerMenu(Identity *&manager);    //管理员子菜单
    void tearcherMenu(Identity *&teacher); //教师子菜单
    void studentMenu(Identity *&student); //学生子菜单
    void managerClientMenu(Manager *&manager); //管理员账号管理菜单

    //子功能实现
    void LoginIn(const string & fileName, int type); //登录功能
    void preDefine(int type); //账户信息管理功能
    void cleanFile(int type); //清除预约记录功能
    void showFile(int type); //实现打印显示功能
    void loadFile(const string& fileName, int type); //实现指定文件信息功能

    //属性设置
    bool StudentFileIsEmpty;
    bool TeacherFileIsEmpty;
    bool ManagerFileIsEmpty;
    vector<long long int> fidV;
    vector<string> fNameV;
    vector<string> fPwdV;
    map<int, vector<string>> infoMap;

};
#endif //CPPSTUDY_COMPUTERORDERSYSTEM_H
