//
// Created by tangkun on 2021/1/16.
//

#include "header/manager.h"

void printStudent(Student &student) { //��ӡѧ����Ϣ����ͨ����
    cout << "ѧ��:" << student.m_id << " ����:" << student.m_name << " ����:" << student.m_pwd << endl;

}

void printTeacher(Teacher &teacher) { //��ӡѧ����Ϣ����ͨ����
    cout << "ְ����:" << teacher.m_empId << " ����:" << teacher.m_name << " ����:" << teacher.m_pwd << endl;

}

void printComputerRoom(Computer &computer) { //�����ӡ������Ϣ����ͨ����
    cout << computer.m_name << "������:" << computer.m_size << endl;
}

Manager::Manager() {

}

Manager::Manager(string name, string pwd) {
    this->m_name = name;
    this->m_pwd = pwd;
    this->initVector();
}

void Manager::openMenu() {
    cout << "��ӭ����Ա:" << this->m_name << "��¼" << endl;
    cout << "\t\t------------------------------\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          1.�����˺�          |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          2.�������          |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          3.���ԤԼ          |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          0.ע����¼          |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t------------------------------\n";
    cout << "����������ѡ��" << endl;
}

void Manager::clientMenu() {
        cout << "��ӭ����Ա:" << this->m_name << "��¼" << endl;
        cout << "\t\t------------------------------\n";
        cout << "\t\t|                            |\n";
        cout << "\t\t|          1.����˺�          |\n";
        cout << "\t\t|                            |\n";
        cout << "\t\t|          2.�鿴�˺�          |\n";
        cout << "\t\t|                            |\n";
        cout << "\t\t|          3.ɾ���˺�          |\n";
        cout << "\t\t|                            |\n";
        cout << "\t\t|          4.����˺�         |\n";
        cout << "\t\t|                            |\n";
        cout << "\t\t|          5.�޸�����         |\n";
        cout << "\t\t|                            |\n";
        cout << "\t\t|          0.ע����¼         |\n";
        cout << "\t\t|                            |\n";
        cout << "\t\t------------------------------\n";
        cout << "����������ѡ��" << endl;

}

void Manager::clientAction() {
    while (true) {
        this->clientMenu();
        int select = 0;
        cin >> select;
        switch (select) { //�˺Ź���
            case 1://����˺�
                this->addPerson();
                break;
            case 2: //�鿴�˺�
                this->showPerson();
                break;
            case 3: //ɾ���˺�
                cout << "ɾ���˺�" << endl;
                break;
            case 4:
                cout << "������Ҫ��յ��˺����ͣ� " << endl;
                cout << "1.ѧ��" << endl;
                cout << "2.��ʦ" << endl;
                int clearType;
                cin >> clearType;
                if(clearType == 1){
                    this->cleanFile(STUDENT_FILE);
                }
                else if(clearType == 2){
                    this->cleanFile(TEACHER_FILE);
                }
                break;
            case 5:
                int type;
                cout << "������Ҫ�޸ĵ��˻����ͣ�" << endl;
                cout << "1.ѧ��" << endl;
                cout << "2.��ʦ" << endl;
                cin >> type;
                this->editClient(type);
                break;  //�������break��䣬����default����ִ��
            default: //Ĭ�������ע����¼
                cout << "ע���ɹ�" << endl;
                system("read -p 'Press Enter to continue...' var");
                system("clear");
                return;
        }
    }

}

void Manager::computerMenu() {
    cout << "��ӭ����Ա:" << this->m_name << "��¼" << endl;
    cout << "\t\t------------------------------\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          1.��ӻ���          |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          2.��ʾ����          |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          3.�޸Ļ���          |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          4.���û���         |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          0.ע����¼         |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t------------------------------\n";
    cout << "����������ѡ��" << endl;
}

