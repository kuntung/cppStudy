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
    cout << "����ԤԼ" <<endl;
}

void Student::showMyOrder() {
    cout <<"��ʾ��ǰԤԼ" <<endl;
}

void Student::showAllOrder() {
    cout << "��ʾ����ԤԼ" <<endl;
}

void Student::cancelOrder() {
    cout << "ȡ��ԤԼ" <<endl;
}

void Student::openMenu() {
    cout << "��ӭѧ��:" << this->m_name << "��¼" << endl;
    cout << "\t\t------------------------------\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          1.����ԤԼ          |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          2.��ʾ��ǰԤԼ      |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          3.��ʾ����ԤԼ      |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          4.ȡ��ԤԼ          |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          0.ע����¼          |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t------------------------------\n";
    cout << "����������ѡ��" << endl;
}

