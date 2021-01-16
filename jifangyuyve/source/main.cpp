//
// Created by tangkun on 2021/1/16.
//
#include <iostream>
#include<string>
#include"header/computerOrderSystem.h"

using namespace std;

int main() {
    OrderManager om;
    int select = 0; //用于接受用户的选择

    while (true) {
        om.show_menu();
        cout << "请输入您的选择:";
        cin >> select; //接受用户的选择

        switch (select) {
            case 1: //学生身份
                om.LoginIn(STUDENT_FILE, 1);
                break;
            case 2: //教师身份
                om.LoginIn(TEACHER_FILE, 2);
                break;
            case 3: //管理员身份
                om.LoginIn(ADMIN_FILE, 3);
                break;
            case 0: //退出系统
                cout << "欢迎下次使用！" << endl;
                system("clear");
                return 0;
                break;
            default:
                cout << "输入有误，请重新选择" << endl;
                system("read -p 'Press Enter to continue...' var");
                system("clear");
                break;
        }
    }


    system("read -p 'Press Enter to continue...' var");
    system("clear");
}