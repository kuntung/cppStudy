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

    //ͨ������£���Ա����Ӧ������Ϊ˽��
    string m_name;
    double m_score[2]; //��������������ֵ÷�

};

#endif //CPPSTUDY_SPEAKER_H
