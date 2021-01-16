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

    //�˵�����
    static void show_menu();

    //�ӹ���ʵ��
    void LoginIn(const string & fileName, int type); //��¼����
    void preDefine(const string& fileName, int type); //�˻���Ϣ������
    void cleanFile(const string& fileName, int type); //���ԤԼ��¼����
    void showFile(const string& fileName, int type); //ʵ�ִ�ӡ��ʾ����
    void loadFile(const string& fileName, int type); //ʵ��ָ���ļ���Ϣ����

    //��������
    bool StudentFileIsEmpty;
    bool TeacherFileIsEmpty;
    bool ManagerFileIsEmpty;
    map<int, vector<string>> infoVector;

};
#endif //CPPSTUDY_COMPUTERORDERSYSTEM_H
