//
// Created by tangkun on 2020/12/30.
//
#include "MyArray.hpp"

#include <iostream>
#include <string>

using namespace std;

//定义一个函数来打自定义数组的元素
void printArray(MyArray<int> &arr){
    for(int i = 0; i < arr.get_Size(); i++){
        cout<<arr[i]<<endl;
    }
}

void test01(){
    //1. 有参构造调用
    MyArray<int> arr1(5);
    //2.拷贝构造调用
    MyArray<int> arr2(arr1);
    //3.有参构造调用
    MyArray<int> arr3(100);
    //operator=调用
    arr3 = arr1;
}

void test02(){
    MyArray<int> arr4(5);
    for(int i = 0; i < 5; i++){
        arr4.Push_Back(i);
    }
    cout<<"数组元素个数为:" <<arr4.get_Size()<<endl;
    cout<<"数组容量为："<<arr4.get_Capactity()<<endl;
    cout<<"打印所有元素"<<endl;
    printArray(arr4); //打印所有元素
    arr4.print_end();//打印最后一个元素
    arr4.Pop_Back();//尾删法
    printArray(arr4); //打印所有元素


}



//测试自定义数据类型
class Person{
public:
    Person(){

    };
    Person(string name, int age){
        this->m_name = name;
        this->m_age = age;
    }
    string m_name;
    int m_age;

};

//定义打印Person数组
void printPersonArray(MyArray<Person> & arr){
    for(int i = 0; i < arr.get_Size(); i++){
        cout<<"姓名:" <<arr[i].m_name
            <<"年龄:" << arr[i].m_age<<endl;
    }
}

void test03(){
    MyArray<Person> arr(10);

    Person p1("孙悟空", 999);
    Person p2("韩信", 20);
    Person p3("吕布", 35);
    Person p4("张飞", 44);

    //将数据插入到数组中
    arr.Push_Back(p1);
    arr.Push_Back(p2);
    arr.Push_Back(p3);
    arr.Push_Back(p4);

    printPersonArray(arr);
}


//测试子类的代码
void test04(){
    sonArray s1;
    sonArray1 s2;
    s2.show_info();
}
int main(){
    test01();
    cout<<"test02()"<<endl;
    test02();

    cout<<"test03()" <<endl;
    test03();

    cout<<"test04()" <<endl;

    test04();

    return 0;
}