//自己的通用的数组类
#ifndef MY_ARRAY_H
#define MY_ARRAY_H
#include<iostream>
#include<string>

using namespace std;

template<class T>
class MyArray {
public:
    //默认构造函数
    MyArray(){
        cout<<"MyArray的默认构造函数"<<endl;
    }
    //有参构造函数
    MyArray(int capacity){
        cout<<"MyArray有参构造调用"<<endl;
        this->m_Capacity = capacity;
        this->m_Size = 0;
        this->pAddress = new T[this->m_Capacity]; //根据传入的容量，在堆区上开辟响应的内存空间
    }

    //拷贝构造函数
    MyArray(const MyArray& arr){
        cout<<"MyArray拷贝构造调用"<<endl;

        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        //this->pAddress = arr.pAddress; //浅拷贝问题
        this->pAddress = new T[arr.m_Capacity]; //深拷贝实现

        //将arr中的数组都拷贝过来
        for(int i = 0; i < arr.m_Size; i++){
            this->pAddress[i] = arr.pAddress[i];
        }
    }
    
    //operator=  防止浅拷贝问题，运算符重载
    MyArray& operator=(const MyArray& arr){
        cout<<"MyArray的operator=调用"<<endl;

        //先判断原来堆区是否有数据，如果有先释放
        if(this->pAddress != nullptr){
            delete[] this->pAddress;
            this->pAddress = nullptr;
            this->m_Capacity = 0;
            this->m_Size = 0;
        }
        //深拷贝
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        this->pAddress = new T[arr.m_Capacity];
        for(int i = 0; i < this->m_Capacity; i++){
            this->pAddress[i] = arr.pAddress[i];
        }

        return *this;
    }

    //尾插法
    void Push_Back(const T & val){
        //判断容量是否等于大小
        if (this->m_Capacity == this->m_Size){
            return;
        }
        this->pAddress[this->m_Size] = val; //在数组末尾插入数据
        this->m_Size ++; //更新数组大小
    }

    //尾删法
    void Pop_Back(){
        //判断数组是否为空
        if(this->m_Size == 0){
            return;
        }
        else{
            this->m_Size--;
        }
    }

    //实现通过下标方式访问数组中的元素
    T& operator[](int index){ //返回引用，即返回数据本身，可以进行左值操作
        return this->pAddress[index];
    }

    //返回数组的容量
    int get_Capactity(){
        return this->m_Capacity;
    }
    //返回数组的大小
    int get_Size(){
        return this->m_Size;
    }

    //打印当前数组的最后一个元素
    void print_end();

    //析构函数
    ~MyArray(){
            //数组中每个元素是指向堆区的指针时，才需要逐个把元素delete一遍
            cout<<"MyArray析构函数调用"<<endl;
            if(this->pAddress != nullptr){

                delete[] this->pAddress;
                this->pAddress = nullptr;
            }
    }

private:
    T * pAddress; //指针指向堆区开辟的真实数组
    int m_Capacity; //数组的容量
    int m_Size; //数组的规模

};


//类模板成员函数类外实现
template<typename T>
void MyArray<T>::print_end(){
        if(this->m_Size == 0){
            cout<<"当前数组为空，无法打印"<<endl;
        }
        else{
            cout<<"当前数组的最后一个元素是:"
                <<this->pAddress[this->m_Size-1]<<endl;
        }
}

//实现子类继承
class sonArray :public MyArray<int>{ //必须指定父类中T的类型
public:
    sonArray(){
        cout<<"sonArray的构造函数"<<endl;
    }
};


template<class T1 = int, class T2 = char> //类模板参数类型可以有默认值
class sonArray1 :public MyArray<T1>{
public:
    sonArray1(){
        cout<<"子类构造函数调用" <<endl;
    }

    void show_info(){
        cout<<"相关信息如下:";
//            <<"grade = " << this->m_grade<<endl;
    }
};
#endif