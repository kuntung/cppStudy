//
// Created by tangkun on 2020/12/25.
//

#include "header/workerManager.h"

WorkerManager::WorkerManager(){
    //初始化属性
    ifstream ifs;
    ifs.open(FILENAME, ios::in); //读文件

    //如果文件不存在
    if(!ifs.is_open()){
        cout<<"文件不存在"<<endl; //测试输出
        this->m_EmpNum = 0;
        this->m_EmpArray = nullptr;
        this->m_FileIsEmpty = true;
        ifs.close();

        return;
    }
    //如果文件存在，但是记录为空
    char ch;
    ifs >> ch;
    if(ifs.eof())
    {
        cout<<"文件为空!"<<endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = nullptr;
        this->m_FileIsEmpty = true;
        ifs.close();

        return;
    }
    //如果文件存在，且不为空
    else{
        cout<<"文件存在且不为空"<<endl;
        this->m_EmpNum = this->get_EmpNum();
        cout<<"职工的人数为:"<<this->m_EmpNum<<endl;
        this->m_FileIsEmpty = false;

        //开辟空间
        this->m_EmpArray = new Worker*[this->m_EmpNum];
        //将文件中数据拷贝过来
        this->init_Emp();
        //显示信息
        this->show_Emp();

    }

}

WorkerManager::~WorkerManager() {
    if(this->m_EmpArray != nullptr){
        delete[] this->m_EmpArray;
        this->m_EmpArray = nullptr;
    }
}

void WorkerManager::show_menu() {
    cout<<"***********************************************"<<endl;
    cout<<"************   欢迎使用职工管理系统！ *************"<<endl;
    cout<<"*************    0.退出管理程序   ***************"<<endl;
    cout<<"*************    1.增加职工信息   ***************"<<endl;
    cout<<"*************    2.显示职工信息   ***************"<<endl;
    cout<<"*************    3.删除离职职工   ***************"<<endl;
    cout<<"*************    4.修改职工信息   ***************"<<endl;
    cout<<"*************    5.查找职工信息   ***************"<<endl;
    cout<<"*************    6.职工信息排序   ***************"<<endl;
    cout<<"*************    7.清空所有文档   ***************"<<endl;
    cout<<"***********************************************"<<endl;
    cout<<endl;
}

//程序退出
void WorkerManager::exit_system() {
    cout<<"是否退出?"<<endl;
    system("pause");
    exit(0); //退出程序
}

void WorkerManager::add_Emp() {
    cout<<"请输入添加职工的数量："<<endl;

    int addNum = 0;//保存用户的输入数量
    cin>>addNum;
    if(addNum>0){
        //添加
        //计算添加新空间的大小
        int newSize = this->m_EmpNum + addNum; //新空间人数 = 原有人数+新的人数

        //开辟新空间
        Worker ** newSpace = new Worker*[newSize];

        //将原来空间下数据，拷贝到新空间下
        if(this->m_EmpArray != NULL ){
            for(int i = 0; i < this-> m_EmpNum; i++){
                newSpace[i] = this->m_EmpArray[i];
            }
        }

        //添加新的成员
        for(int i = 0; i < addNum; i++){
            int id; //职工编号
            string name; //职工姓名
            int dSelect; //姓名选择
            cout<<"请输入第"<<i+1<<"个新职工的编号："<<endl;
            cin>>id;
            cout<<"请输入第"<<i+1<<"个新职工的姓名："<<endl;
            cin>>name;
            cout<<"请选择该职工的岗位："<<endl;
            cout<<"1.普通职工"<<endl;
            cout<<"2.经理"<<endl;
            cout<<"3.老板"<<endl;
            cin>>dSelect;

            Worker * worker = nullptr;
            switch(dSelect){
                case 1:
                    worker = new Employee(id, name, dSelect);
                    break;
                case 2:
                    worker = new Manager(id, name, dSelect);
                    break;
                case 3:
                    worker = new Boss(id, name, dSelect);
                    break;
            }
            newSpace[this->m_EmpNum + i] = worker;

        }
        //释放原有空间
        delete[] this->m_EmpArray;
        //更改新空间指向
        this->m_EmpArray = newSpace;

        //更新新的职工人数
        this->m_EmpNum = newSize;
        //更新职工不为空状态
        this->m_FileIsEmpty = false;
        //提示添加成功
        cout<<"成功添加"<<newSize<<"名职工"<<endl;

        //保存数据到文件中
        this->save();
    }
    else{
        cout<<"输入数据有误"<<endl;
    }
    //按任意键后，清屏回到上级目录
    system("pause");
    system("cls");
}

