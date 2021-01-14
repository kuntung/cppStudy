//
// Created by tangkun on 2021/1/14.
//

#ifndef CPPSTUDY_SPEECHMANAGER_H
#define CPPSTUDY_SPEECHMANAGER_H

#include<iostream>
#include<vector>
#include<map>
#include "Speaker.h"

using namespace std;

class SpeechManager {
public:
    SpeechManager();

    ~SpeechManager();

    //��Ա����
    void show_Menu();   //1.չʾ�˵�����
    void initSpeech();//2.��ʼ������
    void createSpeaker();//3.��ʼ��������Ա
    void speechDraw(); //4.��ǩ
    void speechContest(); //��������ʵ��
    //�˵�����

    void exit_System();//1.�˳�����
    void start_System();//2.��ʼ��������

    //���һЩ��Ա����
    vector<int> v1; //��һ��ѡ����Ա���
    vector<int> v2; //��һ�ֽ���ѡ�ֱ��
    vector<int> v3; //ʤ��ǰ������ѡ�ֱ��
    map<int, Speaker> m1; //��ű���Լ���Ӧ����ѡ������
    int m_int; //�����ִ�
};

#endif //CPPSTUDY_SPEECHMANAGER_H
