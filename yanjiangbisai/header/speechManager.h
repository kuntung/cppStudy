//
// Created by tangkun on 2021/1/14.
//

#ifndef CPPSTUDY_SPEECHMANAGER_H
#define CPPSTUDY_SPEECHMANAGER_H

#include<iostream>
#include<vector>
#include<map>
#include "Speaker.h"
#include<string>

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
    void showScore(); //��ʾ��������
    void saveRecord(); //��������÷ּ�¼
    void showRecord(); //�鿴��¼����

    //�˵�����
    void exit_System();//1.�˳�����
    void start_System();//2.��ʼ��������
    void readRecord(); //3.��ȡ��ʷ�����÷ּ�¼
    void clearRecord(); //4.��ձ�����¼

    //���һЩ��Ա����
    vector<int> v1; //��һ��ѡ����Ա���
    vector<int> v2; //��һ�ֽ���ѡ�ֱ��
    vector<int> v3; //ʤ��ǰ������ѡ�ֱ��
    map<int, Speaker> m1; //��ű���Լ���Ӧ����ѡ������
    int m_int; //�����ִ�
    bool fileIsEmpty; //�ļ�Ϊ�յı�־
    map<int, vector<string>> m_Record; //�����¼
};

#endif //CPPSTUDY_SPEECHMANAGER_H
