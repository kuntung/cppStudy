//
// Created by tangkun on 2021/1/16.
//

#ifndef CPPSTUDY_GLOBALFILE_H
#define CPPSTUDY_GLOBALFILE_H

#include"student.h"
#include"teacher.h"
#define ADMIN_FILE "admin.txt" //管理员文件
#define STUDENT_FILE "student.txt" //学生文件
#define TEACHER_FILE "teacher.txt" //教师文件
#define COMPUTER_FILE "computerRoom.txt" //机房信息文件
#define ORDER_FILE "order.txt" //订单文件


class PrintTeacher{
public:
    void operator()(Teacher & teacher){
        cout <<"职工号:" << teacher.m_empId << " 姓名:"<<teacher.m_name << "密码:" << teacher.m_pwd << endl;

    }
};

#endif //CPPSTUDY_GLOBALFILE_H
