/*
通过c++实现一个通讯录管理系统，系统中需要实现的功能如下：
1.添加联系人：向通讯录中添加新人，信息包括（姓名、性别、年龄、联系地址、家庭地址），最多记录100人
2.显示联系人：显示通讯录中所有联系人信息
3.删除联系人：按照姓名进行删除指定联系人
4.修改联系人：按照姓名重新修改指定联系人
5.清空联系人：清空通讯录中所有信息
6.查找联系人：按照姓名查看指定联系人信息
7.退出通讯录：退出当前使用的通讯录
*/
/*思路：
先构建一个关于个体的结构体，包含以上信息。进而， 构建一系列函数，传入参数为结构体数组
再构建一个包含成员结构体的系统结构体，属性包含成员结构体，以及一些操作标志FLAG等
*/

#include<iostream>
#include<string>

using namespace std;

void addMember(struct System *memberSys);
//定义联系人结构体
//结构体包含：姓名，性别，年龄，电话，联系地址，家庭住址
struct Member
{                       
    string memberName;
    string memberGender;
    int memberAge;
	string memberPhone;
    string memberAddress;
    string memberHome;
};

//定义通讯录结构体
//这个结构体包含属性有：一些操作执行标志、成员结构体，当前尾部长度
struct System{
    char delFLAG;
    char newFLAG;
    char clearFLAG;
	char activeFLAG;
	int index;
    struct Member *memberInfo;
};


/*
定义一个判断目标名字所在位置编号的函数。
返回值为当前查询名字的编号，如果查询为空，则返回-1， 传入参数为通讯录，待查询的名字, 序列最大长度。
*/
int findMember(struct System *memberSys, string memberName){
    for(int i = 0; i < memberSys->index; i++){
        if(memberSys->memberInfo[i].memberName == memberName){
            return i;
        }
    }
	return -1; //for循环结束还没有找到，证明没有这个人    
}

//showName
void showAllName(struct System *memberSys){
    if(0 == memberSys->index){
        cout<<"当前通讯录为空！"<<endl;
    }
    else{
        cout<<"当前通讯录有如下成员："<<endl;
        for(int i = 0; i< memberSys->index; i++){
            cout<<"第"<<i+1<<"个联系人的";
            cout<<"姓名："<<memberSys->memberInfo[i].memberName<<endl;
        }
    }
}

//实现联系人删除
//1. 需要传入需要删除人员的姓名，现有通讯录
//2. 完成对目标人员的检索，如果检索成功则删除，并且把后面的队列往前移动。(或者，记录下来空格，新建的时候优先使用空格)
//3. 如果检索失败，显示无此联系人，并在有容量剩余的时候，提示是否新建此联系人
void delMember(struct System *memberSys, string memberName){
    int location = findMember(memberSys, memberName);    
    if(-1 == location){
    cout<<"没有这个人!"<<endl;
        }
    else{
        cout<<"确认删除(Y/N)"<<endl;
        cin>>memberSys->delFLAG;
        if('Y' == memberSys->delFLAG || 'y' == memberSys->delFLAG){
            memberSys->memberInfo[location] = memberSys->memberInfo[memberSys->index-1];//将最后一位联系人挪来补充空缺
            memberSys->index--;
            cout<<"成功删除关于"<<memberName<<"相关信息!"<<endl;
    }
       
    }

}
void modMember(struct System *memberSys, string memberName);//pre-definition
//实现联系人查找
//需要传入的参数，待删除人员的姓名，通讯录
//设置删除选项,并将删除选择标志传回
void showMember(struct System *memberSys, string memberName){
    int location = findMember(memberSys, memberName);    
    if(-1 == location){
    cout<<"没有这个人，不需要执行删除操作！"<<endl;
        }
	else{
		cout<<"姓名："<<memberSys->memberInfo[location].memberName<<endl;
		cout<<"性别："<<memberSys->memberInfo[location].memberGender<<endl;
		cout<<"年龄："<<memberSys->memberInfo[location].memberAge<<endl;
        cout<<"电话："<<memberSys->memberInfo[location].memberPhone<<endl;
        cout<<"联系地址："<<memberSys->memberInfo[location].memberAddress<<endl;
		cout<<"家庭住址："<<memberSys->memberInfo[location].memberHome<<endl;
		cout<<"可执行操作：修改联系人(M)/删除联系人(D)"<<endl;
    	cin>>memberSys->delFLAG;
        if('D' == memberSys->delFLAG || 'd' == memberSys->delFLAG){
            delMember(memberSys, memberName);
        }
        else if('m' == memberSys->delFLAG || 'M' == memberSys->delFLAG){
            modMember(memberSys, memberName);
        }
	}
    
}

