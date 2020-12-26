//
// Created by tangkun on 2020/12/25.
//

#ifndef CPPSTUDY_WORKERMANAGER_H
#define CPPSTUDY_WORKERMANAGER_H
#include<iostream>
#include "header/worker.h"
#include "header/employee.h"
#include "header/boss.h"
#include "header/manager.h"
#include <fstream>

#define FILENAME "workerFile.txt"

using namespace std;

class WorkerManager{
public:
    WorkerManager();//���캯��
    ~WorkerManager();//��������
    void show_menu(); //��ʾ����
    void exit_system(); //�˳�ϵͳ
    void add_Emp();//���ְ��
    void save(); //�����ļ�
    int get_EmpNum(); //ͳ������ְ������
    void init_Emp(); //��ʼ��Ա��
    void show_Emp(); //��ʾԱ����Ϣ
    void del_Emp(int id); //����ְ�����ɾ��Ա��
    void del_Emp(string name); //���غ�������������ɾ��Ա��
    int IsExit(int id); //�ж�ĳλԱ���Ƿ���ڣ���������򷵻����������е�λ�ã��������򷵻�-1
    int IsExit(string name); //�ж�ĳλԱ���Ƿ���ڣ���������򷵻����������е�λ�ã��������򷵻�-1



    int m_EmpNum; //��¼�ļ��е���������
    Worker ** m_EmpArray; //Ա�������ָ��,ָ��worker�����ָ���ָ��
    bool m_FileIsEmpty; //��־�ļ��Ƿ�Ϊ��



};
#endif //CPPSTUDY_WORKERMANAGER_H
