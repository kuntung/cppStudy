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

    //成员函数
    void show_Menu();   //1.展示菜单功能
    void initSpeech();//2.初始化属性
    void createSpeaker();//3.初始化比赛人员
    void speechDraw(); //4.抽签
    void speechContest(); //比赛功能实现
    void showScore(); //显示比赛分数
    void saveRecord(); //保存比赛得分记录
    void showRecord(); //查看记录功能

    //菜单功能
    void exit_System();//1.退出功能
    void start_System();//2.开始比赛功能
    void readRecord(); //3.读取历史比赛得分记录
    void clearRecord(); //4.清空比赛记录

    //添加一些成员属性
    vector<int> v1; //第一轮选手人员编号
    vector<int> v2; //第一轮晋级选手编号
    vector<int> v3; //胜出前三名的选手编号
    map<int, Speaker> m1; //存放编号以及对应具体选手容器
    int m_int; //比赛轮次
    bool fileIsEmpty; //文件为空的标志
    map<int, vector<string>> m_Record; //往届记录
};

#endif //CPPSTUDY_SPEECHMANAGER_H
