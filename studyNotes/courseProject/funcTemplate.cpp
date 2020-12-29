//
// Created by tangkun on 2020/12/29.
//

/*
 * ����������
 * 1. ���ú���ģ���װ����ĺ��������ԶԲ�ͬ�������������������
 * 2. �������Ӵ�С�������㷨Ϊѡ������
 * 3. �ֱ�����char�����int������в���
 */

#include<iostream>

using namespace std;

template<typename T>
void sort_func(T arr[], int length){ //ѡ������ģ��ʵ��
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