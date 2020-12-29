//
// Created by tangkun on 2020/12/29.
//

/*
 * 案例描述：
 * 1. 利用函数模板封装排序的函数，可以对不同数据类型数组进行排序
 * 2. 排序规则从大到小，排序算法为选择排序
 * 3. 分别利用char数组和int数组进行测试
 */

#include<iostream>

using namespace std;

template<typename T>
void sort_func(T arr[], int length){ //选择排序法模板实现
    for(int i = 0; i < length; i ++){
        int minPos = i;
        for(int j = i + 1; j < length; j++){
            if(arr[minPos] < arr[j]){
                minPos = j;
            }
        }
        if(minPos != i){
            T temp = arr[i];
            arr[i] = arr[minPos];
            arr[minPos] = temp;
        }
    }
    cout<<"the sorted array is "<<endl;
    for(int i = 0; i < length; i ++){
           cout <<arr[i] <<" ";
    }
    cout << "\n";
}

int main(){
    char a[] = "abdasegqweasdgqukyghcgf";
    int num[] = {1, 3, 5, 4, 7, 9, 10};

    int length1 = sizeof(a)/sizeof(a[0]);
    cout<<"the length of a is " << length1 << endl;
    int length2 = sizeof(num)/sizeof(num[0]);
    cout<<"the length of num is " << length2 << endl;
    sort_func(a, length1);
    sort_func(num, length2);

    return 0;
}