/*
ͨ��c++ʵ��һ��ͨѶ¼����ϵͳ��ϵͳ����Ҫʵ�ֵĹ������£�
1.�����ϵ�ˣ���ͨѶ¼��������ˣ���Ϣ�������������Ա����䡢��ϵ��ַ����ͥ��ַ��������¼100��
2.��ʾ��ϵ�ˣ���ʾͨѶ¼��������ϵ����Ϣ
3.ɾ����ϵ�ˣ�������������ɾ��ָ����ϵ��
4.�޸���ϵ�ˣ��������������޸�ָ����ϵ��
5.�����ϵ�ˣ����ͨѶ¼��������Ϣ
6.������ϵ�ˣ����������鿴ָ����ϵ����Ϣ
7.�˳�ͨѶ¼���˳���ǰʹ�õ�ͨѶ¼
*/
/*˼·��
�ȹ���һ�����ڸ���Ľṹ�壬����������Ϣ�������� ����һϵ�к������������Ϊ�ṹ������
�ٹ���һ��������Ա�ṹ���ϵͳ�ṹ�壬���԰�����Ա�ṹ�壬�Լ�һЩ������־FLAG��
*/

#include<iostream>
#include<string>

using namespace std;

void addMember(struct System *memberSys);
//������ϵ�˽ṹ��
//�ṹ��������������Ա����䣬�绰����ϵ��ַ����ͥסַ
struct Member
{                       
    string memberName;
    string memberGender;
    int memberAge;
	string memberPhone;
    string memberAddress;
    string memberHome;
};

//����ͨѶ¼�ṹ��
//����ṹ����������У�һЩ����ִ�б�־����Ա�ṹ�壬��ǰβ������
struct System{
    char delFLAG;
    char newFLAG;
    char clearFLAG;
	char activeFLAG;
	int index;
    struct Member *memberInfo;
};


/*
����һ���ж�Ŀ����������λ�ñ�ŵĺ�����
����ֵΪ��ǰ��ѯ���ֵı�ţ������ѯΪ�գ��򷵻�-1�� �������ΪͨѶ¼������ѯ������, ������󳤶ȡ�
*/
int findMember(struct System *memberSys, string memberName){
    for(int i = 0; i < memberSys->index; i++){
        if(memberSys->memberInfo[i].memberName == memberName){
            return i;
        }
    }
	return -1; //forѭ��������û���ҵ���֤��û�������    
}

//showName
void showAllName(struct System *memberSys){
    if(0 == memberSys->index){
        cout<<"��ǰͨѶ¼Ϊ�գ�"<<endl;
    }
    else{
        cout<<"��ǰͨѶ¼�����³�Ա��"<<endl;
        for(int i = 0; i< memberSys->index; i++){
            cout<<"��"<<i+1<<"����ϵ�˵�";
            cout<<"������"<<memberSys->memberInfo[i].memberName<<endl;
        }
    }
}

//ʵ����ϵ��ɾ��
//1. ��Ҫ������Ҫɾ����Ա������������ͨѶ¼
//2. ��ɶ�Ŀ����Ա�ļ�������������ɹ���ɾ�������ҰѺ���Ķ�����ǰ�ƶ���(���ߣ���¼�����ո��½���ʱ������ʹ�ÿո�)
//3. �������ʧ�ܣ���ʾ�޴���ϵ�ˣ�����������ʣ���ʱ����ʾ�Ƿ��½�����ϵ��
void delMember(struct System *memberSys, string memberName){
    int location = findMember(memberSys, memberName);    
    if(-1 == location){
    cout<<"û�������!"<<endl;
        }
    else{
        cout<<"ȷ��ɾ��(Y/N)"<<endl;
        cin>>memberSys->delFLAG;
        if('Y' == memberSys->delFLAG || 'y' == memberSys->delFLAG){
            memberSys->memberInfo[location] = memberSys->memberInfo[memberSys->index-1];//�����һλ��ϵ��Ų�������ȱ
            memberSys->index--;
            cout<<"�ɹ�ɾ������"<<memberName<<"�����Ϣ!"<<endl;
    }
       
    }

}
void modMember(struct System *memberSys, string memberName);//pre-definition
//ʵ����ϵ�˲���
//��Ҫ����Ĳ�������ɾ����Ա��������ͨѶ¼
//����ɾ��ѡ��,����ɾ��ѡ���־����
void showMember(struct System *memberSys, string memberName){
    int location = findMember(memberSys, memberName);    
    if(-1 == location){
    cout<<"û������ˣ�����Ҫִ��ɾ��������"<<endl;
        }
	else{
		cout<<"������"<<memberSys->memberInfo[location].memberName<<endl;
		cout<<"�Ա�"<<memberSys->memberInfo[location].memberGender<<endl;
		cout<<"���䣺"<<memberSys->memberInfo[location].memberAge<<endl;
        cout<<"�绰��"<<memberSys->memberInfo[location].memberPhone<<endl;
        cout<<"��ϵ��ַ��"<<memberSys->memberInfo[location].memberAddress<<endl;
		cout<<"��ͥסַ��"<<memberSys->memberInfo[location].memberHome<<endl;
		cout<<"��ִ�в������޸���ϵ��(M)/ɾ����ϵ��(D)"<<endl;
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
    cout<<"û������ˣ�"<<endl;
        }
	else{
		cout<<"������"<<memberSys->memberInfo[location].memberName<<endl;
		cout<<"�Ա�"<<memberSys->memberInfo[location].memberGender<<endl;
		cout<<"���䣺"<<memberSys->memberInfo[location].memberAge<<endl;
        cout<<"�绰��"<<memberSys->memberInfo[location].memberPhone<<endl;
        cout<<"��ϵ��ַ��"<<memberSys->memberInfo[location].memberAddress<<endl;
		cout<<"��ͥסַ��"<<memberSys->memberInfo[location].memberHome<<endl;
	}
    
}


