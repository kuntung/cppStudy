//
// Created by tangkun on 2021/1/18.
//

#ifndef CPPSTUDY_COMPUTER_H
#define CPPSTUDY_COMPUTER_H
#include<iostream>

using namespace std;

class Computer{
public:
    explicit Computer(); //默认构造函数
    explicit Computer(string name, int size); //有参构造函数

    //重载==运算符，因为对于自定义数据类型，find最开始不知道如何进行比较
    bool operator==(const string & name) const{
        if(this->m_name == name){
            return true;
        }
        else{
            return false;
        }
    }
    //computer属性设置
    string m_name;
    int m_size;

};
#endif //CPPSTUDY_COMPUTER_H
