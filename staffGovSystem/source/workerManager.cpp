//
// Created by tangkun on 2020/12/25.
//

#include "header/workerManager.h"

WorkerManager::WorkerManager(){


}

WorkerManager::~WorkerManager() {

}

void WorkerManager::show_menu() {
    cout<<"***********************************************"<<endl;
    cout<<"************   ��ӭʹ��ְ������ϵͳ�� *************"<<endl;
    cout<<"*************    0.�˳��������   ***************"<<endl;
    cout<<"*************    1.����ְ����Ϣ   ***************"<<endl;
    cout<<"*************    2.��ʾְ����Ϣ   ***************"<<endl;
    cout<<"*************    3.ɾ����ְְ��   ***************"<<endl;
    cout<<"*************    4.�޸�ְ����Ϣ   ***************"<<endl;
    cout<<"*************    5.����ְ����Ϣ   ***************"<<endl;
    cout<<"*************    6.ְ����Ϣ����   ***************"<<endl;
    cout<<"*************    7.��������ĵ�   ***************"<<endl;
    cout<<"***********************************************"<<endl;
    cout<<endl;
}

//�����˳�
void WorkerManager::exit_system() {
    cout<<"�Ƿ��˳�"<<endl;
    system("pause");
    exit(0); //�˳�����
}