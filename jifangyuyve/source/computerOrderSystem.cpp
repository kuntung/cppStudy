//
// Created by tangkun on 2021/1/16.
//

#include "header/computerOrderSystem.h"

OrderManager::OrderManager() {

}

void OrderManager::show_menu() {
    cout << "=============== 欢迎来到机房预约系统 ===============" << endl;
    cout << endl << "请输入您的身份" << endl;
    cout << "\t\t------------------------------\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          1.学    生         |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          2.教    师         |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          3.管 理 员         |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          4.查    看         |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          0.退    出         |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t------------------------------\n";
}

void OrderManager::LoginIn(const string &fileName, int type) {
    Identity *person = nullptr; //父类指针，用于指向子类对象。多态

    //先创建目标文件
//    ofstream ofs(fileName, ios::trunc);
//    cout<<"删除创建成功"<<endl;
//    ofs.close();
    ifstream ifs(fileName, ios::in);

    //判断文件是否存在
    if (!ifs.is_open()) {
        cout << "文件不存在" << endl;
        ifs.close();
        return;
    }
    char ch;
    ifs >> ch;
    if (ifs.is_open()) { //文件没有数据
        if (ifs.eof()) {
            cout << "文件为空" << endl;
            ifs.close();
            return;
        }
    }
    ifs.putback(ch); //将上面读取的单个字符放回来
    //文件存在且不为空情况
    int id = 0;
    string name;
    string pwd;

    //判断身份
    if (type == 1) { //学生身份
        cout << "请输入你的学号：" << endl;
        cin >> id;
    } else if (type == 2) {
        cout << "请输入您的职工号:" << endl;
        cin >> id;
    }

    cout << "请输入用户名：" << endl;
    cin >> name;

    cout << "请输入密码：" << endl;
    cin >> pwd;
    int fId; //从文件中获取的ID号
    string fName; //从文件中获取的姓名
    string fPwd; //从文件中获取密码
    while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
        //与用户输入的信息进行对比
        if (fId == id && fName == name && fPwd == pwd) {
            if (type == 1) { //学生身份验证
                cout << "学生验证登录成功" << endl;
                system("read -p 'Press Enter to continue...' var");
                system("clear");
                person = new Student(id, name, pwd);
                //进入学生子菜单

                return;
            } else if (type == 2) { //教师身份验证
                cout << "教师验证登录成功" << endl;
                system("read -p 'Press Enter to continue...' var");
                system("clear");
                person = new Teacher(id, name, pwd);
                //进入教师子菜单

                return;
            }
        }
    }
    //对于管理员，少一个属性，需要单独匹配
    while (ifs >> fName && ifs >> fPwd) {
        if (fName == name && fPwd == pwd) {
            cout << "管理员验证登录成功" << endl;
            system("read -p 'Press Enter to continue...' var");
            system("clear");
            person = new Manager(name, pwd);
            //进入管理员子菜单

            return;
        }
    }

    cout << "验证登录失败！" << endl;

    system("read -p 'Press Enter to continue...' var");
    system("clear");
}

void OrderManager::preDefine(const string &fileName, int type) {
    ofstream ofs;
    ofs.open(fileName, ios::out | ios::app); //用追加的方式写文件
    //判断文件是否存在
    if (!ofs.is_open()) {
        cout << "文件不存在" << endl;
        ofs.close();
        return;
    }
    int id = 0;
    string name;
    string pwd;
    //将每个选手数据写入到文件中
    if (type == 1) {
        cout << "请输入要添加的学生相关信息：" << endl;
        cout << "学号：";
        cin >> id;
    } else if (type == 2) {
        cout << "请输入要添加的教师相关信息：" << endl;
        cout << "职工号：";
        cin >> id;
    } else if (type == 3) {
        cout << "请输入管理员信息：";
    }
    cout << "请输入添加的姓名：";
    cin >> name;
    cout << "请输入预设密码：";
    cin >> pwd;
    if (type == 3) {
        ofs << name << " " << pwd << endl;
    } else {
        ofs << id << " " << name << " " << pwd << endl;
    }
    ofs.close();
    cout << "添加成功！";
}

void OrderManager::cleanFile(const string &fileName, int type) {


}

void OrderManager::loadFile(const string &fileName, int type) { //查看目标文件的所有信息
    ifstream ifs(fileName, ios::in);

    //判断文件是否存在
    if (!ifs.is_open()) {
        cout << "文件不存在" << endl;
        ifs.close();
        return;
    }
    char ch;
    ifs >> ch;
    if (ifs.is_open()) { //文件没有数据
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
            cout << "文件为空" << endl;
            ifs.close();
            return;
        }
    }
    ifs.putback(ch); //将上面读取的单个字符放回来

    //文件存在且不为空情况
    string lineData;
    int index = 0; //第0个数据
    while(ifs >> lineData){
        //截取数据
        vector<string> vs;
        int pos = -1; //查找到" "的位置
        int start = 0;
        while(true){
            pos = lineData.find(",", start);
            if (pos == -1) {
                //没有找到清空
                break;
            }
            string temp = lineData.substr(start, pos - start);
//            cout << temp << endl;
            vs.push_back(temp);
            start = pos + 1;
        }
        this->infoVector.insert(make_pair(index, vs)); //将读取出来的数据保存
        index++;
        }

    ifs.close();
}