//showAddMember
void showAddMember(struct System *memberSys, string memberName){
    int location = findMember(memberSys, memberName);    
    if(-1 == location){
    cout<<"没有这个人！"<<endl;
        }
	else{
		cout<<"姓名："<<memberSys->memberInfo[location].memberName<<endl;
		cout<<"性别："<<memberSys->memberInfo[location].memberGender<<endl;
		cout<<"年龄："<<memberSys->memberInfo[location].memberAge<<endl;
        cout<<"电话："<<memberSys->memberInfo[location].memberPhone<<endl;
        cout<<"联系地址："<<memberSys->memberInfo[location].memberAddress<<endl;
		cout<<"家庭住址："<<memberSys->memberInfo[location].memberHome<<endl;
	}
    
}


//修改联系人
//根据名字索引，并且传入新的属性值进行替换
void modMember(struct System *memberSys, string memberName){
    int location = findMember(memberSys, memberName); 
    struct Member newMemberInfo;
    struct Member tempMember;
    char sureFLAG = 'N';
    
    if(-1 == location){
    cout<<"没有这个人，不能执行修改操作！是否新建联系人？"<<endl;
                       cin>>memberSys->newFLAG;
                       if('Y' == memberSys->newFLAG || 'Y' == memberSys->newFLAG){
                            addMember(memberSys);
					   }                     
        }
    else{
        cout<<"当前相关联系人信息为:"<<endl;
        showAddMember(memberSys, memberName);
        cout<<"是否修改？(Y/N)"<<endl;
        cin>>sureFLAG;
        if('Y' == sureFLAG || 'y' == sureFLAG){
            cout<<"请输入更新信息"<<endl;
            cout<<"姓名:";
            cin>>newMemberInfo.memberName;
            cout<<"性别:";
            cin>>newMemberInfo.memberGender;
            cout<<"年龄:";
            cin>>newMemberInfo.memberAge;
            cout<<"电话:";
            cin>>newMemberInfo.memberPhone;
            cout<<"联系地址:";
            cin>>newMemberInfo.memberAddress;
            cout<<"家庭住址:";
            cin>>newMemberInfo.memberHome;
            memberSys->memberInfo[location] = newMemberInfo;
            cout<<"更新后相关联系人信息为:"<<endl;
            showAddMember(memberSys, newMemberInfo.memberName);
        }
        else{

            cout<<"放弃修改。"<<endl;//不修改就执行空语句
        }

    }
}

void showAllMember(struct System *memberSys){
    if(0 == memberSys->index){
        cout<<"当前通讯录为空！"<<endl;
    }
    else{
        for(int i = 0; i< memberSys->index; i++){
            cout<<"第"<<i+1<<"个联系人的信息为:"<<endl;
            cout<<"姓名："<<memberSys->memberInfo[i].memberName<<endl;
            cout<<"性别："<<memberSys->memberInfo[i].memberGender<<endl;
            cout<<"年龄："<<memberSys->memberInfo[i].memberAge<<endl;
            cout<<"电话："<<memberSys->memberInfo[i].memberPhone<<endl;
            cout<<"联系地址："<<memberSys->memberInfo[i].memberAddress<<endl;
            cout<<"家庭住址："<<memberSys->memberInfo[i].memberHome<<endl;
        }
    }
}


