//
// Created by tangkun on 2021/1/21.
//

#include "header/orderFile.h"

OrderFile::OrderFile() {
    ifstream ifs;
    ifs.open(ORDER_FILE,ios::in);

    string date; //预约日期
    string interval; //预约时间段
    string stuId; //预约学生学号
    string stuName; //预约学生姓名
    string roomId; //预约机房编号
    string status; //预约状态

    this->m_Size = 0 ;
    while(ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status){
//        cout << date << endl;
//        cout << interval << endl;
        string key;
        string value;
        map<string, string> m;
        //切割date
        m.insert(readOrder(date));
        m.insert(readOrder(interval));
        m.insert(readOrder(stuId));
        m.insert(readOrder(stuName));
        m.insert(readOrder(roomId));
        m.insert(readOrder(status));
        this->m_orderData.insert(make_pair(this->m_Size, m)); //将读取并切割好的每条数据以对组的形式插入到orderData中
        this->m_Size ++;
    }

    ifs.close();

//    cout << "测试orderData" << endl;
//    cout <<"总共有" << this->m_Size <<"条预约记录要测试" << endl;
//    for(int i = 0; i < this->m_Size; i++){
//        this->showOrder(i);
//    }
//    cout << "测试结束" << endl;
    //初始化机房信息
    ifs.open(COMPUTER_FILE, ios::in);

    this->m_roomCnt = 0;
    Computer com;
    while (ifs >> com.m_name && ifs >> com.m_size) {
        this->map_roomName.insert(make_pair(this->m_roomCnt, com.m_name)); //将机房信息拿到
        this->m_roomCnt++;
    }
    ifs.close();
//    for(auto & mit : this->map_roomName){
//        cout << "机房" << mit.first << " 名称：" << mit.second << endl;
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
//    cout << "成功切割" << orderInfo << endl;
    pos = orderInfo.find(':');
    if(pos != -1){
        key = orderInfo.substr(0, pos);
        value = orderInfo.substr(pos + 1, orderInfo.size() - pos - 1); //截取字符串
        return make_pair(key, value);
    }
}

void OrderFile::showOrder(int i) {
    cout << "预约日期：周" << this->m_orderData[i]["date"] << " ";
    cout <<"时间段：" << (this->m_orderData[i]["interval"] == "1" ? "上午":"下午") << " ";
    cout << "机房号:" <<  this->m_orderData[i]["roomId"] << " ";
    string roomName = "机房"; //根据机房编号来读取机房名字
    roomName += this->getRoomName(atoi(this->m_orderData[i]["roomId"].c_str()));
    string status = "状态:" ; //0 取消的预约 1 审核中的预约 2 已预约 -1 预约失败
    if(this->m_orderData[i]["status"] == "1"){
        status += "审核中";
    }
    else if(this->m_orderData[i]["status"] == "2"){
        status += "预约成功";
    }
    else if(this->m_orderData[i]["status"] == "-1"){
        status += "预约失败";
    } else{
        status += "取消的预约";
    }
    cout <<"预约的机房名称：" << roomName << endl;
    cout <<status << endl;


}

string OrderFile::getRoomName(int roomId) {
    return this->map_roomName[roomId-1];

}
