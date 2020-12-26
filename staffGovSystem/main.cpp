//
// Created by tangkun on 2020/12/25.
//

#include <iostream>
#include "header/workerManager.h"

using namespace std;

void test01(){
    Worker *worker = nullptr;

    worker = new Employee(1, "张三",1);
    worker->show_info();
    delete worker;

    worker = new Manager(2,"李四",2);
    worker->show_info();
    delete worker;

    worker = new Boss(3,"王五",3);
    worker->show_info();
    delete worker;

}

int main() {
    //生成职工管理系统
    WorkerManager WMSystem;
    int choice = 0;
    while(true){
        WMSystem.show_menu();
        cout<<"请输入你的选择:"<<endl;
        cin>>choice;
        switch(choice){
            case 0: //退出系统
                WMSystem.exit_system();
                break;
            case 1: //增加职工信息
                WMSystem.add_Emp();
                break;
            case 2: //显示职工信息
                WMSystem.show_Emp();
                break;
            case 3: //删除离职职工
            {
                //先查找是否存在该职工
                cout << "您是想按照职工编号还是职工姓名来删除员工相关信息？" << endl;
                string del_choice;
                cin >> del_choice;
                if (del_choice == "姓名") {
                    string del_name;
                    cout << "请输入你要删除的职工名字:" << endl;
                    cin >> del_name;
                    WMSystem.del_Emp(del_name);
                } else if (del_choice == "编号") {
                    int del_id;
                    cout << "请输入你要删除的职工编号:" << endl;
                    cin >> del_id;
                    WMSystem.del_Emp(del_id);
                }
                break;
            }
            case 4: //修改职工信息
                break;
            case 5: //查找职工信息
                break;
            case 6: //职工信息排序
                break;
            case 7:  //清空所有文档
                break;
            default:  //无操作
                system("cls");  //清屏操作
                break;
        }
    }

    system("pause");
    return 0;
}