//�޸���ϵ��
//�����������������Ҵ����µ�����ֵ�����滻
void modMember(struct System *memberSys, string memberName){
    int location = findMember(memberSys, memberName); 
    struct Member newMemberInfo;
    struct Member tempMember;
    char sureFLAG = 'N';
    
    if(-1 == location){
    cout<<"û������ˣ�����ִ���޸Ĳ������Ƿ��½���ϵ�ˣ�"<<endl;
                       cin>>memberSys->newFLAG;
                       if('Y' == memberSys->newFLAG){
                            addMember(memberSys);
					   }                     
        }
    else{
        cout<<"��ǰ�����ϵ����ϢΪ:"<<endl;
        showAddMember(memberSys, memberName);
        cout<<"�Ƿ��޸ģ�(Y/N)"<<endl;
        cin>>sureFLAG;
        if('Y' == sureFLAG || 'y' == sureFLAG){
            cout<<"�����������Ϣ"<<endl;
            cout<<"����:";
            cin>>newMemberInfo.memberName;
            cout<<"�Ա�:";
            cin>>newMemberInfo.memberGender;
            cout<<"����:";
            cin>>newMemberInfo.memberAge;
            cout<<"�绰:";
            cin>>newMemberInfo.memberPhone;
            cout<<"��ϵ��ַ:";
            cin>>newMemberInfo.memberAddress;
            cout<<"��ͥסַ:";
            cin>>newMemberInfo.memberHome;
            memberSys->memberInfo[location] = newMemberInfo;
            cout<<"���º������ϵ����ϢΪ:"<<endl;
            showAddMember(memberSys, newMemberInfo.memberName);
        }
        else{

            cout<<"�����޸ġ�"<<endl;//���޸ľ�ִ�п����
        }

    }
}

void showAllMember(struct System *memberSys){
    if(0 == memberSys->index){
        cout<<"��ǰͨѶ¼Ϊ�գ�"<<endl;
    }
    else{
        for(int i = 0; i< memberSys->index; i++){
            cout<<"��"<<i+1<<"����ϵ�˵���ϢΪ:"<<endl;
            cout<<"������"<<memberSys->memberInfo[i].memberName<<endl;
            cout<<"�Ա�"<<memberSys->memberInfo[i].memberGender<<endl;
            cout<<"���䣺"<<memberSys->memberInfo[i].memberAge<<endl;
            cout<<"�绰��"<<memberSys->memberInfo[i].memberPhone<<endl;
            cout<<"��ϵ��ַ��"<<memberSys->memberInfo[i].memberAddress<<endl;
            cout<<"��ͥסַ��"<<memberSys->memberInfo[i].memberHome<<endl;
        }
    }
}


