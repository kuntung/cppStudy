//
// Created by tangkun on 2020/12/26.
//

#include "header/manager.h"

void Manager::show_info() {
    cout<<"ְ�����Ϊ:"<<this->m_id
        <<"\tְ������:"<<this->m_name
        <<"\t��λ:"<<this->get_deptName()
        <<"\t��λְ��:"<<this->get_workType()<<endl;

}

Manager::Manager(int id, string name, int dId) {
    this->m_id = id;
    this->m_name = name;
    this->m_DeptId = dId;
}

string Manager::get_deptName() {
    return string("����"); //���ز��Ÿ�λ����
}

string Manager::get_workType() {
    return string("����ϰ��·��������ɷ��������ͨԱ��");
}
