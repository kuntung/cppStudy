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
    cout << "欢迎教师:" << this->m_name << "登录" << endl;
    cout << "\t\t------------------------------\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          1.查看所有预约      |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          2.审核预约          |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          0.注销登录          |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t------------------------------\n";
    cout << "请输入您的选择：" << endl;
}

void Teacher::showAllOrder() {
    Student st;
    st.showAllOrder();

}

void Teacher::validOrder() {
    while (true) {
        OrderFile od; //在创建od对象的时候，构造函数会读取ORDER_FILE并预约记录读取保存到this->m_OrderData中
        if (od.m_Size == 0) {
            cout << "当前无任何预约记录" << endl;
            system("read -p 'Press Enter to continue...' var");
            system("clear");
            return;
        }

        //　教师进行预约记录审核工作
        cout << "待审核的预约记录如下：" << endl;
        vector<int> v; //用来记录待审核的预约在最大容器中的下标
        int index = 0;
        for (int i = 0; i < od.m_Size; i++) {
            if (od.m_orderData[i]["status"] == "1") { //所有待审核容器
                v.push_back(i);
                cout << "第<" << ++index << ">条待审核预约记录：";
                od.showOrder(i); //打印显示具体的预约记录
            }
        }
        if(v.size() == 0){
            break;
        }
        cout << "请输入审核的预约记录编号" << endl;
        int select = 0; //接受用户选择的预约记录
        int ret = 0; //接受预约审核结果
        while (true) {
            cin >> select;
            if (select >= 0 || select <= v.size()) {
                if (select == 0) {
                    cout << "取消当前审核工作" << endl;
                    break;
                } else {
                    cout << "请输入审核结果" << endl;
                    cout << "1.通过" << endl;
                    cout << "2.不通过" << endl;
                    cin >> ret;
                    if (ret == 1) {
                        od.m_orderData[v[select - 1]]["status"] = "2"; //审核通过
                    } else {
                        od.m_orderData[v[select - 1]]["status"] = "-1"; //审核不通过
                    }
                    od.updateOrder(); //更新审核后的预约记录
                    cout << "审核完毕" << endl;
                    break;
                }
            }
            cout << "输入有误，请重新输入" << endl;
        }
    }
    cout << "全部审核完毕" << endl;
    system("read -p 'Press Enter to continue...' var");
    system("clear");

}
