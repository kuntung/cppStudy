//�Լ���ͨ�õ�������
#ifndef MY_ARRAY_H
#define MY_ARRAY_H
#include<iostream>
#include<string>

using namespace std;

template<class T>
class MyArray {
public:
    //Ĭ�Ϲ��캯��
    MyArray(){
        cout<<"MyArray��Ĭ�Ϲ��캯��"<<endl;
    }
    //�вι��캯��
    MyArray(int capacity){
        cout<<"MyArray�вι������"<<endl;
        this->m_Capacity = capacity;
        this->m_Size = 0;
        this->pAddress = new T[this->m_Capacity]; //���ݴ�����������ڶ����Ͽ�����Ӧ���ڴ�ռ�
    }

    //�������캯��
    MyArray(const MyArray& arr){
        cout<<"MyArray�����������"<<endl;

        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        //this->pAddress = arr.pAddress; //ǳ��������
        this->pAddress = new T[arr.m_Capacity]; //���ʵ��

        //��arr�е����鶼��������
        for(int i = 0; i < arr.m_Size; i++){
            this->pAddress[i] = arr.pAddress[i];
        }
    }
    
    //operator=  ��ֹǳ�������⣬���������
    MyArray& operator=(const MyArray& arr){
        cout<<"MyArray��operator=����"<<endl;

        //���ж�ԭ�������Ƿ������ݣ���������ͷ�
        if(this->pAddress != nullptr){
            delete[] this->pAddress;
            this->pAddress = nullptr;
            this->m_Capacity = 0;
            this->m_Size = 0;
        }
        //���
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        this->pAddress = new T[arr.m_Capacity];
        for(int i = 0; i < this->m_Capacity; i++){
            this->pAddress[i] = arr.pAddress[i];
        }

        return *this;
    }

    //β�巨
    void Push_Back(const T & val){
        //�ж������Ƿ���ڴ�С
        if (this->m_Capacity == this->m_Size){
            return;
        }
        this->pAddress[this->m_Size] = val; //������ĩβ��������
        this->m_Size ++; //���������С
    }

    //βɾ��
    void Pop_Back(){
        //�ж������Ƿ�Ϊ��
        if(this->m_Size == 0){
            return;
        }
        else{
            this->m_Size--;
        }
    }

    //ʵ��ͨ���±귽ʽ���������е�Ԫ��
    T& operator[](int index){ //�������ã����������ݱ������Խ�����ֵ����
        return this->pAddress[index];
    }

    //�������������
    int get_Capactity(){
        return this->m_Capacity;
    }
    //��������Ĵ�С
    int get_Size(){
        return this->m_Size;
    }

    //��ӡ��ǰ��������һ��Ԫ��
    void print_end();

    //��������
    ~MyArray(){
            //������ÿ��Ԫ����ָ�������ָ��ʱ������Ҫ�����Ԫ��deleteһ��
            cout<<"MyArray������������"<<endl;
            if(this->pAddress != nullptr){

                delete[] this->pAddress;
                this->pAddress = nullptr;
            }
    }

private:
    T * pAddress; //ָ��ָ��������ٵ���ʵ����
    int m_Capacity; //���������
    int m_Size; //����Ĺ�ģ

};


//��ģ���Ա��������ʵ��
template<typename T>
void MyArray<T>::print_end(){
        if(this->m_Size == 0){
            cout<<"��ǰ����Ϊ�գ��޷���ӡ"<<endl;
        }
        else{
            cout<<"��ǰ��������һ��Ԫ����:"
                <<this->pAddress[this->m_Size-1]<<endl;
        }
}

//ʵ������̳�
class sonArray :public MyArray<int>{ //����ָ��������T������
public:
    sonArray(){
        cout<<"sonArray�Ĺ��캯��"<<endl;
    }
};


template<class T1 = int, class T2 = char> //��ģ��������Ϳ�����Ĭ��ֵ
class sonArray1 :public MyArray<T1>{
public:
    sonArray1(){
        cout<<"���๹�캯������" <<endl;
    }

    void show_info(){
        cout<<"�����Ϣ����:";
//            <<"grade = " << this->m_grade<<endl;
    }
};
#endif