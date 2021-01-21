//
// Created by tangkun on 2021/1/21.
//

#include "header/orderFile.h"

OrderFile::OrderFile() {
    ifstream ifs;
    ifs.open(ORDER_FILE,ios::in);

    string date; //ԤԼ����
    string interval; //ԤԼʱ���
    string stuId; //ԤԼѧ��ѧ��
    string stuName; //ԤԼѧ������
    string roomId; //ԤԼ�������
    string status; //ԤԼ״̬

    this->m_Size = 0 ;
    while(ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status){
//        cout << date << endl;
//        cout << interval << endl;
        string key;
        string value;
        map<string, string> m;
        //�и�date
        m.insert(readOrder(date));
        m.insert(readOrder(interval));
        m.insert(readOrder(stuId));
        m.insert(readOrder(stuName));
        m.insert(readOrder(roomId));
        m.insert(readOrder(status));
        this->m_orderData.insert(make_pair(this->m_Size, m)); //����ȡ���и�õ�ÿ�������Զ������ʽ���뵽orderData��
        this->m_Size ++;
    }

    ifs.close();

//    cout << "����orderData" << endl;
//    cout <<"�ܹ���" << this->m_Size <<"��ԤԼ��¼Ҫ����" << endl;
//    for(int i = 0; i < this->m_Size; i++){
//        this->showOrder(i);
//    }
//    cout << "���Խ���" << endl;
    //��ʼ��������Ϣ
    ifs.open(COMPUTER_FILE, ios::in);

    this->m_roomCnt = 0;
    Computer com;
    while (ifs >> com.m_name && ifs >> com.m_size) {
        this->map_roomName.insert(make_pair(this->m_roomCnt, com.m_name)); //��������Ϣ�õ�
        this->m_roomCnt++;
    }
    ifs.close();
//    for(auto & mit : this->map_roomName){
//        cout << "����" << mit.first << " ���ƣ�" << mit.second << endl;
//    }

}

void OrderFile::updateOrder() {
    if(this->m_Size == 0){
        return;
    }
    ofstream ofs;
    ofs.open(ORDER_FILE, ios::out | ios::trunc);
    for(int i = 0; i < this->m_Size; i++){
        ofs << "date:" << this->m_orderData[i]["date"] << " ";
        ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
        ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";
        ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
        ofs << "roomId:" << this->m_orderData[i]["roomId"] << " ";
        ofs << "status:" << this->m_orderData[i]["status"] << endl;
    }

    ofs.close();
}

pair<string, string> OrderFile::readOrder(const string &orderInfo) {
    string key;
    string value;
    int pos;
//    cout << "�ɹ��и�" << orderInfo << endl;
    pos = orderInfo.find(':');
    if(pos != -1){
        key = orderInfo.substr(0, pos);
        value = orderInfo.substr(pos + 1, orderInfo.size() - pos - 1); //��ȡ�ַ���
        return make_pair(key, value);
    }
}

void OrderFile::showOrder(int i) {
    cout << "ԤԼ���ڣ���" << this->m_orderData[i]["date"] << " ";
    cout <<"ʱ��Σ�" << (this->m_orderData[i]["interval"] == "1" ? "����":"����") << " ";
    cout << "������:" <<  this->m_orderData[i]["roomId"] << " ";
    string roomName = "����"; //���ݻ����������ȡ��������
    roomName += this->getRoomName(atoi(this->m_orderData[i]["roomId"].c_str()));
    string status = "״̬:" ; //0 ȡ����ԤԼ 1 ����е�ԤԼ 2 ��ԤԼ -1 ԤԼʧ��
    if(this->m_orderData[i]["status"] == "1"){
        status += "�����";
    }
    else if(this->m_orderData[i]["status"] == "2"){
        status += "ԤԼ�ɹ�";
    }
    else if(this->m_orderData[i]["status"] == "-1"){
        status += "ԤԼʧ��";
    } else{
        status += "ȡ����ԤԼ";
    }
    cout <<"ԤԼ�Ļ������ƣ�" << roomName << endl;
    cout <<status << endl;


}

string OrderFile::getRoomName(int roomId) {
    return this->map_roomName[roomId-1];

}
