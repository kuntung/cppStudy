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

    //成员函数
    void show_Menu();   //1.展示菜单功能
    void initSpeech();//2.初始化属性
    void createSpeaker();//3.初始化比赛人员
    void speechDraw(); //4.抽签
    void speechContest(); //比赛功能实现
    //菜单功能

    void exit_System();//1.退出功能
    void start_System();//2.开始比赛功能

    //添加一些成员属性
    vector<int> v1; //第一轮选手人员编号
    vector<int> v2; //第一轮晋级选手编号
    vector<int> v3; //胜出前三名的选手编号
    map<int, Speaker> m1; //存放编号以及对应具体选手容器
    int m_int; //比赛轮次
};

#endif //CPPSTUDY_SPEECHMANAGER_H
