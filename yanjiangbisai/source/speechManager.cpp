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
//在构造函数中调用，初始化属性函数
    this->initSpeech();
    this->createSpeaker();
    //加载往届记录
    this->showRecord();

}

SpeechManager::~SpeechManager() {

}

void SpeechManager::show_Menu() {
    cout << "***********************************************" << endl;
    cout << "***************  欢迎参加演讲比赛  ***************" << endl;
    cout << "***************  1.开始演讲比赛  ***************" << endl;
    cout << "***************  2.查看往届记录  ***************" << endl;
    cout << "***************  3.清空比赛记录  ***************" << endl;
    cout << "***************  0.退出比赛程序  ***************" << endl;
    cout << "***********************************************" << endl;
    cout << endl;

}

void SpeechManager::exit_System() {//退出功能
    cout << "欢迎下次使用！" << endl;
    system("read -p 'Press Enter to continue...' var");
    exit(0);
}

void SpeechManager::start_System() {//开始演讲
    //第一轮比赛
    //1.抽签
    this->speechDraw();
    //2.比赛
    this->speechContest();
    //3.显示晋级结果
    this->showScore();
    //第二轮比赛
    this->m_int++;
    //1.抽签
    this->speechDraw();
    //2.比赛
    this->speechContest();
    //显示前三名
    this->showScore();
    //保存分数
    this->saveRecord();
    //重置比赛
    this->initSpeech();
    //重新构建选手
    this->createSpeaker();
    this->readRecord(); //获取往届记录
    cout << "本届比赛完毕！" << endl;

    system("read -p 'Press Enter to continue...' var");
    system("clear");
}

void SpeechManager::initSpeech() {
    //清空比赛容器
    this->v1.clear();
    this->v2.clear();
    this->v3.clear();
    this->m1.clear();
    //初始化比赛轮次
    this->m_int = 0;
    this->fileIsEmpty = true;
    this->m_Record.clear(); //将记录容器清空

}

void SpeechManager::createSpeaker() {
    string nameSeed = "ABCDEFGHIJKL";

    for (int i = 0; i < nameSeed.size(); i++) {
        string name = "选手";
        name += nameSeed[i];

        Speaker sp;
        sp.m_name = name;
        for (int i = 0; i < 2; i++) {
            sp.m_score[i] = 0; //初始化分数
        }

        //12名选手的编号
        this->v1.push_back(i + 10001);

        //将选手编号以及选手信息放到map容器中
        this->m1.insert(make_pair(i + 10001, sp)); //map容器需要用`insert`插入元素，插入元素类型为对组pair
    }

}

void SpeechManager::speechDraw() {
    cout << "第<" << this->m_int + 1 << ">轮比赛选手正在抽签" << endl;
    cout << "----------------------" << endl;
    cout << "抽签后演讲顺序如下:" << endl;
    if (this->m_int == 0) {
        random_shuffle(v1.begin(), v1.end()); //打乱第一轮选手的标签
        for (int &vit : this->v1) {
            cout << vit << ",";
        }
        cout << endl;
    } else if (this->m_int == 1) {
        random_shuffle(v2.begin(), v2.end()); //打乱第一轮选手的标签
        for (int &vit : this->v2) {
            cout << vit << ",";
        }
        cout << endl;
    }

}

void SpeechManager::speechContest() {
    cout << "------------第<" << this->m_int + 1 << ">轮比赛正式开始----------" << endl;
    multimap<double, int, greater<double>> groupScore; //临时容器，保存key分数，value选手编号

    int num = 0; //记录人员数，六个为一组

    vector<int> v_Src;  //比赛人员容器
    if (this->m_int == 0) {
        v_Src = v1; //第一轮比赛人员
    } else {
        v_Src = v2; //第二轮比赛人员
    }

    for (auto &vit : v_Src) {
        num++;
        //评委打分
        deque<double> d;
        for (int i = 0; i < 10; i++) {
            double score = (rand() % 401 + 600) / 10.f; //60-100
//            cout << score << ",";
            d.push_back(score);
        }


        sort(d.begin(), d.end(), greater<double>()); //按降序排列
        d.pop_front();
        d.pop_back(); //去掉最高分和最低分

        double sum = accumulate(d.begin(), d.end(), 0.0f); //总分
        double avg = sum / (double(d.size())); //平均

        //将平均分放到map容器中
        this->m1[vit].m_score[this->m_int] = avg;
        //打印显示成绩
//        cout << "编号: " << vit << ",姓名：" << this->m1[vit].m_name << ",获取平均分:" << this->m1[vit].m_score[this->m_int]
//             << endl;

        groupScore.insert(make_pair(avg, vit)); //将打分数据放入到临时小组容器中,key为平均成绩，value为选手编号
        if (num % 6 == 0) {
            cout << "第" << num / 6 << "小组比赛名次：" << endl;
            for (auto &mit : groupScore) {
                cout << "编号:" << mit.second << "姓名：" << this->m1[mit.second].m_name
                     << "分数：" << this->m1[mit.second].m_score[this->m_int] << endl;
            }
            //取走前三
            int count = 0;
            for (auto mit = groupScore.begin(); mit != groupScore.end() && count < 3; mit++, count++) {
                if (this->m_int == 0) {
                    v2.push_back((*mit).second);
                } else {
                    v3.push_back((*mit).second);
                }

            }

            groupScore.clear(); //一组比赛完后，清空
            cout << endl;
        }
    }
    cout << "---------第" << this->m_int + 1 << "轮比赛完毕---------" << endl;
}

