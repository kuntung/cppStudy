//在源文件中实现类方法的定义
#include"pointer.h"

void Point::setX(float x){
            m_x = x;
        }
void Point::setY(float y){
    m_y = y;
}
float Point::getX(){
    return m_x;
}
float Point::getY(){
    return m_y;
}