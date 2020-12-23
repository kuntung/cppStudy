//在源文件中实现类方法的定义
#include"circle.h"

 void Circle::setR(float radiu){
            m_R = radiu;
        }
void Circle::setCenter(Point center){
    m_Center = center;
}
float Circle:: getR(){
    return m_R;
}
Point Circle:: getCenter(){
    return m_Center;
}
void Circle::showLocation(Point p1){
    float dis = pow((p1.getX() - getCenter().getX()),2) + pow((p1.getY() - getCenter().getY()),2);
    float squareR = pow(getR(), 2);
    if(dis == 0){
        cout<<"点在圆心"<<"\n";
    }
    else if(dis < squareR){
        cout<<"点在圆内"<<"\n";
    }
    else if(squareR == dis){
        cout<<"点在圆上"<<"\n";
    }
    else{
        cout<<"点在圆外"<<"\n";
    }
}
            