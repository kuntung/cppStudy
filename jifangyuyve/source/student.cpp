//
// Created by tangkun on 2021/1/16.
//

#include <header/student.h>

Student::Student() {

}

Student::Student(int id, string name, string pwd) {
    this->m_name = name;
    this->m_id = id;
    this->m_pwd = pwd;

    //��ʼ��������Ϣ
    ifstream ifs;
    ifs.open(COMPUTER_FILE, ios::in);

    Computer com;
    while (ifs >> com.m_name && ifs >> com.m_size) {
        this->svCom.push_back(com); //��������Ϣ�õ�
    }
    ifs.close();
}


void Student::applyOrder() {
//    cout << "����ԤԼ" <<endl;
    cout << "��������ʱ��Ϊ��һ�����壡" << endl;
    cout << "����������ԤԼ��ʱ�䣺" << endl;
    cout << "1.��һ" << endl;
    cout << "2.�ܶ�" << endl;
    cout << "3.����" << endl;
    cout << "4.����" << endl;
    cout << "5.����" << endl;

    int date = 0; //����
    int interval = 0; //ʱ���
    int room = 0; //�������
    while (true) {
        cin >> date;
        if (date >= 1 && date <= 5) {
            break;
        } else {
            cout << "������������������" << endl;
        }
    }
    cout << "������ԤԼ��ʱ���" << endl;
    cout << "1.����" << endl;
    cout << "2.����" << endl;
    while (true) {
        cin >> interval;
        if (interval >= 1 && interval <= 2) {
            break;
        }
        cout << "��ѡ����ȷ��ʱ���" << endl;
    }
    cout << "��ѡ�������" << endl;
    for (int i = 0; i < this->svCom.size(); i++) { //��ӡ���ÿ������������
        cout << "��<" << i + 1 << ">���������ƣ�" << this->svCom[i].m_name << "����������Ϊ��" << this->svCom[i].m_size << endl;
    }

    while (true) {
        cin >> room;
        if (room >= 1 && room <= this->svCom.size()) {
            break;
        }
        cout << "ѡ���������������ѡ��" << endl;
    }

    cout << "ԤԼ�ɹ��������" << endl;

    ofstream ofs;
    ofs.open(ORDER_FILE, ios::app);
    ofs << "date:" << date << " ";
    ofs << "interval:" << interval << " ";
    ofs << "stuId:" << this->m_id << " ";
    ofs << "stuName:" << this->m_name << " ";
    ofs << "roomId:" << room << " ";
    ofs << "status:" << 1 << endl; // ��1��ʾ������е�ԤԼ
}

void Student::showMyOrder() {
//    cout << "��ʾ��ǰԤԼ" << endl;
    OrderFile od; //�ڴ���od�����ʱ�򣬹��캯�����ȡORDER_FILE��ԤԼ��¼��ȡ���浽this->m_OrderData��
    if(od.m_Size == 0){
        cout << "���κ�ԤԼ��¼" << endl;
        system("read -p 'Press Enter to continue...' var");
        system("clear");
        return;
    }

    for(int i = 0; i < od.m_Size; i++){
        int index = atoi(od.m_orderData[i]["stuId"].c_str());
        if(index == this->m_id){ //�ҵ�����ԤԼ�ļ�¼
            cout << "���������ԤԼ��¼" << endl;
            od.showOrder(i);
        }
    }

}

void Student::showAllOrder() {
    OrderFile od; //�ڴ���od�����ʱ�򣬹��캯�����ȡORDER_FILE��ԤԼ��¼��ȡ���浽this->m_OrderData��
    if(od.m_Size == 0){
        cout << "��ǰ���κ�ԤԼ��¼" << endl;
        system("read -p 'Press Enter to continue...' var");
        system("clear");
        return;
    }
    cout << "��ǰ��" << od.m_Size << "��ԤԼ��¼" << endl;
    for(int i = 0; i < od.m_Size; i++){
        cout <<"��<" << i+1 << ">��ԤԼ��¼��ϢΪ��" << endl;
        od.showOrder(i);
    }
    cout << "��ʾ���" << endl;
}

void Student::cancelOrder() {
    OrderFile of;
    if(of.m_Size == 0){
        cout << "��ǰ���κ�ԤԼ��¼" << endl;
        system("read -p 'Press Enter to continue...' var");
        system("clear");
        return;
    }

    cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ����������Ҫȡ���ļ�¼" << endl;
    vector<int> v; //�����������е��±���
    int index = 1;

    for(int i = 0; i < of.m_Size; i++){
        //���ж�������ѧ�ŵ�ԤԼ��¼
        if(this->m_id == atoi(of.m_orderData[i]["stuId"].c_str())){
            //����˻���ԤԼ�ɹ��ļ�¼�ſ���ȡ��
            if(of.m_orderData[i]["status"] == "1" | of.m_orderData[i]["status"] == "2"){
                v.push_back(i);
                cout << "��"<<index ++ << "���ɱ�ȡ����ԤԼ��¼��" ;
                of.showOrder(i);
            }
        }
    }

    cout << "������Ҫȡ���ļ�¼��ţ�0������" << endl;
    int select = 0;
    while(true){
        cin >> select;
        if(select>=0 && select <=v.size()){
            if(select==0){
                break;
            }
            else{
                of.m_orderData[v[select-1]]["status"] = "0";
                of.updateOrder(); //����ԤԼ��¼��

                cout << "�Ѿ��ɹ�ȡ��ԤԼ" << endl;
                break;
            }
        }
        else{
            cout << "����ȡ������" << endl;
            break;
        }
    }
    system("read -p 'Press Enter to continue...' var");
    system("clear");
}

void Student::openMenu() {
    cout << "��ӭѧ��:" << this->m_name << "��¼" << endl;
    cout << "\t\t------------------------------\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          1.����ԤԼ          |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          2.��ʾ��ǰԤԼ      |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          3.��ʾ����ԤԼ      |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          4.ȡ��ԤԼ          |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          0.ע����¼          |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t------------------------------\n";
    cout << "����������ѡ��" << endl;
}

