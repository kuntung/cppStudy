//在定义类的时候，只需要声明函数方法，以及私有化成员变量
#pragma once
#include<iostream>

using namespace std;

//设计点类
class Point{
    public:
        void setX(float x);
        void setY(float y);
        float getX();
        float getY();
    private:
        float m_x;
        float m_y;
};