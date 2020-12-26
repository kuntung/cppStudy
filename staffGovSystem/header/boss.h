//
// Created by tangkun on 2020/12/26.
//

#ifndef CPPSTUDY_BOSS_H
#define CPPSTUDY_BOSS_H
#include "worker.h"
#include <iostream>
#include <string>

using namespace std;

class Boss : public Worker {
public:
    Boss(int id, string name, int dId);
    //显示个人信息
    void show_info() override;
    //获取职工岗位名称
    string get_deptName() override;
    //获取岗位职责
    string get_workType() override;
};
#endif //CPPSTUDY_BOSS_H
