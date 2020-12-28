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
            {
                //�Ȳ����Ƿ���ڸ�ְ��
                cout << "�����밴��ְ����Ż���ְ���������޸�Ա�������Ϣ��" << endl;
                string edit_choice;
                cin >> edit_choice;
                if (edit_choice == "����") {
                    string edit_name;
                    cout << "��������Ҫ�޸ĵ�ְ������:" << endl;
                    cin >> edit_name;
                    WMSystem.edit_Emp(edit_name);
                } else if (edit_choice == "���") {
                    int edit_id;
                    cout << "��������Ҫ�޸ĵ�ְ�����:" << endl;
                    cin >> edit_id;
                    WMSystem.edit_Emp(edit_id);
                }
                break;
            }
            case 5: //����ְ����Ϣ
            {
                //�Ȳ����Ƿ���ڸ�ְ��
                cout << "�����밴��ְ����Ż���ְ������������Ա�������Ϣ��" << endl;
                string find_choice;
                cin >> find_choice;
                if (find_choice == "����") {
                    string find_name;
                    cout << "��������Ҫ���ҵ�ְ������:" << endl;
                    cin >> find_name;
                    WMSystem.find_Emp(find_name);
                } else if (find_choice == "���") {
                    int find_id;
                    cout << "��������Ҫ���ҵ�ְ�����:" << endl;
                    cin >> find_id;
                    WMSystem.find_Emp(find_id);
                }
                break;
            }
            case 6: //ְ����Ϣ����
                WMSystem.sort_Emp();
                break;
            case 7:  //��������ĵ�
                WMSystem.clear_Emp();
                break;
            default:  //�޲���
                system("cls");  //��������
                break;
        }
    }

    system("pause");
    return 0;
}
