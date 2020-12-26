//
// Created by tangkun on 2020/12/25.
//

#include <iostream>
#include <fstream>
#include "header/workerManager.h"
#include "header/boss.h"
#include "header/manager.h"
#include "header/employee.h"

using namespace std;

void test01(){
    Worker *worker = nullptr;

    worker = new Employee(1, "����",1);
    worker->show_info();
    delete worker;

    worker = new Manager(2,"����",2);
    worker->show_info();
    delete worker;

    worker = new Boss(3,"����",3);
    worker->show_info();
    delete worker;

}

int main() {
    //����ְ������ϵͳ
    WorkerManager WMSystem;
    int choice = 0;
    WMSystem.show_menu();
    test01();
//    while(true){
//        WMSystem.show_menu();
//        cout<<"���������ѡ��:"<<endl;
//        cin>>choice;
//        switch(choice){
//            case 0: //�˳�ϵͳ
//                WMSystem.exit_system();
//                break;
//            case 1: //����ְ����Ϣ
//                break;
//            case 2: //��ʾְ����Ϣ
//                break;
//            case 3: //ɾ����ְְ��
//                break;
//            case 4: //�޸�ְ����Ϣ
//                break;
//            case 5: //����ְ����Ϣ
//                break;
//            case 6: //ְ����Ϣ����
//                break;
//            case 7:  //��������ĵ�
//                break;
//            default:  //�޲���
//                system("cls");  //��������
//                break;
//        }
//    }

    system("pause");
    return 0;
}
