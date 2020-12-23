//在定义类的时候，只需要声明函数方法
#pragma once
#include<iostream>
#include"pointer.h"

using namespace std;

//设计圆类
class Circle{
    //将成员函数设置为public，以用来访问和调用私有化的成员变量
    public:
        void setR(float radiu);
        void setCenter(Point center);
        float getR();
        Point getCenter();
        void showLocation(Point p1);
            
    //先将成员属性设置为私有
    private:
        float m_R;
        Point m_Center;//在类中，可以让另一个类作为本来中的成员
};