//
// Created by tangkun on 2021/1/16.
//

#include "header/computerOrderSystem.h"

OrderManager::OrderManager() {

}

void OrderManager::show_menu() {
    cout << "=============== ��ӭ��������ԤԼϵͳ ===============" << endl;
    cout << endl << "�������������" << endl;
    cout << "\t\t------------------------------\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          1.ѧ    ��         |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          2.��    ʦ         |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          3.�� �� Ա         |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          4.��    ��         |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          0.��    ��         |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t------------------------------\n";
}

void OrderManager::LoginIn(const string &fileName, int type) {
    Identity *person = nullptr; //����ָ�룬����ָ��������󡣶�̬

    //�ȴ���Ŀ���ļ�
//    ofstream ofs(fileName, ios::trunc);
//    cout<<"ɾ�������ɹ�"<<endl;
//    ofs.close();
    ifstream ifs(fileName, ios::in);

    //�ж��ļ��Ƿ����
    if (!ifs.is_open()) {
        cout << "�ļ�������" << endl;
        ifs.close();
        return;
    }
    char ch;
    ifs >> ch;
    if (ifs.is_open()) { //�ļ�û������
        if (ifs.eof()) {
            cout << "�ļ�Ϊ��" << endl;
            ifs.close();
            return;
        }
    }
    ifs.putback(ch); //�������ȡ�ĵ����ַ��Ż���
    //�ļ������Ҳ�Ϊ�����
    int id = 0;
    string name;
    string pwd;

    //�ж����
    if (type == 1) { //ѧ�����
        cout << "���������ѧ�ţ�" << endl;
        cin >> id;
    } else if (type == 2) {
        cout << "����������ְ����:" << endl;
        cin >> id;
    }

    cout << "�������û�����" << endl;
    cin >> name;

    cout << "���������룺" << endl;
    cin >> pwd;
    int fId; //���ļ��л�ȡ��ID��
    string fName; //���ļ��л�ȡ������
    string fPwd; //���ļ��л�ȡ����
    while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
        //���û��������Ϣ���жԱ�
        if (fId == id && fName == name && fPwd == pwd) {
            if (type == 1) { //ѧ�������֤
                cout << "ѧ����֤��¼�ɹ�" << endl;
                system("read -p 'Press Enter to continue...' var");
                system("clear");
                person = new Student(id, name, pwd);
                //����ѧ���Ӳ˵�

                return;
            } else if (type == 2) { //��ʦ�����֤
                cout << "��ʦ��֤��¼�ɹ�" << endl;
                system("read -p 'Press Enter to continue...' var");
                system("clear");
                person = new Teacher(id, name, pwd);
                //�����ʦ�Ӳ˵�

                return;
            }
        }
    }
    //���ڹ���Ա����һ�����ԣ���Ҫ����ƥ��
    while (ifs >> fName && ifs >> fPwd) {
        if (fName == name && fPwd == pwd) {
            cout << "����Ա��֤��¼�ɹ�" << endl;
            system("read -p 'Press Enter to continue...' var");
            system("clear");
            person = new Manager(name, pwd);
            //�������Ա�Ӳ˵�

            return;
        }
    }

    cout << "��֤��¼ʧ�ܣ�" << endl;

    system("read -p 'Press Enter to continue...' var");
    system("clear");
}

void OrderManager::preDefine(const string &fileName, int type) {
    ofstream ofs;
    ofs.open(fileName, ios::out | ios::app); //��׷�ӵķ�ʽд�ļ�
    //�ж��ļ��Ƿ����
    if (!ofs.is_open()) {
        cout << "�ļ�������" << endl;
        ofs.close();
        return;
    }
    int id = 0;
    string name;
    string pwd;
    //��ÿ��ѡ������д�뵽�ļ���
    if (type == 1) {
        cout << "������Ҫ��ӵ�ѧ�������Ϣ��" << endl;
        cout << "ѧ�ţ�";
        cin >> id;
    } else if (type == 2) {
        cout << "������Ҫ��ӵĽ�ʦ�����Ϣ��" << endl;
        cout << "ְ���ţ�";
        cin >> id;
    } else if (type == 3) {
        cout << "���������Ա��Ϣ��";
    }
    cout << "��������ӵ�������";
    cin >> name;
    cout << "������Ԥ�����룺";
    cin >> pwd;
    if (type == 3) {
        ofs << name << " " << pwd << endl;
    } else {
        ofs << id << " " << name << " " << pwd << endl;
    }
    ofs.close();
    cout << "��ӳɹ���";
}

void OrderManager::cleanFile(const string &fileName, int type) {


}

void OrderManager::loadFile(const string &fileName, int type) { //�鿴Ŀ���ļ���������Ϣ
    ifstream ifs(fileName, ios::in);

    //�ж��ļ��Ƿ����
    if (!ifs.is_open()) {
        cout << "�ļ�������" << endl;
        ifs.close();
        return;
    }
    char ch;
    ifs >> ch;
    if (ifs.is_open()) { //�ļ�û������
        if (ifs.eof()) {
            if(type == 1){
                this->StudentFileIsEmpty = true;
            }
            else if(type == 2){
                this->TeacherFileIsEmpty = true;
            }
            else if(type == 3){
                this->ManagerFileIsEmpty = true;
            }
            cout << "�ļ�Ϊ��" << endl;
            ifs.close();
            return;
        }
    }
    ifs.putback(ch); //�������ȡ�ĵ����ַ��Ż���

    //�ļ������Ҳ�Ϊ�����
    string lineData;
    int index = 0; //��0������
    while(ifs >> lineData){
        //��ȡ����
        vector<string> vs;
        int pos = -1; //���ҵ�" "��λ��
        int start = 0;
        while(true){
            pos = lineData.find(",", start);
            if (pos == -1) {
                //û���ҵ����
                break;
            }
            string temp = lineData.substr(start, pos - start);
//            cout << temp << endl;
            vs.push_back(temp);
            start = pos + 1;
        }
        this->infoVector.insert(make_pair(index, vs)); //����ȡ���������ݱ���
        index++;
        }

    ifs.close();
}
