//
// Created by tangkun on 2021/1/16.
//

#include "header/computerOrderSystem.h"

OrderManager::OrderManager() {
    this->init();
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
    if(type == 1 || type == 2) {
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
                    this->studentMenu(person);
                    return;
                } else if (type == 2) { //��ʦ�����֤
                    cout << "��ʦ��֤��¼�ɹ�" << endl;
                    system("read -p 'Press Enter to continue...' var");
                    system("clear");
                    person = new Teacher(id, name, pwd);
                    //�����ʦ�Ӳ˵�
                    this->tearcherMenu(person);
                    return;
                }
            }
        }
    }
    else if(type == 3){
        string fName; //���ļ��л�ȡ������
        string fPwd; //���ļ��л�ȡ����
        //���ڹ���Ա����һ�����ԣ���Ҫ����ƥ��
        while (ifs >> fName && ifs >> fPwd) {
            if (fName == name && fPwd == pwd) {
                cout << "����Ա��֤��¼�ɹ�" << endl;
                system("read -p 'Press Enter to continue...' var");
                system("clear");
                person = new Manager(name, pwd);
                //�������Ա�Ӳ˵�
                this->managerMenu(person);// Identity* &person = new Manager(name, pwd); //����ָ��ָ�������������ã���̬
                return;
            }
        }
    }


    cout << "��֤��¼ʧ�ܣ�" << endl;

    system("read -p 'Press Enter to continue...' var");
    system("clear");
}

void OrderManager::preDefine(int type) {
    string fileName;
    if (type == 1) {
        fileName = STUDENT_FILE;
    } else if (type == 2) {
        fileName = TEACHER_FILE;
    } else if (type == 3) {
        fileName = ADMIN_FILE;
    }
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

void OrderManager::cleanFile(int type) {
    cout << "ȷ����գ�" << endl;
    cout << "1.ȷ��" << endl;
    cout << "2.����" << endl;

    int select = 0;
    cin >> select;
    string fileName;
    if (type == 1) {
        fileName = STUDENT_FILE;
    } else if (type == 2) {
        fileName = TEACHER_FILE;
    } else if (type == 3) {
        fileName = ADMIN_FILE;
    }
    if (select == 1) {
        //��ģʽios::trunc�����������ɾ���ļ������´���
        ofstream ofs(fileName, ios::trunc);
        ofs.close();
        //��ʼ������

        cout << "��ճɹ�" << endl;

    }
    system("read -p 'Press Enter to continue...' var");
    system("clear");

}

void OrderManager::loadFile(const string &fileName, int type) { //�鿴Ŀ���ļ���������Ϣ
    this->init(); //��ÿ�ζ�ȡ�Ŀ�ʼ�������
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
            if (type == 1) {
                this->StudentFileIsEmpty = true;
            } else if (type == 2) {
                this->TeacherFileIsEmpty = true;
            } else if (type == 3) {
                this->ManagerFileIsEmpty = true;
            }
            cout << "�ļ�Ϊ��" << endl;
            ifs.close();
            return;
        }
    }
    ifs.putback(ch); //�������ȡ�ĵ����ַ��Ż���

    //�ļ������Ҳ�Ϊ�����
    int fid;
    string fName;
    string fPwd;
    if (type == 3) {
        while (ifs >> fName && ifs >> fPwd) {
            fNameV.push_back(fName);
            fPwdV.push_back(fPwd);
        }
    } else if (type == 1 || type == 2) {
        while (ifs >> fid && ifs >> fName && ifs >> fPwd) {
            fidV.push_back(fid);
            fNameV.push_back(fName);
            fPwdV.push_back(fPwd);
        }
    }
    ifs.close();
}

