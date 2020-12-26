//
// Created by tangkun on 2020/12/25.
//

#include "header/employee.h"
#include <string>
#include<iostream>


void Employee::show_info() {
    cout<<"职工编号为:"<<this->m_id
        <<"\t职工姓名:"<<this->m_name
        <<"\t岗位:"<<this->get_deptName()
        <<"\t岗位职责:"<<this->get_workType()<<endl;

}

Employee::Employee(int id, string name, int dId) {
    this->m_id = id;
    this->m_name = name;
    this->m_DeptId = dId;
}

string Employee::get_deptName() {
    return string("普通员工"); //返回部门岗位名称
}

string Employee::get_workType() {
    return string("完成经理下发的任务");
}
