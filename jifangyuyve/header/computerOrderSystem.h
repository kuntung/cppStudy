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

    //菜单功能
    static void show_menu();

    //子功能实现
    void LoginIn(const string & fileName, int type); //登录功能
    void preDefine(const string& fileName, int type); //账户信息管理功能
    void cleanFile(const string& fileName, int type); //清除预约记录功能
    void showFile(const string& fileName, int type); //实现打印显示功能
    void loadFile(const string& fileName, int type); //实现指定文件信息功能

    //属性设置
    bool StudentFileIsEmpty;
    bool TeacherFileIsEmpty;
    bool ManagerFileIsEmpty;
    map<int, vector<string>> infoVector;

};
#endif //CPPSTUDY_COMPUTERORDERSYSTEM_H
