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

//    cout<<"进行文件清空操作:"<<endl;
//    cout<<"请选择要清空的文件类别。1.学生，2.教师，3.管理员"<<endl;
//    int cleanTag = 0;
//    cin>>cleanTag;
//    om.cleanFile(cleanTag);

//    cout<<"进行文件添加操作:"<<endl;
//    cout<<"请选择要添加的文件类别。1.学生，2.教师，3.管理员"<<endl;
//    int cleanTag = 0;
//    cin>>cleanTag;
//    om.preDefine(cleanTag);

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
            case 4:
                int showTag;
                cout << "请输入要查看的文件:" << endl;
                cout << "1.学生，2.教师，3.管理员" << endl;
                cin >> showTag;
                om.showFile(showTag);
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