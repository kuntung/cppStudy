#include <iostream>
#include "header/speechManager.h"
#include<ctime>
using namespace std;

int main() {
    //随机数种子
    srand((unsigned int) time(NULL));
//    cout<<"演讲比赛流程管理系统"<<endl;
    SpeechManager sm;
    //测试代码
//    for (auto &mit : sm.m1) {
//        cout << "编号:" << mit.first << " 姓名：" << mit.second.m_name << " 第一轮成绩：" << mit.second.m_score[0] << endl;
//    }
    int choice = 0; //用来存储用户的选项

    while (true) {
        sm.show_Menu();
        cout << "请输入您的选择:" << endl;
        cin >> choice; //接受用户的选项

        switch (choice) {
            case 1:
                //开始比赛
                sm.start_System();
                break;
            case 2:
                //查看往届记录
                sm.showRecord();
                break;
            case 3:
                //清空历史记录
                sm.clearRecord();
                break;
            case 0:
                //退出演讲比赛系统
                sm.exit_System();
                break;
            default:
                system("clear"); //清屏
                break;
        }
    }
}
