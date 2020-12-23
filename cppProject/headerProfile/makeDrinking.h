#pragma once
#include<iostream>

class Drinks{//抽象类
    public:
        virtual void zhuShui() = 0;//煮水的纯虚函数
        virtual void chongPao() = 0;//冲泡的纯虚函数
        virtual void daoBei() = 0;//倒入杯子
        virtual void jiaLiao() = 0;//加入辅料
    
    //制作饮品
        void makeDrink(){
            zhuShui();
            chongPao();
            daoBei();
            jiaLiao();
        }

};
//制作咖啡
class Coffee: public Drinks{
    public:
        void zhuShui();//煮水的纯虚函数
        void chongPao();//冲泡的纯虚函数
        void daoBei();//倒入杯子
        void jiaLiao();//加入辅料
    
};
//制作

class Tea: public Drinks{
    public:
        void zhuShui();//煮水的纯虚函数
        void chongPao();//冲泡的纯虚函数
        void daoBei();//倒入杯子
        void jiaLiao();//加入辅料
    
};
