//
// Created by tangkun on 2021/1/16.
//

#ifndef CPPSTUDY_MANAGER_H
#define CPPSTUDY_MANAGER_H
#include<iostream>
#include"identity.h"
#include"globalFile.h"
#include<vector>
#include"student.h"
#include"teacher.h"
#include "computer.h"
#include<fstream>
#include<algorithm>

using namespace std;

class Manager:public Identity{
public:
    explicit Manager(); //Ĭ�Ϲ���
    explicit Manager(string name, string pwd); //�вι���

    //�˵�����
    virtual void openMenu();
    void clientMenu();
    void computerMenu();

    //���ܺ���
    void initVector(); //��ʼ������
    bool checkRepeat(int id, int type); //ȥ�غ�����װ
    bool checkRepeat(const string& name); //���ص�ȥ�غ����������жϻ��������Ƿ��ظ�
    void clientAction(); //�˺Ź���ӿ�
    void computerAction(); //��������ӿ�

    void addPerson(); //����˺�
    void showPerson(); //�鿴�˺�
    void showComputer(); //�鿴������Ϣ
    void manageComputer(); //�޸Ļ�����Ϣ
    void addComputerRoom(); //��ӻ�����Ϣ
    void editComputerRoom(); //�޸Ļ�����Ϣ
    void cleanFile(const string & filename); //���ԤԼ��¼
    void editFile(int type); //�޸��ļ�
    void editClient(int type); //�޸�ѧ���ͽ�ʦ�˻���Ϣ
    //����
    vector<Student> vStu;
    vector<Teacher> vTea;
    vector<Computer> vCom;


};
#endif //CPPSTUDY_MANAGER_H
