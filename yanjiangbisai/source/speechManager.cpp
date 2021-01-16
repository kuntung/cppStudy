//
// Created by tangkun on 2021/1/14.
//

#include "header/speechManager.h"
#include<algorithm>
#include <random>
#include<deque>
#include<map>
#include<fstream>
#include<numeric>

SpeechManager::SpeechManager() {
//�ڹ��캯���е��ã���ʼ�����Ժ���
    this->initSpeech();
    this->createSpeaker();
    //���������¼
    this->showRecord();

}

SpeechManager::~SpeechManager() {

}

void SpeechManager::show_Menu() {
    cout << "***********************************************" << endl;
    cout << "***************  ��ӭ�μ��ݽ�����  ***************" << endl;
    cout << "***************  1.��ʼ�ݽ�����  ***************" << endl;
    cout << "***************  2.�鿴�����¼  ***************" << endl;
    cout << "***************  3.��ձ�����¼  ***************" << endl;
    cout << "***************  0.�˳���������  ***************" << endl;
    cout << "***********************************************" << endl;
    cout << endl;

}

void SpeechManager::exit_System() {//�˳�����
    cout << "��ӭ�´�ʹ�ã�" << endl;
    system("read -p 'Press Enter to continue...' var");
    exit(0);
}

void SpeechManager::start_System() {//��ʼ�ݽ�
    //��һ�ֱ���
    //1.��ǩ
    this->speechDraw();
    //2.����
    this->speechContest();
    //3.��ʾ�������
    this->showScore();
    //�ڶ��ֱ���
    this->m_int++;
    //1.��ǩ
    this->speechDraw();
    //2.����
    this->speechContest();
    //��ʾǰ����
    this->showScore();
    //�������
    this->saveRecord();
    //���ñ���
    this->initSpeech();
    //���¹���ѡ��
    this->createSpeaker();
    this->readRecord(); //��ȡ�����¼
    cout << "���������ϣ�" << endl;

    system("read -p 'Press Enter to continue...' var");
    system("clear");
}

void SpeechManager::initSpeech() {
    //��ձ�������
    this->v1.clear();
    this->v2.clear();
    this->v3.clear();
    this->m1.clear();
    //��ʼ�������ִ�
    this->m_int = 0;
    this->fileIsEmpty = true;
    this->m_Record.clear(); //����¼�������

}

void SpeechManager::createSpeaker() {
    string nameSeed = "ABCDEFGHIJKL";

    for (int i = 0; i < nameSeed.size(); i++) {
        string name = "ѡ��";
        name += nameSeed[i];

        Speaker sp;
        sp.m_name = name;
        for (int i = 0; i < 2; i++) {
            sp.m_score[i] = 0; //��ʼ������
        }

        //12��ѡ�ֵı��
        this->v1.push_back(i + 10001);

        //��ѡ�ֱ���Լ�ѡ����Ϣ�ŵ�map������
        this->m1.insert(make_pair(i + 10001, sp)); //map������Ҫ��`insert`����Ԫ�أ�����Ԫ������Ϊ����pair
    }

}

void SpeechManager::speechDraw() {
    cout << "��<" << this->m_int + 1 << ">�ֱ���ѡ�����ڳ�ǩ" << endl;
    cout << "----------------------" << endl;
    cout << "��ǩ���ݽ�˳������:" << endl;
    if (this->m_int == 0) {
        random_shuffle(v1.begin(), v1.end()); //���ҵ�һ��ѡ�ֵı�ǩ
        for (int &vit : this->v1) {
            cout << vit << ",";
        }
        cout << endl;
    } else if (this->m_int == 1) {
        random_shuffle(v2.begin(), v2.end()); //���ҵ�һ��ѡ�ֵı�ǩ
        for (int &vit : this->v2) {
            cout << vit << ",";
        }
        cout << endl;
    }

}

void SpeechManager::speechContest() {
    cout << "------------��<" << this->m_int + 1 << ">�ֱ�����ʽ��ʼ----------" << endl;
    multimap<double, int, greater<double>> groupScore; //��ʱ����������key������valueѡ�ֱ��

    int num = 0; //��¼��Ա��������Ϊһ��

    vector<int> v_Src;  //������Ա����
    if (this->m_int == 0) {
        v_Src = v1; //��һ�ֱ�����Ա
    } else {
        v_Src = v2; //�ڶ��ֱ�����Ա
    }

    for (auto &vit : v_Src) {
        num++;
        //��ί���
        deque<double> d;
        for (int i = 0; i < 10; i++) {
            double score = (rand() % 401 + 600) / 10.f; //60-100
//            cout << score << ",";
            d.push_back(score);
        }


        sort(d.begin(), d.end(), greater<double>()); //����������
        d.pop_front();
        d.pop_back(); //ȥ����߷ֺ���ͷ�

        double sum = accumulate(d.begin(), d.end(), 0.0f); //�ܷ�
        double avg = sum / (double(d.size())); //ƽ��

        //��ƽ���ַŵ�map������
        this->m1[vit].m_score[this->m_int] = avg;
        //��ӡ��ʾ�ɼ�
//        cout << "���: " << vit << ",������" << this->m1[vit].m_name << ",��ȡƽ����:" << this->m1[vit].m_score[this->m_int]
//             << endl;

        groupScore.insert(make_pair(avg, vit)); //��������ݷ��뵽��ʱС��������,keyΪƽ���ɼ���valueΪѡ�ֱ��
        if (num % 6 == 0) {
            cout << "��" << num / 6 << "С��������Σ�" << endl;
            for (auto &mit : groupScore) {
                cout << "���:" << mit.second << "������" << this->m1[mit.second].m_name
                     << "������" << this->m1[mit.second].m_score[this->m_int] << endl;
            }
            //ȡ��ǰ��
            int count = 0;
            for (auto mit = groupScore.begin(); mit != groupScore.end() && count < 3; mit++, count++) {
                if (this->m_int == 0) {
                    v2.push_back((*mit).second);
                } else {
                    v3.push_back((*mit).second);
                }

            }

            groupScore.clear(); //һ�����������
            cout << endl;
        }
    }
    cout << "---------��" << this->m_int + 1 << "�ֱ������---------" << endl;
}

