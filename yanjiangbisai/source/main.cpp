#include <iostream>
#include "header/speechManager.h"
#include<ctime>
using namespace std;

int main() {
    //���������
    srand((unsigned int) time(NULL));
//    cout<<"�ݽ��������̹���ϵͳ"<<endl;
    SpeechManager sm;
    //���Դ���
//    for (auto &mit : sm.m1) {
//        cout << "���:" << mit.first << " ������" << mit.second.m_name << " ��һ�ֳɼ���" << mit.second.m_score[0] << endl;
//    }
    int choice = 0; //�����洢�û���ѡ��

    while (true) {
        sm.show_Menu();
        cout << "����������ѡ��:" << endl;
        cin >> choice; //�����û���ѡ��

        switch (choice) {
            case 1:
                //��ʼ����
                sm.start_System();
                break;
            case 2:
                //�鿴�����¼
                sm.showRecord();
                break;
            case 3:
                //�����ʷ��¼
                sm.clearRecord();
                break;
            case 0:
                //�˳��ݽ�����ϵͳ
                sm.exit_System();
                break;
            default:
                system("clear"); //����
                break;
        }
    }
}
