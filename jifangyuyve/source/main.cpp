//
// Created by tangkun on 2021/1/16.
//
#include <iostream>
#include<string>
#include"header/computerOrderSystem.h"

using namespace std;

int main() {
    OrderManager om;
    int select = 0; //���ڽ����û���ѡ��

    while (true) {
        om.show_menu();
        cout << "����������ѡ��:";
        cin >> select; //�����û���ѡ��

        switch (select) {
            case 1: //ѧ�����
                om.LoginIn(STUDENT_FILE, 1);
                break;
            case 2: //��ʦ���
                om.LoginIn(TEACHER_FILE, 2);
                break;
            case 3: //����Ա���
                om.LoginIn(ADMIN_FILE, 3);
                break;
            case 0: //�˳�ϵͳ
                cout << "��ӭ�´�ʹ�ã�" << endl;
                system("clear");
                return 0;
                break;
            default:
                cout << "��������������ѡ��" << endl;
                system("read -p 'Press Enter to continue...' var");
                system("clear");
                break;
        }
    }


    system("read -p 'Press Enter to continue...' var");
    system("clear");
}