void SpeechManager::showScore() {
    cout << "-----��" << this->m_int + 1 << "�ֱ����Ľ���ѡ����Ϣ����-----" << endl;

    vector<int> v;
    if (this->m_int == 0) {
        v = v2;
    } else {
        v = v3;
    }

    for (auto &vit : v) {
        cout << "ѡ�ֱ��:" << vit << "����" << this->m1[vit].m_name << "�÷�" << this->m1[vit].m_score[this->m_int]
             << endl;
    }
    cout << endl;

    system("read -p 'Press Enter to continue...' var");
    system("clear");
    this->show_Menu();
}

void SpeechManager::saveRecord() {
    ofstream ofs;
    ofs.open("speech.csv", ios::out | ios::app); //��׷�ӵķ�ʽд�ļ�

    //��ÿ��ѡ������д�뵽�ļ���
    for (auto &vit : v3) {
        ofs << vit << "," << this->m1[vit].m_score[1] << ",";
    }
    ofs << endl;

    ofs.close();
    cout << "��¼�Ѿ�����" << endl;
    this->fileIsEmpty = false; //�ɹ�����һ�μ�¼����־�ļ���Ϊ��
}

void SpeechManager::readRecord() {
    ifstream ifs("speech.csv", ios::in); //���ļ�
    if (!ifs.is_open()) {
        this->fileIsEmpty = true;
        cout << "�ļ�������" << endl;
        ifs.close();
        return;
    }

    //�ļ�Ϊ�����
    char ch;
    ifs >> ch;
    if (ifs.eof()) {
        cout << "�ļ�Ϊ��" << endl;
        this->fileIsEmpty = true;
        ifs.close();
        return;
    }

    //�ļ���Ϊ��
    this->fileIsEmpty = false;

    ifs.putback(ch); //�������ȡ�ĵ����ַ��Ż���

    string data;
    int index = 0; //��0��
    while (ifs >> data) {
//        cout << data <<endl;
        //��ȡ����
        vector<string> vs;
        int pos = -1; //�鵽","λ�õı���
        int start = 0;
        while (true) {
            pos = data.find(",", start);
            if (pos == -1) {
                //û���ҵ����
                break;
            }
            string temp = data.substr(start, pos - start);
//            cout << temp << endl;
            vs.push_back(temp);
            start = pos + 1;
        }
        this->m_Record.insert(make_pair(index, vs));
        index++;

    }

    ifs.close();

//    for (auto &mit: this->m_Record) {
//        cout << "��" << mit.first + 1 << "��ھ���ţ�" << mit.second[0] << "������" << mit.second[1] << endl;
//    }
}

void SpeechManager::clearRecord() {
    cout << "ȷ����գ�" << endl;
    cout <<"1.ȷ��"<<endl;
    cout<<"2.����"<<endl;
    
    int select = 0;
    cin >> select;
    
    if(select == 1){
        //��ģʽios::trunc�����������ɾ���ļ������´���
        ofstream ofs("speech.csv", ios::trunc);
        ofs.close();
        //��ʼ������
        this->initSpeech();
        this->createSpeaker();
        this->readRecord();

        cout <<"��ճɹ�"<<endl;

    }
    system("read -p 'Press Enter to continue...' var");
    system("clear");

}

void SpeechManager::showRecord() {
    this->readRecord();
    if(this->fileIsEmpty){
        cout<<"�ļ�Ϊ�ջ򲻴��ڣ�"<<endl;
    }
    else{
        for(int i = 0; i < this->m_Record.size(); i++){
            cout <<"��" << i+1 <<"��" <<"�ھ����:"<< this->m_Record[i][0] << "�÷�:" << this->m_Record[i][1] <<" "
                 <<"��" << i+1 <<"��" <<"�Ǿ����:"<< this->m_Record[i][2] << "�÷�:" << this->m_Record[i][3] <<" "
                 <<"��" << i+1 <<"��" <<"�������:"<< this->m_Record[i][4] << "�÷�:" << this->m_Record[i][5] <<" "<<endl;
        }
    }

//    system("read -p 'Press Enter to continue...' var");
    system("clear");
//    this->show_Menu();

}
