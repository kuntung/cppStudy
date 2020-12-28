//
// Created by tangkun on 2020/12/25.
//

#include "header/workerManager.h"

WorkerManager::WorkerManager(){
    //��ʼ������
    ifstream ifs;
    ifs.open(FILENAME, ios::in); //���ļ�

    //����ļ�������
    if(!ifs.is_open()){
        cout<<"�ļ�������"<<endl; //�������
        this->m_EmpNum = 0;
        this->m_EmpArray = nullptr;
        this->m_FileIsEmpty = true;
        ifs.close();

        return;
    }
    //����ļ����ڣ����Ǽ�¼Ϊ��
    char ch;
    ifs >> ch;
    if(ifs.eof())
    {
        cout<<"�ļ�Ϊ��!"<<endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = nullptr;
        this->m_FileIsEmpty = true;
        ifs.close();

        return;
    }
    //����ļ����ڣ��Ҳ�Ϊ��
    else{
        cout<<"�ļ������Ҳ�Ϊ��"<<endl;
        this->m_EmpNum = this->get_EmpNum();
        cout<<"ְ��������Ϊ:"<<this->m_EmpNum<<endl;
        this->m_FileIsEmpty = false;

        //���ٿռ�
        this->m_EmpArray = new Worker*[this->m_EmpNum];
        //���ļ������ݿ�������
        this->init_Emp();
        //��ʾ��Ϣ
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
    cout<<"************   ��ӭʹ��ְ������ϵͳ�� *************"<<endl;
    cout<<"*************    0.�˳��������   ***************"<<endl;
    cout<<"*************    1.����ְ����Ϣ   ***************"<<endl;
    cout<<"*************    2.��ʾְ����Ϣ   ***************"<<endl;
    cout<<"*************    3.ɾ����ְְ��   ***************"<<endl;
    cout<<"*************    4.�޸�ְ����Ϣ   ***************"<<endl;
    cout<<"*************    5.����ְ����Ϣ   ***************"<<endl;
    cout<<"*************    6.ְ����Ϣ����   ***************"<<endl;
    cout<<"*************    7.��������ĵ�   ***************"<<endl;
    cout<<"***********************************************"<<endl;
    cout<<endl;
}

//�����˳�
void WorkerManager::exit_system() {
    cout<<"�Ƿ��˳�?"<<endl;
    system("pause");
    exit(0); //�˳�����
}

void WorkerManager::add_Emp() {
    cout<<"���������ְ����������"<<endl;

    int addNum = 0;//�����û�����������
    cin>>addNum;
    if(addNum>0){
        //���
        //��������¿ռ�Ĵ�С
        int newSize = this->m_EmpNum + addNum; //�¿ռ����� = ԭ������+�µ�����

        //�����¿ռ�
        Worker ** newSpace = new Worker*[newSize];

        //��ԭ���ռ������ݣ��������¿ռ���
        if(this->m_EmpArray != NULL ){
            for(int i = 0; i < this-> m_EmpNum; i++){
                newSpace[i] = this->m_EmpArray[i];
            }
        }

        //����µĳ�Ա
        for(int i = 0; i < addNum; i++){
            int id; //ְ�����
            string name; //ְ������
            int dSelect; //����ѡ��
            cout<<"�������"<<i+1<<"����ְ���ı�ţ�"<<endl;
            cin>>id;
            cout<<"�������"<<i+1<<"����ְ����������"<<endl;
            cin>>name;
            cout<<"��ѡ���ְ���ĸ�λ��"<<endl;
            cout<<"1.��ְͨ��"<<endl;
            cout<<"2.����"<<endl;
            cout<<"3.�ϰ�"<<endl;
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
        //�ͷ�ԭ�пռ�
        delete[] this->m_EmpArray;
        //�����¿ռ�ָ��
        this->m_EmpArray = newSpace;

        //�����µ�ְ������
        this->m_EmpNum = newSize;
        //����ְ����Ϊ��״̬
        this->m_FileIsEmpty = false;
        //��ʾ��ӳɹ�
        cout<<"�ɹ����"<<newSize<<"��ְ��"<<endl;

        //�������ݵ��ļ���
        this->save();
    }
    else{
        cout<<"������������"<<endl;
    }
    //��������������ص��ϼ�Ŀ¼
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



    ofs.close(); //�ر��ļ�
}

int WorkerManager::get_EmpNum() {

    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int num = 0; //��ʼ��ͳ������Ϊ0

    while(ifs >> id && ifs >> name && ifs >> dId){
        //��¼����
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
        switch(dId){ //����dId�Ĳ�ͬ������Ӧ�Ķ���
            case 1:
                worker = new Employee(id, name, dId); //��̬
                break;
            case 2:
                worker = new Manager(id, name, dId);
                break;
            case 3:
                worker = new Boss(id, name, dId);
                break;
        }
        this->m_EmpArray[index++] = worker; //����������
    }

    ifs.close();

}

void WorkerManager::show_Emp() {
    if(!this->m_FileIsEmpty){ //�ļ������в�Ϊ��
        for (int i = 0; i < this->m_EmpNum; i++){
            //���ö�̬���ó�����
            this->m_EmpArray[i]->show_info();
//            cout << "ְ�����: " << this->m_EmpArray[i]->m_id
//                << " ְ������: " << this->m_EmpArray[i]->m_name
//                <<" ְ������: " << this->m_EmpArray[i]->m_DeptId
//                << " ְ��ְ��: " << this->m_EmpArray[i]->get_workType()<<endl;
        }
    }
    else{
        cout<<"�ļ������ڻ�Ϊ��" << endl;
    }

    //�������������
    system("pause");
    system("cls");

}
void WorkerManager::del_Emp(string name) {
    if(this->m_FileIsEmpty){
        cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
    }
    else{
        //����Ա������ɾ��
        int index = this->IsExit(name);
        if(index != -1){
            //����������һ��Ԫ����������ȱ�����ҽ������ģ��һ
            this->m_EmpArray[index] = this->m_EmpArray[this->m_EmpNum - 1];
            this->m_EmpNum--;
        }
        else{
            cout<<"δ�ҵ���Ա��������Ҫִ��ɾ������"<<endl;
        }

    }
    //�������������
    system("pause");
    system("cls");
}

void WorkerManager::del_Emp(int id) {
    if(this->m_FileIsEmpty){
        cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
    }
    else{
        //����Ա�����ɾ��
        int index = this->IsExit(id);
        if(index != -1){
            cout<<"�Ƿ�ɾ��?"<<endl;
            char qveren = 'N';
            cin>>qveren;
            if(qveren == 'Y'){
                //����������һ��Ԫ����������ȱ�����ҽ������ģ��һ
                this->m_EmpArray[index] = this->m_EmpArray[this->m_EmpNum - 1];
                this->m_EmpNum--;

                //����ͬ�����µ��ļ���
                this->save();

                cout<<"ɾ���ɹ���"<<endl;
            }
        }
        else{
            cout<<"δ�ҵ���Ա��������Ҫִ��ɾ������"<<endl;
        }

    }

    system("pause");
    system("cls");
}
//���صĲ��Һ���������Ա�����������в����ж�
int WorkerManager::IsExit(string name) {
    if(this->m_FileIsEmpty){
        cout<<"��ǰ�ļ������ڻ���Ϊ��"<<endl;
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
//����Ա����id���в����ж�
int WorkerManager::IsExit(int id) {
    if(this->m_FileIsEmpty){
        cout<<"��ǰ�ļ������ڻ���Ϊ��"<<endl;
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

void WorkerManager::edit_Emp(int id) {
    if(this->m_FileIsEmpty){
        cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
    }
    else{
        //����Ա�����ɾ��
        int index = this->IsExit(id);
        if(index != -1){
            //�����е�Ա����Ϣ�����޸�
            //��ӡ�޸�ǰ��Ϣ
            this->m_EmpArray[index]->show_info();
            //�����޸ĺ����Ϣ
            Worker * worker = nullptr;
            int new_id;
            string new_name;
            int new_dId;
            cout << "������Ҫ�޸ĵ�ְ����Ϣ:" << endl;
            cout<<"ְ�����:";
            cin >> new_id;
            cout << "ְ������";
            cin >> new_name;
            cout << "ְ������";
            cin >> new_dId;
            switch(new_dId){
                case 1:
                    worker = new Employee(new_id, new_name, new_dId);
                    break;
                case 2:
                    worker = new Manager(new_id, new_name, new_dId);
                    break;
                case 3:
                    worker = new Boss(new_id, new_name, new_dId);
                    break;
            }
            this->m_EmpArray[index] = worker;
        }
        else{
            cout<<"δ�ҵ���Ա�����޷�����ɾ������"<<endl;
        }

        //���޸ĺ����Ϣ����
        this->save();
    }
    //�������������
    system("pause");
    system("cls");
}

void WorkerManager::edit_Emp(string name) {
    if(this->m_FileIsEmpty){
        cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
    }
    else{
        //����Ա������ɾ��
        int index = this->IsExit(name);
        if(index != -1){
            //�����е�Ա����Ϣ�����޸�
            //��ӡ�޸�ǰ��Ϣ
            this->m_EmpArray[index]->show_info();
            //�����޸ĺ����Ϣ
            Worker * worker = nullptr;
            int new_id;
            string new_name;
            int new_dId;
            cout << "������Ҫ�޸ĵ�ְ����Ϣ:" << endl;
            cout<<"ְ�����:";
            cin >> new_id;
            cout << "ְ������";
            cin >> new_name;
            cout << "ְ������";
            cin >> new_dId;
            switch(new_dId){
                case 1:
                    worker = new Employee(new_id, new_name, new_dId);
                    break;
                case 2:
                    worker = new Manager(new_id, new_name, new_dId);
                    break;
                case 3:
                    worker = new Boss(new_id, new_name, new_dId);
                    break;
            }
            this->m_EmpArray[index] = worker;
        }
        else{
            cout<<"δ�ҵ���Ա�����޷�����ɾ������"<<endl;
        }

        //���޸ĺ����Ϣ����
        this->save();
    }
    //�������������
    system("pause");
    system("cls");
}

void WorkerManager::find_Emp(int id) {
    if(this->m_FileIsEmpty){
        cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
    }
    else{
        //����Ա����Ž�����ʾ
        int index = this->IsExit(id);
        if(index != -1){
            //�����е�Ա����Ϣ������ʾ
            //��ӡ�޸�ǰ��Ϣ
            this->m_EmpArray[index]->show_info();
        }
        else{
            cout<<"δ�ҵ���Ա��"<<endl;
        }
    }
    //�������������
    system("pause");
    system("cls");
}

void WorkerManager::find_Emp(string name) {
    if(this->m_FileIsEmpty){
        cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
    }
    else{
        //����Ա������������ʾ
        bool find_flag = false; //�տ�ʼʱĬ�ϲ����ڸ�Ա��
        for(int i = 0; i < this->m_EmpNum; i++){
            if(this->m_EmpArray[i]->m_name == name){
                cout << "���ҳɹ���ְ�����Ϊ:"
                    << this->m_EmpArray[i]->m_id
                    << "�����Ϣ����:" << endl;
                find_flag = true;
                this->m_EmpArray[i]->show_info();
            }
        }
        if(!find_flag){
            cout<<"δ�ҵ���Ա��"<<endl;
        }
    }
    //�������������
    system("pause");
    system("cls");
}

void WorkerManager::sort_Emp() {
    if(this->m_FileIsEmpty){
        cout << "��ǰ�ļ������ڻ��޼�¼" << endl;
        return;
    }
    else{
        cout << "��ѡ������ʽ��" << endl;
        cout << "1. ��ְ���Ž�����������" << endl;
        cout << "2. ��ְ���Ž��н�������" << endl;
        int sort_selection = 0;
        cin >> sort_selection;

        for(int i = 0; i < this->m_EmpNum; i++){
            int minOrMax = i; //��¼��ǰ��С�������Ԫ�ص�λ��
            for(int j = i + 1; j < this->m_EmpNum; j++){
                if(sort_selection == 1){ //��������
                    if(this->m_EmpArray[minOrMax]->m_id > this->m_EmpArray[j]->m_id){
                        minOrMax = j;
                    }
                }
                else{
                    if(this->m_EmpArray[minOrMax]->m_id < this->m_EmpArray[j]->m_id){
                        minOrMax = j;
                    }
                }
                //�����жϲ�����λ��
                if(minOrMax != i){
                    Worker *temp = this->m_EmpArray[i];
                    this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
                    this->m_EmpArray[minOrMax] = temp;
                }
            }
        }
        cout << "����ɹ�,�������Ϊ:" << endl;
        this->save();
        this->show_Emp();
    }

}

//���ְ�������Ϣ
void WorkerManager::clear_Emp() {
    cout << "ȷ�����?" << endl;
    cout << "1.ȷ��" << endl;
    cout << "2.����" << endl;

    int clear_selection = 0;
    cin >> clear_selection;

    if(clear_selection == 1){
        //��ģʽ�� ios::trunc,������ڸ��ļ�����ɾ�������´���
        ofstream ofs(FILENAME, ios::trunc);
        ofs.close();
        if( this->m_EmpArray != nullptr){
            for(int i = 0; i < this->m_EmpNum; i++){
                if(this->m_EmpArray[i] != nullptr){
                    delete this->m_EmpArray[i];
                }
            }
            this->m_EmpNum = 0;
            delete[] this->m_EmpArray;
            this->m_EmpArray = nullptr;
            this->m_FileIsEmpty = true;
        }
        cout << "��ճɹ���" << endl;
    }
    system("pause");
    system("cls");
}