void Manager::computerAction() {
    while (true) {
        this->computerMenu();
        int select = 0;
        cin >> select; //��ȡ�û��Ļ�������
        if (select == 1) {
            this->addComputerRoom();
        } else if (select == 2) { //��ʾ����
            this->showComputer();
        } else if (select == 3) { //�޸Ļ���
            this->showComputer();
            this->editComputerRoom();
        }
        else if(select == 4){
            this->cleanFile(COMPUTER_FILE); //���û�����Ϣ
        }
        else{
            cout << "ע�����ɹ�" << endl;
            system("read -p 'Press Enter to continue...' var");
            system("clear");
            return;
        }
    }

}
void Manager::addPerson() {
    cout << "������Ҫ��ӵ��˺�����:" << endl;
    cout << "1.���ѧ��" << endl;
    cout << "2.�����ʦ" << endl;

    int type = 0;
    cin >> type;
    string fileName; //�����ļ���
    string tip; //��ʾ��Ϣ
    string errorTip; //�ظ�������ʾ
    if (type == 1) {
        fileName = STUDENT_FILE;
        tip = "������Ҫ��ӵ�ѧ�������Ϣ��\nѧ�ţ�";
        errorTip = "ѧ���ظ�������������!\nѧ�ţ�";
    } else if (type == 2) {
        fileName = TEACHER_FILE;
        tip = "������Ҫ��ӵĽ�ʦ�����Ϣ��\nְ���ţ�";
        errorTip = "ְ�����ظ�������������!\nְ����:";

    } else if (type == 3) {
        fileName = ADMIN_FILE;
        tip = "���������Ա��Ϣ��";
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
    //����ȥ�ز���
    cout << tip << endl;
    while (true) {
        cin >> id;
        bool ret = this->checkRepeat(id, type);
        if (ret) {
            cout << errorTip << endl;
        } else {
            break;
        }
    }
    cout << "������";
    cin >> name;
    cout << "Ԥ�����룺";
    cin >> pwd;
    if (type == 3) {
        ofs << name << " " << pwd << endl;
        cout << "��ӳɹ���" << endl;
    } else if (type == 1 || type == 2) {
        ofs << id << " " << name << " " << pwd << endl;
        cout << "��ӳɹ���" << endl;
    } else {
        cout << "��������ȷ����Ա���͡�" << endl;
        cout << "���ʧ��" << endl;
    }
    ofs.close();
    this->initVector(); //���ó�ʼ�������ӿڣ����»�ȡ�ļ��е�����
    system("read -p 'Press Enter to continue...' var");
    system("clear");

}

void Manager::showPerson() {
    cout << "��ѡ��鿴�����ݣ�" << endl;
    cout << "1. �鿴����ѧ��" << endl;
    cout << "2. �鿴������ʦ" << endl;

    int select = 0; //�����û�ѡ��
    cin >> select;
    if (select == 1) {
        //�鿴����ѧ��
        cout << "����ѧ����Ϣ����: " << endl;
        for_each(this->vStu.begin(), this->vStu.end(), printStudent); //ͨ������º���������ͨ����
    } else if (select == 2) {
        cout << "���н�ʦ����Ϣ���£�" << endl;
        for_each(this->vTea.begin(), this->vTea.end(), printTeacher); //ͨ������º���������ͨ����
    }

    system("read -p 'Press Enter to continue...' var");
    system("clear");
}

void Manager::showComputer() {
    cout << "��ǰ�������������:" << endl;
    for_each(this->vCom.begin(), this->vCom.end(), printComputerRoom); //ͨ������º���������ͨ����
}

void Manager::cleanFile(const string & filename) {
    ofstream ofs(filename, ios::trunc); // ���Ŀ���ļ�
    ofs.close();

    cout << "��ճɹ�" << endl;
    system("read -p 'Press Enter to continue...' var");
    system("clear");

    this->initVector();
}

void Manager:: initVector() {
    //ȷ���ļ������״̬
    this->vStu.clear();
    this->vTea.clear();
    this->vCom.clear();
    //��ȡ��Ϣ ѧ������ʦ
    ifstream ifs;
    ifs.open(STUDENT_FILE, ios::in);
    if (!ifs.is_open()) {
        cout << "�ļ���ȡʧ��" << endl;
        return;
    }

    //��ȡѧ����Ϣ
    Student s;
    while (ifs >> s.m_id && ifs >> s.m_name && ifs >> s.m_pwd) {
        this->vStu.push_back(s);
    }

    cout << "��ǰѧ������Ϊ:" << this->vStu.size() << endl;
    ifs.close();

    //��ȡ��ʦ��Ϣ
    ifs.open(TEACHER_FILE, ios::in);
    if (!ifs.is_open()) {
        cout << "�ļ���ȡʧ��" << endl;
        return;
    }
    Teacher tea;
    while (ifs >> tea.m_empId && ifs >> tea.m_name && ifs >> tea.m_pwd) {
        this->vTea.push_back(tea);
    }

    cout << "��ǰ��ʦ����Ϊ:" << this->vTea.size() << endl;

    ifs.close();

    //��ȡ������Ϣ
    ifs.open(COMPUTER_FILE, ios::in);
    if (!ifs.is_open()) {
        cout << "�ļ���ȡʧ��" << endl;
        return;
    }
    Computer computer;
    while (ifs >> computer.m_name && ifs >> computer.m_size) {
        this->vCom.push_back(computer);
    }

    cout << "��ǰ��������Ϊ:" << this->vCom.size() << endl;

    ifs.close();
}

bool Manager::checkRepeat(int id, int type) { //idΪ������ѧ�š�ְ���ţ�typeΪ������
    if (type == 1) {
        //����ѧ�������е�ѧ�ţ��ж��Ƿ����ظ�
        for (auto &svit : this->vStu) {
            if (svit.m_id == id) {
                return true;
            }
        }
    } else if (type == 2) {
        //������ʦ�����е�ְ���ţ��ж��Ƿ����ظ�
        for (auto &tvit : this->vTea) {
            if (tvit.m_empId == id) {
                return true;
            }
        }
    }
    return false;
}

bool Manager::checkRepeat(const string &name) { //nameΪ��ȷ���Ļ�������
    for (auto &cvit : this->vCom) {
        if (cvit.m_name == name) {
            return true;
        }
    }
    return false;
}

void Manager::manageComputer() {
    int select = 0;
    cin >> select; //��ȡ�û��Ļ�������
    if (select == 1) {
        string name; //�ⶨ��������
        int size = 0; //�»�������
        ofstream ofs;
        ofs.open(COMPUTER_FILE, ios::out | ios::app); //��׷�ӵ���ʽд���µĻ�����Ϣ
        cout << "�������»���������:" << endl;
        while (true) {
            cin >> name;
            bool ret = checkRepeat(name);
            if (ret) {
                cout << "�������Ƴ�ͻ������������\n�»������ƣ�" << endl;
            } else {
                break;
            }
        }
        cout << "�������»�����������" << endl;
        cin >> size;
        ofs << name <<" "<< size << endl;
        cout << "����»����ɹ���" << endl;
        ofs.close(); //�ر��ļ�
        this->initVector(); //����������Ϣ�����̸���
    } else if (select == 2) {
        this->showComputer();
        cout << "�޸Ļ�����Ϣ" << endl;
    } else if (select == 3) {
        this->showComputer();
        system("read -p 'Press Enter to continue...' var");
        system("clear");
    }
}

void Manager::addComputerRoom() {
    string name; //�ⶨ��������
    int size = 0; //�»�������
    ofstream ofs;
    ofs.open(COMPUTER_FILE, ios::out | ios::app); //��׷�ӵ���ʽд���µĻ�����Ϣ
    cout << "�������»���������:" << endl;
    while (true) {
        cin >> name;
        bool ret = checkRepeat(name);
        if (ret) {
            cout << "�������Ƴ�ͻ������������\n�»������ƣ�" << endl;
        } else {
            break;
        }
    }
    cout << "�������»�����������" << endl;
    cin >> size;
    ofs << name <<" "<< size << endl;
    cout << "����»����ɹ���" << endl;
    ofs.close(); //�ر��ļ�
    this->initVector(); //����������Ϣ�����̸���
}

void Manager::editComputerRoom() {
    cout << "������Ҫ�޸ĵĻ������ƣ�" << endl;
    string roomName;
    vector<Computer>::iterator findName;
    while (true){  //�����Ƿ���������Ļ�������
        cin >> roomName;
        //
        findName = find(this->vCom.begin(), this->vCom.end(), roomName);
        if(findName == this->vCom.end()){
            cout << "��������Ϊ" << roomName << "�Ļ���������������" << endl;
        }
        else{
            break;
        }
    }
    cout << "�������»��������ƣ�" << endl;
    string newRoomName;
    while (true){
        cin >> newRoomName;
        //
        findName = find(this->vCom.begin(), this->vCom.end(), newRoomName);
        if(findName == this->vCom.end()){
            break;
        }
        else{
            cout << "�Ѿ�������Ϊ" << newRoomName << "�Ļ���������������" << endl;
        }
    }
    //�滻�ҵ�λ�õĻ�������
    cout << "�������»���<" << newRoomName << ">������:" << endl;
    int newSize;
    while(true){
        cin >> newSize;
        if(newSize > 0){
            break;
        }
        else{
            cout << "��������ȷ������ֵ��" << endl;
        }
    }
    Computer newComputer;
    newComputer.m_name = newRoomName;
    newComputer.m_size = newSize;
    replace_if(this->vCom.begin(),this->vCom.end(),[&](const Computer& c)->bool {
        c.m_name == roomName;},newComputer);
    //��ӡ��ʾ�»�����Ϣ
    this->showComputer();
    this->editFile(3); //���µĻ�������д�뵽�ļ���
    //���»�����Ϣд���ļ��С����Կ��ǹ���һ��д��ģ�塣
    system("read -p 'Press Enter to continue...' var");
    system("clear");
}

void Manager::editFile(int type) {
    string filename;
    ofstream ofs;
    switch(type){
        case 1:
            filename = STUDENT_FILE;
            ofs.open(filename, ios::trunc);
            for(auto & vit : this->vStu){
                ofs << vit.m_id <<" " << vit.m_name << " " << vit.m_pwd << endl;
            }
            cout << "�޸�ѧ���˺���Ϣ�ɹ�" << endl;
            break;
        case 2:
            filename = TEACHER_FILE;
            ofs.open(filename, ios::trunc);
            for(auto & vit : this->vTea){
                ofs << vit.m_empId <<" " << vit.m_name << " " << vit.m_pwd << endl;
            }
            cout << "�޸Ľ�ʦ�˺���Ϣ�ɹ�" << endl;
            break;
        case 3:
            filename = COMPUTER_FILE;
            ofs.open(filename, ios::trunc);
            for(auto & vit : this->vCom){
                ofs << vit.m_name << " " << vit.m_size << endl;
            }
            cout << "�޸Ļ�����Ϣ�ɹ�" << endl;
            break;
        default:
            cout << "��������ȷ���ļ����͡�" << endl;
    }
    ofs.close();
    this->initVector(); //���¼������µ������Ϣ
}

void Manager::editClient(int type) {
    cout << "������Ҫ�޸�������û�ID��" << endl;
    int clientID;
    string newPWD;  //Ҫ�޸ĵ�������
    while(true){ //���ѧ��ƥ��ʧ��
        cin >> clientID;
        if(!checkRepeat(clientID, type)){
            cout << "�����ڸ��û����Ƿ���ӣ�" << endl;
            cout << "1.���" << endl;
            cout << "2.ȡ��" << endl;
            int select;
            cin >> select;
            if(select == 1){
                string extraName; //����δ�ҵ���գ���Ҫ���ʱ������
                string extraPwd; //��Ҫ��ӵ�����
                cout << "�������ID��Ӧ��������" << endl;
                cin >> extraName;
                cout << "�������ID��Ӧ�����룺" << endl;
                cin >> extraPwd;
                if(type == 1){
                    Student temp(clientID, extraName, extraPwd);
                    this->vStu.push_back(temp);
                    cout << "��ӳɹ�" << endl;
                }
                else if(type == 2){
                    Teacher temp(clientID, extraName, extraPwd);
                    this->vTea.push_back(temp);
                    cout << "��ӳɹ�" << endl;
                }
                return;
            }
            else{
                break;
            }
        }

    }
    if(type == 1){ //ѧ��ƥ��ɹ�
        auto findID = find(this->vStu.begin(), this->vStu.end(), clientID);
        cout << "ƥ�䵽ѧ��Ϊ��" << clientID << "���û���" << endl;
        cout << "������" << findID->m_name << "���룺" << findID->m_pwd << endl;
        cout << "�������µ����룺" << endl;
        cin >> newPWD;
        Student tempStu = *findID;
        tempStu.m_pwd = newPWD;
        replace_if(this->vStu.begin(), this->vStu.end(), [&](const Student& s)->bool {
            return s.m_id == clientID;}, tempStu);    //���޸ĺ����Ϣ�滻
    }
    else if(type == 2){ //ְ����ƥ��ɹ�
        auto findID = find(this->vTea.begin(), this->vTea.end(), clientID);
        cout << "ƥ�䵽ְ����Ϊ��" << clientID << "���û���" << endl;
        cout << "������" << findID->m_name << "���룺" << findID->m_pwd << endl;
        cout << "�������µ����룺" << endl;
        cin >> newPWD;
        Teacher tempTea = *findID;
        tempTea.m_pwd = newPWD;
        replace_if(this->vTea.begin(), this->vTea.end(), [&](const Teacher& t)->bool {
            return t.m_empId == clientID;}, tempTea);    //���޸ĺ����Ϣ�滻

    }
    this->editFile(type);


}