void OrderManager::showFile(int type) {
    string fileName;
    if (type == 1) {
        fileName = STUDENT_FILE;
    } else if (type == 2) {
        fileName = TEACHER_FILE;
    } else if (type == 3) {
        fileName = ADMIN_FILE;
    }
    this->loadFile(fileName, type);
    if (type == 3 && !this->ManagerFileIsEmpty) {
        cout << "�����ǹ���Ա�����Ϣ��" << endl;
        for (int i = 0; i < this->fNameV.size(); i++) {
            cout << "��" << i + 1 << "�����ݣ�" << " ����Ա����:" << this->fNameV[i]
                 << " ���룺" << this->fPwdV[i] << endl;
        }
    } else if (type == 1 && !this->StudentFileIsEmpty) {
        cout << "������ѧ�������Ϣ��" << endl;
        for (int i = 0; i < this->fNameV.size(); i++) {
            cout << "��" << i + 1 << "�����ݣ�" << "ѧ�ţ�" << this->fidV[i] << " �û�����" << this->fNameV[i] << " ���룺"
                 << this->fPwdV[i] << endl;
        }
    } else if (type == 2 && !this->TeacherFileIsEmpty) {
        cout << "�����ǽ�ʦ�����Ϣ��" << endl;
        for (int i = 0; i < this->fNameV.size(); i++) {
            cout << "��" << i + 1 << "�����ݣ�" << "ְ���ţ�" << this->fidV[i] << " �û�����" << this->fNameV[i] << " ���룺"
                 << this->fPwdV[i] << endl;
        }
    }
    system("clear");
}

void OrderManager::init() {
    this->infoMap.clear();
    this->fidV.clear();
    this->fNameV.clear();
    this->fPwdV.clear();
}

void OrderManager::managerMenu(Identity *&manager) { //����������ͣ�����Identity*���͵�����
    while (true) {
        //���ù���Ա�Ӳ˵�
        manager->openMenu();

        //������ָ��תΪ����ָ�룬���������������ӿ�
        Manager *man = (Manager *) manager;

        int select = 0;
        cin >> select;
        switch (select) { //����Ա�Ӳ˵�
            case 1://�˺Ź���
                man->clientAction();
                break;
            case 2: //��������
                man->computerAction();
                break;
            case 3: //ԤԼ����
                man->cleanFile(ORDER_FILE);
                break;
            default: //Ĭ�������ע����¼
                delete manager;
                cout << "ע���ɹ�" << endl;
                system("read -p 'Press Enter to continue...' var");
//                system("clear");
                return;
        }
    }
}

void OrderManager::tearcherMenu(Identity *&teacher) {
    while (true) {
        //���ù���Ա�Ӳ˵�
        teacher->openMenu();

        //������ָ��תΪ����ָ�룬���������������ӿ�
        Teacher *teac = (Teacher *) teacher;

        int select = 0;
        cin >> select;
        switch (select) {
            case 1://��ʾ����ԤԼ
                teac->showAllOrder();
                break;
            case 2: //���ԤԼ
                teac->validOrder();
                break;
            default: //Ĭ�������ע����¼
                delete teacher;
                cout << "ע���ɹ�" << endl;
                system("read -p 'Press Enter to continue...' var");
//                system("clear");
                return;
        }
    }
}

void OrderManager::studentMenu(Identity *&student) {
    while (true) {
        //����ѧ���Ӳ˵�
        student->openMenu();

        //������ָ��תΪ����ָ�룬���������������ӿ�
        Student *stu = (Student *) student;

        int select = 0;
        cin >> select;
        switch (select) {
            case 1://����ԤԼ
                stu->applyOrder();
                break;
            case 2: //��ʾ�Լ���ԤԼ���
                stu->showMyOrder();
                break;
            case 3: //��ʾ����ԤԼ
                stu->showAllOrder();
                break;
            case 4: //ȡ��ԤԼ
                stu->cancelOrder();
                break;
            default: //Ĭ�������ע����¼
                delete student;
                cout << "ע���ɹ�" << endl;
                system("read -p 'Press Enter to continue...' var");
                system("clear");
                return;
        }
    }
}
