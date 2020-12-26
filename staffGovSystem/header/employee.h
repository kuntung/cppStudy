//
// Created by tangkun on 2020/12/25.
//

#ifndef CPPSTUDY_EMPLOYEE_H
#define CPPSTUDY_EMPLOYEE_H
#include "worker.h"
#include <iostream>
#include <string>

using namespace std;

class Employee : public Worker {
public:
    Employee(int id, string name, int dId);
    //显示个人信息
    void show_info() override;
    //获取职工岗位名称
    string get_deptName() override;
    //获取岗位职责
    string get_workType() override;
};



#endif //CPPSTUDY_EMPLOYEE_H