void SpeechManager::showScore() {
    cout << "-----第" << this->m_int + 1 << "轮比赛的晋级选手信息如下-----" << endl;

    vector<int> v;
    if (this->m_int == 0) {
        v = v2;
    } else {
        v = v3;
    }

    for (auto &vit : v) {
        cout << "选手编号:" << vit << "姓名" << this->m1[vit].m_name << "得分" << this->m1[vit].m_score[this->m_int]
             << endl;
    }
    cout << endl;

    system("read -p 'Press Enter to continue...' var");
    system("clear");
    this->show_Menu();
}

void SpeechManager::saveRecord() {
    ofstream ofs;
    ofs.open("speech.csv", ios::out | ios::app); //用追加的方式写文件

    //将每个选手数据写入到文件中
    for (auto &vit : v3) {
        ofs << vit << "," << this->m1[vit].m_score[1] << ",";
    }
    ofs << endl;

    ofs.close();
    cout << "记录已经保存" << endl;
    this->fileIsEmpty = false; //成功保存一次记录，标志文件不为空
}

void SpeechManager::readRecord() {
    ifstream ifs("speech.csv", ios::in); //读文件
    if (!ifs.is_open()) {
        this->fileIsEmpty = true;
        cout << "文件不存在" << endl;
        ifs.close();
        return;
    }

    //文件为空情况
    char ch;
    ifs >> ch;
    if (ifs.eof()) {
        cout << "文件为空" << endl;
        this->fileIsEmpty = true;
        ifs.close();
        return;
    }

    //文件不为空
    this->fileIsEmpty = false;

    ifs.putback(ch); //将上面读取的单个字符放回来

    string data;
    int index = 0; //第0届
    while (ifs >> data) {
//        cout << data <<endl;
        //截取数据
        vector<string> vs;
        int pos = -1; //查到","位置的变量
        int start = 0;
        while (true) {
            pos = data.find(",", start);
            if (pos == -1) {
                //没有找到清空
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
//        cout << "第" << mit.first + 1 << "届冠军编号：" << mit.second[0] << "分数：" << mit.second[1] << endl;
//    }
}

void SpeechManager::clearRecord() {
    cout << "确认清空？" << endl;
    cout <<"1.确认"<<endl;
    cout<<"2.返回"<<endl;
    
    int select = 0;
    cin >> select;
    
    if(select == 1){
        //打开模式ios::trunc，如果存在则删除文件并重新创建
        ofstream ofs("speech.csv", ios::trunc);
        ofs.close();
        //初始化属性
        this->initSpeech();
        this->createSpeaker();
        this->readRecord();

        cout <<"清空成功"<<endl;

    }
    system("read -p 'Press Enter to continue...' var");
    system("clear");

}

void SpeechManager::showRecord() {
    this->readRecord();
    if(this->fileIsEmpty){
        cout<<"文件为空或不存在！"<<endl;
    }
    else{
        for(int i = 0; i < this->m_Record.size(); i++){
            cout <<"第" << i+1 <<"届" <<"冠军编号:"<< this->m_Record[i][0] << "得分:" << this->m_Record[i][1] <<" "
                 <<"第" << i+1 <<"届" <<"亚军编号:"<< this->m_Record[i][2] << "得分:" << this->m_Record[i][3] <<" "
                 <<"第" << i+1 <<"届" <<"季军编号:"<< this->m_Record[i][4] << "得分:" << this->m_Record[i][5] <<" "<<endl;
        }
    }

//    system("read -p 'Press Enter to continue...' var");
    system("clear");
//    this->show_Menu();

}
