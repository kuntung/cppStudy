#include <iostream>
#include "header/speechManager.h"

using namespace std;

int main() {
//    cout<<"�ݽ��������̹���ϵͳ"<<endl;
    SpeechManager sm;
    //���Դ���
    for (auto &mit : sm.m1) {
        cout << "���:" << mit.first << " ������" << mit.second.m_name << " ��һ�ֳɼ���" << mit.second.m_score[0] << endl;
    }
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
                break;
            case 3:
                //�����ʷ��¼
                break;
            case 0:
                //�˳��ݽ�����ϵͳ
                sm.exit_System();
                break;
            default:
                system("cls"); //����
                break;
        }
    }
}
