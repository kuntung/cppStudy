//
// Created by tangkun on 2021/1/16.
//

#include <header/student.h>

Student::Student() {

}

Student::Student(int id, string name, string pwd) {
    this->m_name = name;
    this->m_id = id;
    this->m_pwd = pwd;
}


void Student::applyOrder() {
    cout << "申请预约" <<endl;
}

void Student::showMyOrder() {
    cout <<"显示当前预约" <<endl;
}

void Student::showAllOrder() {
    cout << "显示所有预约" <<endl;
}

void Student::cancelOrder() {
    cout << "取消预约" <<endl;
}

void Student::openMenu() {
    cout << "欢迎学生:" << this->m_name << "登录" << endl;
    cout << "\t\t------------------------------\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          1.申请预约          |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          2.显示当前预约      |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          3.显示所有预约      |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          4.取消预约          |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          0.注销登录          |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t------------------------------\n";
    cout << "请输入您的选择：" << endl;
}

