//
// Created by tangkun on 2021/1/16.
//

#ifndef CPPSTUDY_COMPUTERORDERSYSTEM_H
#define CPPSTUDY_COMPUTERORDERSYSTEM_H
#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>
#include <header/teacher.h>
#include <header/manager.h>
#include "header/student.h"
#include"header/identity.h"
#include"header/globalFile.h"

class OrderManager{
public:
    explicit OrderManager(); //���캯��

    //��ʼ������
    void init();
    //�˵�����
    static void show_menu();
    void managerMenu(Identity *&manager);    //����Ա�Ӳ˵�
    void tearcherMenu(Identity *&teacher); //��ʦ�Ӳ˵�
    void studentMenu(Identity *&student); //ѧ���Ӳ˵�
    void managerClientMenu(Manager *&manager); //����Ա�˺Ź���˵�

    //�ӹ���ʵ��
    void LoginIn(const string & fileName, int type); //��¼����
    void preDefine(int type); //�˻���Ϣ������
    void cleanFile(int type); //���ԤԼ��¼����
    void showFile(int type); //ʵ�ִ�ӡ��ʾ����
    void loadFile(const string& fileName, int type); //ʵ��ָ���ļ���Ϣ����

    //��������
    bool StudentFileIsEmpty;
    bool TeacherFileIsEmpty;
    bool ManagerFileIsEmpty;
    vector<long long int> fidV;
    vector<string> fNameV;
    vector<string> fPwdV;
    map<int, vector<string>> infoMap;

};
#endif //CPPSTUDY_COMPUTERORDERSYSTEM_H
