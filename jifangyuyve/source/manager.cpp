//
// Created by tangkun on 2021/1/16.
//

#include "header/manager.h"

void printStudent(Student &student) { //打印学生信息的普通函数
    cout << "学号:" << student.m_id << " 姓名:" << student.m_name << " 密码:" << student.m_pwd << endl;

}

void printTeacher(Teacher &teacher) { //打印学生信息的普通函数
    cout << "职工号:" << teacher.m_empId << " 姓名:" << teacher.m_name << " 密码:" << teacher.m_pwd << endl;

}

void printComputerRoom(Computer &computer) { //逐个打印机房信息的普通函数
    cout << computer.m_name << "，容量:" << computer.m_size << endl;
}

Manager::Manager() {

}

Manager::Manager(string name, string pwd) {
    this->m_name = name;
    this->m_pwd = pwd;
    this->initVector();
}

void Manager::openMenu() {
    cout << "欢迎管理员:" << this->m_name << "登录" << endl;
    cout << "\t\t------------------------------\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          1.管理账号          |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          2.管理机房          |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          3.清空预约          |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          0.注销登录          |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t------------------------------\n";
    cout << "请输入您的选择：" << endl;
}

void Manager::clientMenu() {
        cout << "欢迎管理员:" << this->m_name << "登录" << endl;
        cout << "\t\t------------------------------\n";
        cout << "\t\t|                            |\n";
        cout << "\t\t|          1.添加账号          |\n";
        cout << "\t\t|                            |\n";
        cout << "\t\t|          2.查看账号          |\n";
        cout << "\t\t|                            |\n";
        cout << "\t\t|          3.删除账号          |\n";
        cout << "\t\t|                            |\n";
        cout << "\t\t|          4.清空账号         |\n";
        cout << "\t\t|                            |\n";
        cout << "\t\t|          5.修改密码         |\n";
        cout << "\t\t|                            |\n";
        cout << "\t\t|          0.注销登录         |\n";
        cout << "\t\t|                            |\n";
        cout << "\t\t------------------------------\n";
        cout << "请输入您的选择：" << endl;

}

void Manager::clientAction() {
    while (true) {
        this->clientMenu();
        int select = 0;
        cin >> select;
        switch (select) { //账号管理
            case 1://添加账号
                this->addPerson();
                break;
            case 2: //查看账号
                this->showPerson();
                break;
            case 3: //删除账号
                cout << "删除账号" << endl;
                break;
            case 4:
                cout << "请输入要清空的账号类型： " << endl;
                cout << "1.学生" << endl;
                cout << "2.教师" << endl;
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
                cout << "请输入要修改的账户类型：" << endl;
                cout << "1.学生" << endl;
                cout << "2.教师" << endl;
                cin >> type;
                this->editClient(type);
                break;  //忘记添加break语句，导致default接着执行
            default: //默认情况，注销登录
                cout << "注销成功" << endl;
                system("read -p 'Press Enter to continue...' var");
                system("clear");
                return;
        }
    }

}

void Manager::computerMenu() {
    cout << "欢迎管理员:" << this->m_name << "登录" << endl;
    cout << "\t\t------------------------------\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          1.添加机房          |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          2.显示机房          |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          3.修改机房          |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          4.重置机房         |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t|          0.注销登录         |\n";
    cout << "\t\t|                            |\n";
    cout << "\t\t------------------------------\n";
    cout << "请输入您的选择：" << endl;
}

