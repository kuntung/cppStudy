//
// Created by tangkun on 2020/12/25.
//

#include "header/employee.h"
#include <string>
#include<iostream>


void Employee::show_info() {
    cout<<"ְ�����Ϊ:"<<this->m_id
        <<"\tְ������:"<<this->m_name
        <<"\t��λ:"<<this->get_deptName()
        <<"\t��λְ��:"<<this->get_workType()<<endl;

}

Employee::Employee(int id, string name, int dId) {
    this->m_id = id;
    this->m_name = name;
    this->m_DeptId = dId;
}

string Employee::get_deptName() {
    return string("��ͨԱ��"); //���ز��Ÿ�λ����
}

string Employee::get_workType() {
    return string("��ɾ����·�������");
}
