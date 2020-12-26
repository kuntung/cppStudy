//
// Created by tangkun on 2020/12/25.
//

#include <iostream>
#include "header/workerManager.h"

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
    while(true){
        WMSystem.show_menu();
        cout<<"���������ѡ��:"<<endl;
        cin>>choice;
        switch(choice){
            case 0: //�˳�ϵͳ
                WMSystem.exit_system();
                break;
            case 1: //����ְ����Ϣ
                WMSystem.add_Emp();
                break;
            case 2: //��ʾְ����Ϣ
                WMSystem.show_Emp();
                break;
            case 3: //ɾ����ְְ��
            {
                //�Ȳ����Ƿ���ڸ�ְ��
                cout << "�����밴��ְ����Ż���ְ��������ɾ��Ա�������Ϣ��" << endl;
                string del_choice;
                cin >> del_choice;
                if (del_choice == "����") {
                    string del_name;
                    cout << "��������Ҫɾ����ְ������:" << endl;
                    cin >> del_name;
                    WMSystem.del_Emp(del_name);
                } else if (del_choice == "���") {
                    int del_id;
                    cout << "��������Ҫɾ����ְ�����:" << endl;
                    cin >> del_id;
                    WMSystem.del_Emp(del_id);
                }
                break;
            }
            case 4: //�޸�ְ����Ϣ
                break;
            case 5: //����ְ����Ϣ
                break;
            case 6: //ְ����Ϣ����
                break;
            case 7:  //��������ĵ�
                break;
            default:  //�޲���
                system("cls");  //��������
                break;
        }
    }

    system("pause");
    return 0;
}