void Manager::computerAction() {
    while (true) {
        this->computerMenu();
        int select = 0;
        cin >> select; //获取用户的机房操作
        if (select == 1) {
            this->addComputerRoom();
        } else if (select == 2) { //显示机房
            this->showComputer();
        } else if (select == 3) { //修改机房
            this->showComputer();
            this->editComputerRoom();
        }
        else if(select == 4){
            this->cleanFile(COMPUTER_FILE); //重置机房信息
        }
        else{
            cout << "注销不成功" << endl;
            system("read -p 'Press Enter to continue...' var");
            system("clear");
            return;
        }
    }

}
void Manager::addPerson() {
    cout << "请输入要添加的账号类型:" << endl;
    cout << "1.添加学生" << endl;
    cout << "2.添加老师" << endl;

    int type = 0;
    cin >> type;
    string fileName; //操作文件名
    string tip; //提示信息
    string errorTip; //重复错误提示
    if (type == 1) {
        fileName = STUDENT_FILE;
        tip = "请输入要添加的学生相关信息：\n学号：";
        errorTip = "学号重复，请重新输入!\n学号：";
    } else if (type == 2) {
        fileName = TEACHER_FILE;
        tip = "请输入要添加的教师相关信息：\n职工号：";
        errorTip = "职工号重复，请重新输入!\n职工号:";

    } else if (type == 3) {
        fileName = ADMIN_FILE;
        tip = "请输入管理员信息：";
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
    //进行去重操作
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
    cout << "姓名：";
    cin >> name;
    cout << "预设密码：";
    cin >> pwd;
    if (type == 3) {
        ofs << name << " " << pwd << endl;
        cout << "添加成功！" << endl;
    } else if (type == 1 || type == 2) {
        ofs << id << " " << name << " " << pwd << endl;
        cout << "添加成功！" << endl;
    } else {
        cout << "请输入正确的人员类型。" << endl;
        cout << "添加失败" << endl;
    }
    ofs.close();
    this->initVector(); //调用初始化容器接口，重新获取文件中的数据
    system("read -p 'Press Enter to continue...' var");
    system("clear");

}

void Manager::showPerson() {
    cout << "请选择查看的内容：" << endl;
    cout << "1. 查看所有学生" << endl;
    cout << "2. 查看所有老师" << endl;

    int select = 0; //接受用户选择
    cin >> select;
    if (select == 1) {
        //查看所有学生
        cout << "所有学生信息如下: " << endl;
        for_each(this->vStu.begin(), this->vStu.end(), printStudent); //通过传入仿函数或者普通函数
    } else if (select == 2) {
        cout << "所有教师的信息如下：" << endl;
        for_each(this->vTea.begin(), this->vTea.end(), printTeacher); //通过传入仿函数或者普通函数
    }

    system("read -p 'Press Enter to continue...' var");
    system("clear");
}

void Manager::showComputer() {
    cout << "当前机房的情况如下:" << endl;
    for_each(this->vCom.begin(), this->vCom.end(), printComputerRoom); //通过传入仿函数或者普通函数
}

void Manager::cleanFile(const string & filename) {
    ofstream ofs(filename, ios::trunc); // 清空目标文件
    ofs.close();

    cout << "清空成功" << endl;
    system("read -p 'Press Enter to continue...' var");
    system("clear");

    this->initVector();
}

void Manager:: initVector() {
    //确保文件是清空状态
    this->vStu.clear();
    this->vTea.clear();
    this->vCom.clear();
    //读取信息 学生、老师
    ifstream ifs;
    ifs.open(STUDENT_FILE, ios::in);
    if (!ifs.is_open()) {
        cout << "文件读取失败" << endl;
        return;
    }

    //读取学生信息
    Student s;
    while (ifs >> s.m_id && ifs >> s.m_name && ifs >> s.m_pwd) {
        this->vStu.push_back(s);
    }

    cout << "当前学生数量为:" << this->vStu.size() << endl;
    ifs.close();

    //读取教师信息
    ifs.open(TEACHER_FILE, ios::in);
    if (!ifs.is_open()) {
        cout << "文件读取失败" << endl;
        return;
    }
    Teacher tea;
    while (ifs >> tea.m_empId && ifs >> tea.m_name && ifs >> tea.m_pwd) {
        this->vTea.push_back(tea);
    }

    cout << "当前老师数量为:" << this->vTea.size() << endl;

    ifs.close();

    //读取机房信息
    ifs.open(COMPUTER_FILE, ios::in);
    if (!ifs.is_open()) {
        cout << "文件读取失败" << endl;
        return;
    }
    Computer computer;
    while (ifs >> computer.m_name && ifs >> computer.m_size) {
        this->vCom.push_back(computer);
    }

    cout << "当前机房数量为:" << this->vCom.size() << endl;

    ifs.close();
}

bool Manager::checkRepeat(int id, int type) { //id为待检测的学号、职工号，type为检测类别
    if (type == 1) {
        //遍历学生容器中的学号，判断是否有重复
        for (auto &svit : this->vStu) {
            if (svit.m_id == id) {
                return true;
            }
        }
    } else if (type == 2) {
        //遍历老师容器中的职工号，判断是否有重复
        for (auto &tvit : this->vTea) {
            if (tvit.m_empId == id) {
                return true;
            }
        }
    }
    return false;
}

bool Manager::checkRepeat(const string &name) { //name为拟确定的机房名称
    for (auto &cvit : this->vCom) {
        if (cvit.m_name == name) {
            return true;
        }
    }
    return false;
}

void Manager::manageComputer() {
    int select = 0;
    cin >> select; //获取用户的机房操作
    if (select == 1) {
        string name; //拟定机房名称
        int size = 0; //新机房容量
        ofstream ofs;
        ofs.open(COMPUTER_FILE, ios::out | ios::app); //以追加的形式写入新的机房信息
        cout << "请输入新机房的名称:" << endl;
        while (true) {
            cin >> name;
            bool ret = checkRepeat(name);
            if (ret) {
                cout << "机房名称冲突，请重新输入\n新机房名称：" << endl;
            } else {
                break;
            }
        }
        cout << "请输入新机房的容量：" << endl;
        cin >> size;
        ofs << name <<" "<< size << endl;
        cout << "添加新机房成功！" << endl;
        ofs.close(); //关闭文件
        this->initVector(); //添加完机房信息后立刻更新
    } else if (select == 2) {
        this->showComputer();
        cout << "修改机房信息" << endl;
    } else if (select == 3) {
        this->showComputer();
        system("read -p 'Press Enter to continue...' var");
        system("clear");
    }
}

void Manager::addComputerRoom() {
    string name; //拟定机房名称
    int size = 0; //新机房容量
    ofstream ofs;
    ofs.open(COMPUTER_FILE, ios::out | ios::app); //以追加的形式写入新的机房信息
    cout << "请输入新机房的名称:" << endl;
    while (true) {
        cin >> name;
        bool ret = checkRepeat(name);
        if (ret) {
            cout << "机房名称冲突，请重新输入\n新机房名称：" << endl;
        } else {
            break;
        }
    }
    cout << "请输入新机房的容量：" << endl;
    cin >> size;
    ofs << name <<" "<< size << endl;
    cout << "添加新机房成功！" << endl;
    ofs.close(); //关闭文件
    this->initVector(); //添加完机房信息后立刻更新
}

void Manager::editComputerRoom() {
    cout << "请输入要修改的机房名称：" << endl;
    string roomName;
    vector<Computer>::iterator findName;
    while (true){  //查找是否存在这样的机房名称
        cin >> roomName;
        //
        findName = find(this->vCom.begin(), this->vCom.end(), roomName);
        if(findName == this->vCom.end()){
            cout << "不存在名为" << roomName << "的机房。请重新输入" << endl;
        }
        else{
            break;
        }
    }
    cout << "请输入新机房的名称：" << endl;
    string newRoomName;
    while (true){
        cin >> newRoomName;
        //
        findName = find(this->vCom.begin(), this->vCom.end(), newRoomName);
        if(findName == this->vCom.end()){
            break;
        }
        else{
            cout << "已经存在名为" << newRoomName << "的机房。请重新输入" << endl;
        }
    }
    //替换找到位置的机房名称
    cout << "请输入新机房<" << newRoomName << ">的容量:" << endl;
    int newSize;
    while(true){
        cin >> newSize;
        if(newSize > 0){
            break;
        }
        else{
            cout << "请输入正确的容量值！" << endl;
        }
    }
    Computer newComputer;
    newComputer.m_name = newRoomName;
    newComputer.m_size = newSize;
    replace_if(this->vCom.begin(),this->vCom.end(),[&](const Computer& c)->bool {
        c.m_name == roomName;},newComputer);
    //打印显示新机房信息
    this->showComputer();
    this->editFile(3); //将新的机房容器写入到文件中
    //将新机房信息写入文件中。可以考虑构建一个写入模板。
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
            cout << "修改学生账号信息成功" << endl;
            break;
        case 2:
            filename = TEACHER_FILE;
            ofs.open(filename, ios::trunc);
            for(auto & vit : this->vTea){
                ofs << vit.m_empId <<" " << vit.m_name << " " << vit.m_pwd << endl;
            }
            cout << "修改教师账号信息成功" << endl;
            break;
        case 3:
            filename = COMPUTER_FILE;
            ofs.open(filename, ios::trunc);
            for(auto & vit : this->vCom){
                ofs << vit.m_name << " " << vit.m_size << endl;
            }
            cout << "修改机房信息成功" << endl;
            break;
        default:
            cout << "请输入正确的文件类型～" << endl;
    }
    ofs.close();
    this->initVector(); //重新加载最新的相关信息
}

