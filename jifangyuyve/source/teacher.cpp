//
// Created by tangkun on 2021/1/16.
//

#include "header/teacher.h"

Teacher::Teacher() {

}

Teacher::Teacher(int empId, string name, string pwd) {
    this->m_empId = empId;
    this->m_name = name;
    this->m_pwd = pwd;
}

void Teacher::openMenu() {
    cout << "��ӭ��ʦ:" << this->m_name << "��¼" << endl;
    cout << "\t\t------------------------------\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          1.�鿴����ԤԼ      |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          2.���ԤԼ          |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          0.ע����¼          |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t------------------------------\n";
    cout << "����������ѡ��" << endl;
}

void Teacher::showAllOrder() {
    Student st;
    st.showAllOrder();

}

void Teacher::validOrder() {
    while (true) {
        OrderFile od; //�ڴ���od�����ʱ�򣬹��캯�����ȡORDER_FILE��ԤԼ��¼��ȡ���浽this->m_OrderData��
        if (od.m_Size == 0) {
            cout << "��ǰ���κ�ԤԼ��¼" << endl;
            system("read -p 'Press Enter to continue...' var");
            system("clear");
            return;
        }

        //����ʦ����ԤԼ��¼��˹���
        cout << "����˵�ԤԼ��¼���£�" << endl;
        vector<int> v; //������¼����˵�ԤԼ����������е��±�
        int index = 0;
        for (int i = 0; i < od.m_Size; i++) {
            if (od.m_orderData[i]["status"] == "1") { //���д��������
                v.push_back(i);
                cout << "��<" << ++index << ">�������ԤԼ��¼��";
                od.showOrder(i); //��ӡ��ʾ�����ԤԼ��¼
            }
        }
        if(v.size() == 0){
            break;
        }
        cout << "��������˵�ԤԼ��¼���" << endl;
        int select = 0; //�����û�ѡ���ԤԼ��¼
        int ret = 0; //����ԤԼ��˽��
        while (true) {
            cin >> select;
            if (select >= 0 || select <= v.size()) {
                if (select == 0) {
                    cout << "ȡ����ǰ��˹���" << endl;
                    break;
                } else {
                    cout << "��������˽��" << endl;
                    cout << "1.ͨ��" << endl;
                    cout << "2.��ͨ��" << endl;
                    cin >> ret;
                    if (ret == 1) {
                        od.m_orderData[v[select - 1]]["status"] = "2"; //���ͨ��
                    } else {
                        od.m_orderData[v[select - 1]]["status"] = "-1"; //��˲�ͨ��
                    }
                    od.updateOrder(); //������˺��ԤԼ��¼
                    cout << "������" << endl;
                    break;
                }
            }
            cout << "������������������" << endl;
        }
    }
    cout << "ȫ��������" << endl;
    system("read -p 'Press Enter to continue...' var");
    system("clear");

}
