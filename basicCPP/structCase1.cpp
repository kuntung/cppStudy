#include<iostream>
#include<string>
#include<ctime>

using namespace std;

struct Student
{
    string stuName;
    int stuScore;
    string stuTeacher;
    
};


struct Teacher
{
    string teacherName;
    struct Student student[5];
};

void allocateAttr(struct Teacher sArry[], int len){
    
    srand((unsigned int)time(NULL));

    string nameSeed = "ABCDEFGHIJKLMNOPQ";
    //通过添加随机数种子，实现分数的每次随机初始化
    float scoreQue[15];

    for(int i = 0; i<15; i++){
         scoreQue[i] = rand()%61 + 40;
    }

	for(int i = 0; i<len; i++){
        sArry[i].teacherName = nameSeed[i];
        sArry[i].teacherName +=  "老师";
        for(int j = 0; j<5;j++){
            sArry[i].student[j].stuName = "小";
            sArry[i].student[j].stuName += nameSeed[i*5+j];
            sArry[i].student[j].stuScore = scoreQue[i*5+j];
            sArry[i].student[j].stuTeacher = sArry[i].teacherName;
        }
    }

}



int main(){


    struct Teacher teacher[3];
    int len = sizeof(teacher)/sizeof(teacher[0]);
    
    allocateAttr(teacher, len);
    for(int i = 0;i<3;i++){
        cout<<teacher[i].teacherName<<"共辅导了五位学生，他们分别是:"<<endl;
        for(int j = 0; j<5;j++){
            cout<<teacher[i].student[j].stuName<<", 他们的成绩分别为:"<<teacher[i].student[j].stuScore<<endl;                                                                    
        }
    }


}