void Manager::editClient(int type) {
    cout << "请输入要修改密码的用户ID：" << endl;
    int clientID;
    string newPWD;  //要修改的新密码
    while(true){ //如果学号匹配失败
        cin >> clientID;
        if(!checkRepeat(clientID, type)){
            cout << "不存在该用户，是否添加？" << endl;
            cout << "1.添加" << endl;
            cout << "2.取消" << endl;
            int select;
            cin >> select;
            if(select == 1){
                string extraName; //对于未找到清空，需要添加时的姓名
                string extraPwd; //需要添加的密码
                cout << "请输入该ID对应的姓名：" << endl;
                cin >> extraName;
                cout << "请输入该ID对应的密码：" << endl;
                cin >> extraPwd;
                if(type == 1){
                    Student temp(clientID, extraName, extraPwd);
                    this->vStu.push_back(temp);
                    cout << "添加成功" << endl;
                }
                else if(type == 2){
                    Teacher temp(clientID, extraName, extraPwd);
                    this->vTea.push_back(temp);
                    cout << "添加成功" << endl;
                }
                return;
            }
            else{
                break;
            }
        }

    }
    if(type == 1){ //学号匹配成功
        auto findID = find(this->vStu.begin(), this->vStu.end(), clientID);
        cout << "匹配到学号为：" << clientID << "的用户。" << endl;
        cout << "姓名：" << findID->m_name << "密码：" << findID->m_pwd << endl;
        cout << "请输入新的密码：" << endl;
        cin >> newPWD;
        Student tempStu = *findID;
        tempStu.m_pwd = newPWD;
        replace_if(this->vStu.begin(), this->vStu.end(), [&](const Student& s)->bool {
            return s.m_id == clientID;}, tempStu);    //将修改后的信息替换
    }
    else if(type == 2){ //职工号匹配成功
        auto findID = find(this->vTea.begin(), this->vTea.end(), clientID);
        cout << "匹配到职工号为：" << clientID << "的用户。" << endl;
        cout << "姓名：" << findID->m_name << "密码：" << findID->m_pwd << endl;
        cout << "请输入新的密码：" << endl;
        cin >> newPWD;
        Teacher tempTea = *findID;
        tempTea.m_pwd = newPWD;
        replace_if(this->vTea.begin(), this->vTea.end(), [&](const Teacher& t)->bool {
            return t.m_empId == clientID;}, tempTea);    //将修改后的信息替换

    }
    this->editFile(type);


}








