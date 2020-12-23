//在这个源文件中实现饮品制作的类方法
#include"makeDrinking.h"

using  namespace std;
//对咖啡的制作流程方法进行定义
void Coffee::zhuShui(){//煮水的纯虚函数
	cout<<"煮水准备冲泡咖啡"<<endl;
}
void Coffee::chongPao(){//冲泡的纯虚函数
	cout<<"冲泡咖啡"<<endl;
}
void Coffee::daoBei(){//倒入杯子
	cout<<"倒入咖啡杯中"<<endl;
}
void Coffee::jiaLiao(){//加入辅料
	cout<<"加入咖啡料"<<endl;
}

//对茶的制作流程方法进行定义
void Tea::zhuShui(){//煮水的纯虚函数
	cout<<"煮水准备冲泡茶"<<endl;
}
void Tea::chongPao(){//冲泡的纯虚函数
	cout<<"冲泡茶"<<endl;
}
void Tea::daoBei(){//倒入杯子
	cout<<"倒入茶杯中"<<endl;
}
void Tea::jiaLiao(){//加入辅料
	cout<<"加入茶料"<<endl;
}