//ʵ����ϵ�����
//�������Ϊ: ��ǰͨѶ¼�� ��ǰ���е�ĩβ�� ɾ���Ŀ�ȱ����
//�����ϵ����������������ʾ�޷����
//���������ϵ�˺���ʾĿ����ϵ�ˣ��Ա����ں˶�
void addMember(struct System *memberSys){
	if(99 <= memberSys->index){
	    cout<<"��������¼��,�޷�ִ���½�����!"<<endl;
	}
	else{
	    struct Member newMemberInfo;
		char retryFLAG = 'R';
		while('R' == retryFLAG || 'r' == retryFLAG){
            cout<<memberSys->index<<endl;
			cout<<"��������Ҫ��ӵ���Ա����Ϣ:"<<endl;
			cout<<"����:"<<endl;
			cin>>newMemberInfo.memberName;
			cout<<"�Ա�:"<<endl;
			cin>>newMemberInfo.memberGender;
			cout<<"����:"<<endl;
			cin>>newMemberInfo.memberAge;
			cout<<"�绰:"<<endl;
			cin>>newMemberInfo.memberPhone;
			cout<<"��ϵ��ַ:"<<endl;
			cin>>newMemberInfo.memberAddress;
			cout<<"��ͥסַ:"<<endl;
			cin>>newMemberInfo.memberHome;
			memberSys->memberInfo[memberSys->index] = newMemberInfo;
            memberSys->index++;
            cout<<memberSys->index;
			cout<<"afterAdding"<<memberSys->index<<endl;
            cout<<"����ӵ���ϵ����ϢΪ:"<<endl;
			showAddMember(memberSys, newMemberInfo.memberName);
            cout<<"�����Ҫ�������������:R ����������N��"<<endl;
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





//�����ϵ��
//ִ���߼��������
void clearMember(struct System *memberSys){
    cout<<"�Ƿ�Ҫ���������ϵ�ˣ�(Y/N)"<<endl;
    cin>>memberSys->clearFLAG;
    if('Y' == memberSys->clearFLAG || 'y' == memberSys->clearFLAG){
        memberSys->index = 0;
        cout<<"�ɹ�����"<<endl;
    }
}

int main(){

//��ʼ������
	struct Member initialMember[4] = {{"����", "��", 24, "17772323526", "�Ĵ��ɶ�", "�Ĵ��㰲"},
                                  {"С��", "Ů", 24, "17711342362", "�Ĵ��ɶ�", "�Ĵ��㰲"},
                                  {"����", "��", 24, "18883778804", "�Ĵ��ɶ�", "�Ĵ��㰲"},
                                  {"����", "��", 23, "18626060554", "�Ĵ��ɶ�", "�Ĵ��Թ�"}
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

    cout<<"�Ƿ�鿴��ǰͨѶ¼?(Y/N)"<<endl;
    cin>>memberSys->activeFLAG;
        while('Y' == memberSys->activeFLAG || 'y' == memberSys->activeFLAG){
            char actionFLAG;//define a temp flag, which does not involved in cases of 'switch'
            string caozuoMemberName;
            showAllName(memberSys);
            cout<<"����ִ�������ʲô������"<<endl;
            cout<<"1.�����ϵ��(A)"<<endl;
            cout<<"2.��ʾ��ϵ��(S)"<<endl;
            cout<<"3.ɾ����ϵ��(D)"<<endl;
            cout<<"4.�޸���ϵ��(M)"<<endl;
            cout<<"5.�����ϵ��(C)"<<endl;
            cout<<"6.������ϵ��(F)"<<endl;
            cout<<"7.�˳�ͨѶ¼(Q)"<<endl;
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
                    cout<<"������Ҫ����delete�����������֣�"<<endl;
                    cin>>caozuoMemberName;
                    delMember(memberSys, caozuoMemberName);
                    break;
            }
                case (int)'M':{
                    cout<<"������Ҫ���в����������֣�"<<endl;
                    cin>>caozuoMemberName; 
                    modMember(memberSys, caozuoMemberName);
                    break;
            }
				case (int)'C':{
					cout<<"ȷ��Ҫִ����ղ�����(Y/N)"<<endl;
                    cin>>memberSys->clearFLAG;
                    if('Y' == memberSys->clearFLAG){
						clearMember(memberSys);
					}
					break;}
				case (int)'F':{
					cout<<"�����ѯ˭����Ϣ��"<<endl;
                    cin>>caozuoMemberName;
                    showMember(memberSys, caozuoMemberName);
                    break;}
				case (int)'Q':{
					char quitFLAG = 'N';	
					cout<<"ȷ���˳�ͨѶ¼?(Y/N)"<<endl;
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