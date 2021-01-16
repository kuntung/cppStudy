//
// Created by tangkun on 2021/1/16.
//

#ifndef CPPSTUDY_IDENTITY_H
#define CPPSTUDY_IDENTITY_H
#include<iostream>

using namespace std;

class Identity{//身份抽象基类
public:
    virtual void openMenu()=0; //操作菜单，纯虚函数。不需要提供函数实现

    //用户名
    string m_name;
    string m_pwd;
};
#endif //CPPSTUDY_IDENTITY_H
