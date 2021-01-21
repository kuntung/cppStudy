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

    //初始化机房信息
    ifstream ifs;
    ifs.open(COMPUTER_FILE, ios::in);

    Computer com;
    while (ifs >> com.m_name && ifs >> com.m_size) {
        this->svCom.push_back(com); //将机房信息拿到
    }
    ifs.close();
}


void Student::applyOrder() {
//    cout << "申请预约" <<endl;
    cout << "机房开放时间为周一到周五！" << endl;
    cout << "请输入申请预约的时间：" << endl;
    cout << "1.周一" << endl;
    cout << "2.周二" << endl;
    cout << "3.周三" << endl;
    cout << "4.周四" << endl;
    cout << "5.周五" << endl;

    int date = 0; //日期
    int interval = 0; //时间段
    int room = 0; //机房编号
    while (true) {
        cin >> date;
        if (date >= 1 && date <= 5) {
            break;
        } else {
            cout << "输入有误，请重新输入" << endl;
        }
    }
    cout << "请输入预约的时间段" << endl;
    cout << "1.上午" << endl;
    cout << "2.下午" << endl;
    while (true) {
        cin >> interval;
        if (interval >= 1 && interval <= 2) {
            break;
        }
        cout << "请选择正确的时间段" << endl;
    }
    cout << "请选择机房：" << endl;
    for (int i = 0; i < this->svCom.size(); i++) { //打印输出每个机房的容量
        cout << "第<" << i + 1 << ">个机房名称：" << this->svCom[i].m_name << "机房的容量为：" << this->svCom[i].m_size << endl;
    }

    while (true) {
        cin >> room;
        if (room >= 1 && room <= this->svCom.size()) {
            break;
        }
        cout << "选择机房出错，请重新选择" << endl;
    }

    cout << "预约成功！审核中" << endl;

    ofstream ofs;
    ofs.open(ORDER_FILE, ios::app);
    ofs << "date:" << date << " ";
    ofs << "interval:" << interval << " ";
    ofs << "stuId:" << this->m_id << " ";
    ofs << "stuName:" << this->m_name << " ";
    ofs << "roomId:" << room << " ";
    ofs << "status:" << 1 << endl; // 用1表示待审核中的预约
}

void Student::showMyOrder() {
//    cout << "显示当前预约" << endl;
    OrderFile od; //在创建od对象的时候，构造函数会读取ORDER_FILE并预约记录读取保存到this->m_OrderData中
    if(od.m_Size == 0){
        cout << "无任何预约记录" << endl;
        system("read -p 'Press Enter to continue...' var");
        system("clear");
        return;
    }

    for(int i = 0; i < od.m_Size; i++){
        int index = atoi(od.m_orderData[i]["stuId"].c_str());
        if(index == this->m_id){ //找到自身预约的记录
            cout << "存在自身的预约记录" << endl;
            od.showOrder(i);
        }
    }

}

void Student::showAllOrder() {
    OrderFile od; //在创建od对象的时候，构造函数会读取ORDER_FILE并预约记录读取保存到this->m_OrderData中
    if(od.m_Size == 0){
        cout << "当前无任何预约记录" << endl;
        system("read -p 'Press Enter to continue...' var");
        system("clear");
        return;
    }
    cout << "当前有" << od.m_Size << "条预约记录" << endl;
    for(int i = 0; i < od.m_Size; i++){
        cout <<"第<" << i+1 << ">条预约记录信息为：" << endl;
        od.showOrder(i);
    }
    cout << "显示完毕" << endl;
}

void Student::cancelOrder() {
    OrderFile of;
    if(of.m_Size == 0){
        cout << "当前无任何预约记录" << endl;
        system("read -p 'Press Enter to continue...' var");
        system("clear");
        return;
    }

    cout << "审核中或预约成功的记录可以取消，请输入要取消的记录" << endl;
    vector<int> v; //存放最大容器中的下标编号
    int index = 1;

    for(int i = 0; i < of.m_Size; i++){
        //先判断是自身学号的预约记录
        if(this->m_id == atoi(of.m_orderData[i]["stuId"].c_str())){
            //在审核或者预约成功的记录才可以取消
            if(of.m_orderData[i]["status"] == "1" | of.m_orderData[i]["status"] == "2"){
                v.push_back(i);
                cout << "第"<<index ++ << "条可被取消的预约记录：" ;
                of.showOrder(i);
            }
        }
    }

    cout << "请输入要取消的记录编号，0代表返回" << endl;
    int select = 0;
    while(true){
        cin >> select;
        if(select>=0 && select <=v.size()){
            if(select==0){
                break;
            }
            else{
                of.m_orderData[v[select-1]]["status"] = "0";
                of.updateOrder(); //更新预约记录表

                cout << "已经成功取消预约" << endl;
                break;
            }
        }
        else{
            cout << "放弃取消操作" << endl;
            break;
        }
    }
    system("read -p 'Press Enter to continue...' var");
    system("clear");
}

void Student::openMenu() {
    cout << "欢迎学生:" << this->m_name << "登录" << endl;
    cout << "\t\t------------------------------\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          1.申请预约          |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          2.显示当前预约      |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          3.显示所有预约      |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          4.取消预约          |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          0.注销登录          |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t------------------------------\n";
    cout << "请输入您的选择：" << endl;
}