//实现联系人添加
//传入参数为: 当前通讯录， 当前队列的末尾， 删除的空缺序列
//如果联系人容量已满，则显示无法添加
//在添加完联系人后，显示目标联系人，以便用于核对
void addMember(struct System *memberSys){
	if(99 <= memberSys->index){
	    cout<<"超出最大记录数,无法执行新建操作!"<<endl;
	}
	else{
	    struct Member newMemberInfo;
		char retryFLAG = 'R';
		while('R' == retryFLAG || 'r' == retryFLAG){
            cout<<memberSys->index<<endl;
			cout<<"请输入需要添加的人员的信息:"<<endl;
			cout<<"姓名:"<<endl;
			cin>>newMemberInfo.memberName;
			cout<<"性别:"<<endl;
			cin>>newMemberInfo.memberGender;
			cout<<"年龄:"<<endl;
			cin>>newMemberInfo.memberAge;
			cout<<"电话:"<<endl;
			cin>>newMemberInfo.memberPhone;
			cout<<"联系地址:"<<endl;
			cin>>newMemberInfo.memberAddress;
			cout<<"家庭住址:"<<endl;
			cin>>newMemberInfo.memberHome;
			memberSys->memberInfo[memberSys->index] = newMemberInfo;
            memberSys->index++;
            cout<<memberSys->index;
			cout<<"afterAdding"<<memberSys->index<<endl;
            cout<<"您添加的联系人信息为:"<<endl;
			showAddMember(memberSys, newMemberInfo.memberName);
            cout<<"如果想要重新添加请输入:R 结束请输入N。"<<endl;
            cin>>retryFLAG;
            if('R' == retryFLAG || 'r' == retryFLAG){
                memberSys->index--;
			    cout<<"retrying"<<memberSys->index<<endl;
            }
    }
		}
        cout<<memberSys->index;
        cout<<"ending"<<memberSys->index<<endl;

}





//清空联系人
//执行逻辑清零操作
void clearMember(struct System *memberSys){
    cout<<"是否要清空所有联系人？(Y/N)"<<endl;
    cin>>memberSys->clearFLAG;
    if('Y' == memberSys->clearFLAG || 'y' == memberSys->clearFLAG){
        memberSys->index = 0;
        cout<<"成功清零"<<endl;
    }
}

int main(){

//初始化参数
	struct Member initialMember[4] = {{"唐昆", "男", 24, "17772323526", "四川成都", "四川广安"},
                                  {"小鱼", "女", 24, "17711342362", "四川成都", "四川广安"},
                                  {"刘超", "男", 24, "18883778804", "四川成都", "四川广安"},
                                  {"黄洋", "男", 23, "18626060554", "四川成都", "四川自贡"}
                                 };
    int initialSize = sizeof(initialMember)/sizeof(initialMember[0]);
    struct Member memberInfo[100];
    for(int i = 0; i <4; i++){
        memberInfo[i] = initialMember[i];
    }
    struct System memSys = {'N', 'N', 'N', 'N', initialSize, memberInfo};
    struct System * memberSys = &memSys;


//DEBUG C0DE


//DEBUG CODE

    cout<<"是否查看当前通讯录?(Y/N)"<<endl;
    cin>>memberSys->activeFLAG;
        while('Y' == memberSys->activeFLAG || 'y' == memberSys->activeFLAG){
            char actionFLAG;//define a temp flag, which does not involved in cases of 'switch'
            string caozuoMemberName;
            showAllName(memberSys);
            cout<<"您想执行下面的什么操作？"<<endl;
            cout<<"1.添加联系人(A)"<<endl;
            cout<<"2.显示联系人(S)"<<endl;
            cout<<"3.删除联系人(D)"<<endl;
            cout<<"4.修改联系人(M)"<<endl;
            cout<<"5.清空联系人(C)"<<endl;
            cout<<"6.查找联系人(F)"<<endl;
            cout<<"7.退出通讯录(Q)"<<endl;
            cin>>actionFLAG;
            switch((int)actionFLAG){
				case (int)'A':{
					addMember(memberSys);
					break;
            }
				case (int)'S':{
                    showAllMember(memberSys);
                    break;
            }
                case (int)'D':{
                    cout<<"请输入要进行delete操作的人名字："<<endl;
                    cin>>caozuoMemberName;
                    delMember(memberSys, caozuoMemberName);
                    break;
            }
                case (int)'M':{
                    cout<<"请输入要进行操作的人名字："<<endl;
                    cin>>caozuoMemberName; 
                    modMember(memberSys, caozuoMemberName);
                    break;
            }
				case (int)'C':{
					cout<<"确定要执行清空操作？(Y/N)"<<endl;
                    cin>>memberSys->clearFLAG;
                    if('Y' == memberSys->clearFLAG){
						clearMember(memberSys);
					}
					break;}
				case (int)'F':{
					cout<<"您想查询谁的信息？"<<endl;
                    cin>>caozuoMemberName;
                    showMember(memberSys, caozuoMemberName);
                    break;}
				case (int)'Q':{
					char quitFLAG = 'N';	
					cout<<"确定退出通讯录?(Y/N)"<<endl;
                    cin>>quitFLAG;
					if('Y' == quitFLAG){
						memberSys->activeFLAG = 'N';
					}
					break;}
				default:{
					memberSys->activeFLAG = 'Y';
					break;                
                    }

            }
        }
}