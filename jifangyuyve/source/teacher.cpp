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
    cout << "欢迎教师:" << this->m_name << "登录" << endl;
    cout << "\t\t------------------------------\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          1.查看所有预约      |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          2.审核预约          |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          0.注销登录          |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t------------------------------\n";
    cout << "请输入您的选择：" << endl;
}

void Teacher::showAllOrder() {
    cout << "查看所有预约" <<endl;
}

void Teacher::validOrder() {
    cout << "审核预约" <<endl;

}
