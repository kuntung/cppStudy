//
// Created by tangkun on 2021/1/16.
//

#ifndef CPPSTUDY_GLOBALFILE_H
#define CPPSTUDY_GLOBALFILE_H

#include"student.h"
#include"teacher.h"
#define ADMIN_FILE "admin.txt" //����Ա�ļ�
#define STUDENT_FILE "student.txt" //ѧ���ļ�
#define TEACHER_FILE "teacher.txt" //��ʦ�ļ�
#define COMPUTER_FILE "computerRoom.txt" //������Ϣ�ļ�
#define ORDER_FILE "order.txt" //�����ļ�


class PrintTeacher{
public:
    void operator()(Teacher & teacher){
        cout <<"ְ����:" << teacher.m_empId << " ����:"<<teacher.m_name << "����:" << teacher.m_pwd << endl;

    }
};

#endif //CPPSTUDY_GLOBALFILE_H
