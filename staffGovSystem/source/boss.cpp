//
// Created by tangkun on 2020/12/26.
//

#include "header/boss.h"
void Boss::show_info() {
    cout<<"职工编号为:"<<this->m_id
        <<"\t职工姓名:"<<this->m_name
        <<"\t岗位:"<<this->get_deptName()
        <<"\t岗位职责:"<<this->get_workType()<<endl;

}

Boss::Boss(int id, string name, int dId) {
    this->m_id = id;
    this->m_name = name;
    this->m_DeptId = dId;
}

string Boss::get_deptName() {
    return string("老板"); //返回部门岗位名称
}

string Boss::get_workType() {
    return string("给经理下发任务");
}