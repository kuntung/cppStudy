//
// Created by tangkun on 2021/1/14.
//

#include "header/speechManager.h"
#include<algorithm>
#include <random>

SpeechManager::SpeechManager() {
//�ڹ��캯���е��ã���ʼ�����Ժ���
    initSpeech();
    createSpeaker();
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
    system("pause");
    exit(0);
}

void SpeechManager::start_System() {//��ʼ�ݽ�
    //��һ�ֱ���
    //1.��ǩ
    speechDraw();
    //2.����

    //3.��ʾ�������

    //�ڶ��ֱ���

    //1.��ǩ

    //2.����

    //��ʾǰ����


}

void SpeechManager::initSpeech() {
    //��ձ�������
    this->v1.clear();
    this->v2.clear();
    this->v3.clear();
    this->m1.clear();
    //��ʼ�������ִ�
    this->m_int = 0;

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
    cout << "��<" << this->m_int + 1<< ">�ֱ���ѡ�����ڳ�ǩ" << endl;
    cout << "----------------------" << endl;
    cout << "��ǩ���ݽ�˳������:" << endl;
    if (this->m_int == 0) {
        random_shuffle(v1.begin(), v1.end()); //���ҵ�һ��ѡ�ֵı�ǩ
        for (int &vit : this->v1) {
            cout << vit << ",";
        }
        cout << endl;
    }
    else if(this->m_int == 1){
        random_shuffle(v2.begin(), v2.end()); //���ҵ�һ��ѡ�ֵı�ǩ
        for (int &vit : this->v2) {
            cout << vit << ",";
        }
        cout << endl;
    }

}
