//
// Created by tangkun on 2021/1/16.
//

#include "header/teacher.h"

Teacher::Teacher() {

}

Teacher::Teacher(int empId, string name, string pwd) {
    this->m_empId = empId;
    this->m_name = name;
    this->m_pwd = pwd;
}

void Teacher::openMenu() {
    cout << "��ӭ��ʦ:" << this->m_name << "��¼" << endl;
    cout << "\t\t------------------------------\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          1.�鿴����ԤԼ      |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          2.���ԤԼ          |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          0.ע����¼          |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t------------------------------\n";
    cout << "����������ѡ��" << endl;
}

void Teacher::showAllOrder() {
    cout << "�鿴����ԤԼ" <<endl;
}

void Teacher::validOrder() {
    cout << "���ԤԼ" <<endl;

}
