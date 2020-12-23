#include<iostream>
#include<string>

using namespace std;

class Drinks{//抽象类，即不实现任何成员函数
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


void doWork(Drinks *abs){
    abs->makeDrink();
    delete abs;//释放堆区内存，防止内存泄露
}

//对咖啡的制作流程方法进行定义
void Coffee::zhuShui(){//煮水的纯虚函数
	cout<<"煮水准备冲泡咖啡"<<endl;
}
void Coffee::chongPao(){//冲泡的纯虚函数
	cout<<"冲泡咖啡"<<endl;
}
void Coffee::daoBei(){//倒入杯子
	cout<<"倒入咖啡杯中"<<endl;
}
void Coffee::jiaLiao(){//加入辅料
	cout<<"加入咖啡料"<<endl;
}

//对茶的制作流程方法进行定义
void Tea::zhuShui(){//煮水的纯虚函数
	cout<<"煮水准备冲泡茶"<<endl;
}
void Tea::chongPao(){//冲泡的纯虚函数
	cout<<"冲泡茶"<<endl;
}
void Tea::daoBei(){//倒入杯子
	cout<<"倒入茶杯中"<<endl;
}
void Tea::jiaLiao(){//加入辅料
	cout<<"加入茶料"<<endl;
}

void test01(){
    Coffee *cof = new Coffee;
    doWork(cof);
    doWork(new Tea);
}
int main(){
    test01();
}
