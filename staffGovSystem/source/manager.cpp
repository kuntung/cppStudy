//
// Created by tangkun on 2020/12/26.
//

#include "header/manager.h"

void Manager::show_info() {
    cout<<"职工编号为:"<<this->m_id
        <<"\t职工姓名:"<<this->m_name
        <<"\t岗位:"<<this->get_deptName()
        <<"\t岗位职责:"<<this->get_workType()<<endl;

}

Manager::Manager(int id, string name, int dId) {
    this->m_id = id;
    this->m_name = name;
    this->m_DeptId = dId;
}

string Manager::get_deptName() {
    return string("经理"); //返回部门岗位名称
}

string Manager::get_workType() {
    return string("完成老板下发的任务，派发任务给普通员工");
}
