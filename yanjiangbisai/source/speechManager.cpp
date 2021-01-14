//
// Created by tangkun on 2021/1/14.
//

#include "header/speechManager.h"
#include<algorithm>
#include <random>

SpeechManager::SpeechManager() {
//在构造函数中调用，初始化属性函数
    initSpeech();
    createSpeaker();
}

SpeechManager::~SpeechManager() {

}

void SpeechManager::show_Menu() {
    cout << "***********************************************" << endl;
    cout << "***************  欢迎参加演讲比赛  ***************" << endl;
    cout << "***************  1.开始演讲比赛  ***************" << endl;
    cout << "***************  2.查看往届记录  ***************" << endl;
    cout << "***************  3.清空比赛记录  ***************" << endl;
    cout << "***************  0.退出比赛程序  ***************" << endl;
    cout << "***********************************************" << endl;
    cout << endl;

}

void SpeechManager::exit_System() {//退出功能
    cout << "欢迎下次使用！" << endl;
    system("pause");
    exit(0);
}

void SpeechManager::start_System() {//开始演讲
    //第一轮比赛
    //1.抽签
    speechDraw();
    //2.比赛

    //3.显示晋级结果

    //第二轮比赛

    //1.抽签

    //2.比赛

    //显示前三名


}

void SpeechManager::initSpeech() {
    //清空比赛容器
    this->v1.clear();
    this->v2.clear();
    this->v3.clear();
    this->m1.clear();
    //初始化比赛轮次
    this->m_int = 0;

}

void SpeechManager::createSpeaker() {
    string nameSeed = "ABCDEFGHIJKL";

    for (int i = 0; i < nameSeed.size(); i++) {
        string name = "选手";
        name += nameSeed[i];

        Speaker sp;
        sp.m_name = name;
        for (int i = 0; i < 2; i++) {
            sp.m_score[i] = 0; //初始化分数
        }

        //12名选手的编号
        this->v1.push_back(i + 10001);

        //将选手编号以及选手信息放到map容器中
        this->m1.insert(make_pair(i + 10001, sp)); //map容器需要用`insert`插入元素，插入元素类型为对组pair
    }

}

void SpeechManager::speechDraw() {
    cout << "第<" << this->m_int + 1<< ">轮比赛选手正在抽签" << endl;
    cout << "----------------------" << endl;
    cout << "抽签后演讲顺序如下:" << endl;
    if (this->m_int == 0) {
        random_shuffle(v1.begin(), v1.end()); //打乱第一轮选手的标签
        for (int &vit : this->v1) {
            cout << vit << ",";
        }
        cout << endl;
    }
    else if(this->m_int == 1){
        random_shuffle(v2.begin(), v2.end()); //打乱第一轮选手的标签
        for (int &vit : this->v2) {
            cout << vit << ",";
        }
        cout << endl;
    }

}
