//
// Created by tangkun on 2021/1/16.
//

#include "header/computerOrderSystem.h"

OrderManager::OrderManager() {
    this->init();
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
    if(type == 1 || type == 2) {
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
                    this->studentMenu(person);
                    return;
                } else if (type == 2) { //教师身份验证
                    cout << "教师验证登录成功" << endl;
                    system("read -p 'Press Enter to continue...' var");
                    system("clear");
                    person = new Teacher(id, name, pwd);
                    //进入教师子菜单
                    this->tearcherMenu(person);
                    return;
                }
            }
        }
    }
    else if(type == 3){
        string fName; //从文件中获取的姓名
        string fPwd; //从文件中获取密码
        //对于管理员，少一个属性，需要单独匹配
        while (ifs >> fName && ifs >> fPwd) {
            if (fName == name && fPwd == pwd) {
                cout << "管理员验证登录成功" << endl;
                system("read -p 'Press Enter to continue...' var");
                system("clear");
                person = new Manager(name, pwd);
                //进入管理员子菜单
                this->managerMenu(person);// Identity* &person = new Manager(name, pwd); //父类指针指向子类对象的引用，多态
                return;
            }
        }
    }


    cout << "验证登录失败！" << endl;

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

void OrderManager::cleanFile(int type) {
    cout << "确认清空？" << endl;
    cout << "1.确认" << endl;
    cout << "2.返回" << endl;

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
        //打开模式ios::trunc，如果存在则删除文件并重新创建
        ofstream ofs(fileName, ios::trunc);
        ofs.close();
        //初始化属性

        cout << "清空成功" << endl;

    }
    system("read -p 'Press Enter to continue...' var");
    system("clear");

}

void OrderManager::loadFile(const string &fileName, int type) { //查看目标文件的所有信息
    this->init(); //在每次读取的开始清空容器
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
            if (type == 1) {
                this->StudentFileIsEmpty = true;
            } else if (type == 2) {
                this->TeacherFileIsEmpty = true;
            } else if (type == 3) {
                this->ManagerFileIsEmpty = true;
            }
            cout << "文件为空" << endl;
            ifs.close();
            return;
        }
    }
    ifs.putback(ch); //将上面读取的单个字符放回来

    //文件存在且不为空情况
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
        cout << "以下是管理员相关信息：" << endl;
        for (int i = 0; i < this->fNameV.size(); i++) {
            cout << "第" << i + 1 << "条数据：" << " 管理员姓名:" << this->fNameV[i]
                 << " 密码：" << this->fPwdV[i] << endl;
        }
    } else if (type == 1 && !this->StudentFileIsEmpty) {
        cout << "以下是学生相关信息：" << endl;
        for (int i = 0; i < this->fNameV.size(); i++) {
            cout << "第" << i + 1 << "条数据：" << "学号：" << this->fidV[i] << " 用户名：" << this->fNameV[i] << " 密码："
                 << this->fPwdV[i] << endl;
        }
    } else if (type == 2 && !this->TeacherFileIsEmpty) {
        cout << "以下是教师相关信息：" << endl;
        for (int i = 0; i < this->fNameV.size(); i++) {
            cout << "第" << i + 1 << "条数据：" << "职工号：" << this->fidV[i] << " 用户名：" << this->fNameV[i] << " 密码："
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

void OrderManager::managerMenu(Identity *&manager) { //传入参数类型：对于Identity*类型的引用
    while (true) {
        //调用管理员子菜单
        manager->openMenu();

        //将父类指针转为子类指针，调用子类里其他接口
        Manager *man = (Manager *) manager;

        int select = 0;
        cin >> select;
        switch (select) { //管理员子菜单
            case 1://账号管理
                man->clientAction();
                break;
            case 2: //机房管理
                man->computerAction();
                break;
            case 3: //预约管理
                man->cleanFile(ORDER_FILE);
                break;
            default: //默认情况，注销登录
                delete manager;
                cout << "注销成功" << endl;
                system("read -p 'Press Enter to continue...' var");
//                system("clear");
                return;
        }
    }
}

void OrderManager::tearcherMenu(Identity *&teacher) {
    while (true) {
        //调用管理员子菜单
        teacher->openMenu();

        //将父类指针转为子类指针，调用子类里其他接口
        Teacher *teac = (Teacher *) teacher;

        int select = 0;
        cin >> select;
        switch (select) {
            case 1://显示所有预约
                teac->showAllOrder();
                break;
            case 2: //审核预约
                teac->validOrder();
                break;
            default: //默认情况，注销登录
                delete teacher;
                cout << "注销成功" << endl;
                system("read -p 'Press Enter to continue...' var");
//                system("clear");
                return;
        }
    }
}

void OrderManager::studentMenu(Identity *&student) {
    while (true) {
        //调用学生子菜单
        student->openMenu();

        //将父类指针转为子类指针，调用子类里其他接口
        Student *stu = (Student *) student;

        int select = 0;
        cin >> select;
        switch (select) {
            case 1://申请预约
                stu->applyOrder();
                break;
            case 2: //显示自己的预约情况
                stu->showMyOrder();
                break;
            case 3: //显示所有预约
                stu->showAllOrder();
                break;
            case 4: //取消预约
                stu->cancelOrder();
                break;
            default: //默认情况，注销登录
                delete student;
                cout << "注销成功" << endl;
                system("read -p 'Press Enter to continue...' var");
                system("clear");
                return;
        }
    }
}
