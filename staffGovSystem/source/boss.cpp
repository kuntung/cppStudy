//
// Created by tangkun on 2020/12/26.
//

#include "header/boss.h"
void Boss::show_info() {
    cout<<"ְ�����Ϊ:"<<this->m_id
        <<"\tְ������:"<<this->m_name
        <<"\t��λ:"<<this->get_deptName()
        <<"\t��λְ��:"<<this->get_workType()<<endl;

}

Boss::Boss(int id, string name, int dId) {
    this->m_id = id;
    this->m_name = name;
    this->m_DeptId = dId;
}

string Boss::get_deptName() {
    return string("�ϰ�"); //���ز��Ÿ�λ����
}

string Boss::get_workType() {
    return string("�������·�����");
}