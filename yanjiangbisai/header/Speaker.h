//
// Created by tangkun on 2021/1/14.
//

#ifndef CPPSTUDY_SPEAKER_H
#define CPPSTUDY_SPEAKER_H

#include<iostream>

using namespace std;

class Speaker {
public:
    Speaker();

    ~Speaker();

    //通常情况下，成员属性应该设置为私有
    string m_name;
    double m_score[2]; //分数，最多有两轮得分

};

#endif //CPPSTUDY_SPEAKER_H
