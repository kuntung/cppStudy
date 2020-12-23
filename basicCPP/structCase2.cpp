#include<iostream>
#include<string>

using namespace std;

struct Hero
{               
    string heroName;
    int age;
    string gender;
};

void popSort(struct Hero hero[], int size){
    
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i -1; j++){
            if(hero[j].age > hero[j+1].age){
                struct Hero temp = hero[j];
                hero[j] = hero[j+1];
                hero[j+1] = temp;
            }
        }
    }
}

void printHero(struct Hero hero[], int size){
    for(int i = 0; i < size; i++){
        cout<<hero[i].heroName<<": "<<hero[i].gender<<hero[i].age<<"岁."<<endl;
    }
}

int main(){

    Hero threeKindom[5] = {{"刘备",23,"男"}, {"关羽",22,"男"},{"张飞",20,"男"},{"赵云",21,"男"},{"马超",19,"男"}};

    int size = sizeof(threeKindom)/sizeof(threeKindom[0]);

    cout<<"排序前的结果:"<<endl;
    printHero(threeKindom, size);

    cout<<"排序前的结果:"<<endl;
    popSort(threeKindom, size);
    printHero(threeKindom, size);
        
    cout<<"this is governSystem"<<endl;

}