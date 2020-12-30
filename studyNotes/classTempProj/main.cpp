//
// Created by tangkun on 2020/12/30.
//
#include "MyArray.hpp"

#include <iostream>
#include <string>

using namespace std;

//����һ�����������Զ��������Ԫ��
void printArray(MyArray<int> &arr){
    for(int i = 0; i < arr.get_Size(); i++){
        cout<<arr[i]<<endl;
    }
}

void test01(){
    //1. �вι������
    MyArray<int> arr1(5);
    //2.�����������
    MyArray<int> arr2(arr1);
    //3.�вι������
    MyArray<int> arr3(100);
    //operator=����
    arr3 = arr1;
}

void test02(){
    MyArray<int> arr4(5);
    for(int i = 0; i < 5; i++){
        arr4.Push_Back(i);
    }
    cout<<"����Ԫ�ظ���Ϊ:" <<arr4.get_Size()<<endl;
    cout<<"��������Ϊ��"<<arr4.get_Capactity()<<endl;
    cout<<"��ӡ����Ԫ��"<<endl;
    printArray(arr4); //��ӡ����Ԫ��
    arr4.print_end();//��ӡ���һ��Ԫ��
    arr4.Pop_Back();//βɾ��
    printArray(arr4); //��ӡ����Ԫ��


}



//�����Զ�����������
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

//�����ӡPerson����
void printPersonArray(MyArray<Person> & arr){
    for(int i = 0; i < arr.get_Size(); i++){
        cout<<"����:" <<arr[i].m_name
            <<"����:" << arr[i].m_age<<endl;
    }
}

void test03(){
    MyArray<Person> arr(10);

    Person p1("�����", 999);
    Person p2("����", 20);
    Person p3("����", 35);
    Person p4("�ŷ�", 44);

    //�����ݲ��뵽������
    arr.Push_Back(p1);
    arr.Push_Back(p2);
    arr.Push_Back(p3);
    arr.Push_Back(p4);

    printPersonArray(arr);
}


//��������Ĵ���
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