void WorkerManager::save(){
    ofstream ofs;
    ofs.open(FILENAME, ios::out);


        for(int i = 0; i < this->m_EmpNum; i++){
            ofs << this->m_EmpArray[i]->m_id << " "
                << this->m_EmpArray[i]->m_name << " "
                << this->m_EmpArray[i]->m_DeptId << endl;
        }



    ofs.close(); //关闭文件
}

int WorkerManager::get_EmpNum() {

    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int num = 0; //初始化统计人数为0

    while(ifs >> id && ifs >> name && ifs >> dId){
        //记录人数
        num++;
    }

    ifs.close();

    return num;


}

void WorkerManager::init_Emp() {
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;

    string name;
    int dId;

    int index = 0;
    while(ifs >> id && ifs >> name && ifs >> dId){
        Worker * worker = nullptr;
        switch(dId){ //根据dId的不同创建对应的对象
            case 1:
                worker = new Employee(id, name, dId); //多态
                break;
            case 2:
                worker = new Manager(id, name, dId);
                break;
            case 3:
                worker = new Boss(id, name, dId);
                break;
        }
        this->m_EmpArray[index++] = worker; //放在数组中
    }

    ifs.close();

}

void WorkerManager::show_Emp() {
    if(!this->m_FileIsEmpty){ //文件存在切不为空
        for (int i = 0; i < this->m_EmpNum; i++){
            //利用多态调用程序借口
            this->m_EmpArray[i]->show_info();
//            cout << "职工编号: " << this->m_EmpArray[i]->m_id
//                << " 职工姓名: " << this->m_EmpArray[i]->m_name
//                <<" 职工类型: " << this->m_EmpArray[i]->m_DeptId
//                << " 职工职责: " << this->m_EmpArray[i]->get_workType()<<endl;
        }
    }
    else{
        cout<<"文件不存在或为空" << endl;
    }

    //按任意键后清屏
    system("pause");
    system("cls");

}
void WorkerManager::del_Emp(string name) {
    if(this->m_FileIsEmpty){
        cout << "文件不存在或者记录为空！" << endl;
    }
    else{
        //按照员工编号删除
        int index = this->IsExit(name);
        if(index != -1){
            //将数组的最后一个元素用来补空缺。并且将数组规模减一
            this->m_EmpArray[index] = this->m_EmpArray[this->m_EmpNum - 1];
            this->m_EmpNum--;
        }
        else{
            cout<<"未找到该员工，不需要执行删除操作"<<endl;
        }

    }
}

void WorkerManager::del_Emp(int id) {
    if(this->m_FileIsEmpty){
        cout << "文件不存在或者记录为空！" << endl;
    }
    else{
        //按照员工编号删除
        int index = this->IsExit(id);
        if(index != -1){
            cout<<"是否删除?"<<endl;
            char qveren = 'N';
            cin>>qveren;
            if(qveren == 'Y'){
                //将数组的最后一个元素用来补空缺。并且将数组规模减一
                this->m_EmpArray[index] = this->m_EmpArray[this->m_EmpNum - 1];
                this->m_EmpNum--;

                //数据同步更新到文件中
                this->save();

                cout<<"删除成功！"<<endl;
            }
        }
        else{
            cout<<"未找到该员工，不需要执行删除操作"<<endl;
        }

    }

    system("pause");
    system("cls");
}
//重载的查找函数，根据员工的姓名进行查找判断
int WorkerManager::IsExit(string name) {
    if(this->m_FileIsEmpty){
        cout<<"当前文件不存在或者为空"<<endl;
        return -1;
    }
    else{
        for(int i = 0; i < this->m_EmpNum; i++){
            if(this->m_EmpArray[i]->m_name == name)
                return i;
        }
        return -1;
    }
}
//根据员工的id进行查找判断
int WorkerManager::IsExit(int id) {
    if(this->m_FileIsEmpty){
        cout<<"当前文件不存在或者为空"<<endl;
        return -1;
    }
    else{
        for(int i = 0; i < this->m_EmpNum; i++){
            if(this->m_EmpArray[i]->m_id == id)
                return i;
        }
        return -1;
    }
}


