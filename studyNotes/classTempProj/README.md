# ��ģ�徭�䰸��
����������ʵ��һ��ͨ�õ������࣬Ҫ�����£�
1. ���Զ��������������Լ��Զ����������͵����ݽ��д洢
2. �������е����ݴ洢������
3. ���캯���п��Դ������������
4. �ṩ���ڵ�`�������캯��`�Լ�operator=��ֹ`ǳ��������`
5. �ṩβ�巨��βɾ���������е����ݽ������Ӻ�ɾ��
6. ����ͨ���±�ķ�ʽ���������е�Ԫ��
7. ���Ի�ȡ��ǰ������Ԫ�ظ��������������

![img.png](˼·.png)

## ֪ʶ���ܽ�
1. ��ģ��������������������ִ��뷽ʽ
    1. ָ����������ͣ�ֱ����ʾ�������������  **���**
       ```cpp
       //����һ�����������Զ��������Ԫ��
        void printArray(MyArray<int> &arr){
        for(int i = 0; i < arr.get_Size(); i++){
        cout<<arr[i]<<endl;
        }
        }
       ```
    2. ����ģ�廯���������еĲ�����Ϊģ����д���
    3. ������ģ�廯���������������ģ����д���
1. �������캯��
   ```cpp
       //�������캯��
    MyArray(const MyArray& arr){
        cout<<"MyArray�����������"<<endl;

        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        //this->pAddress = arr.pAddress; //ǳ��������
        this->pAddress = new T[arr.m_Capacity]; //���ʵ��

        //��arr�е����鶼��������
        for(int i = 0; i < arr.m_Size; i++){
            this->pAddress[i] = arr.pAddress[i];
        }
    }
   ```
2. ǳ��������
   
3. ���������
   ```c++
    //ʵ��ͨ���±귽ʽ���������е�Ԫ��
    T& operator[](int index){ //�������ã����������ݱ������Խ�����ֵ����
        return this->pAddress[index];
    }
   ```
4. �ຯ����������ʵ��
    ```cpp
    template<typename T>
    void MyArray<T>::print_end(){
            if(this->m_Size == 0){
                cout<<"��ǰ����Ϊ�գ��޷���ӡ"<<endl;
            }
            else{
                cout<<"��ǰ��������һ��Ԫ����:"
                    <<this->pAddress[this->m_Size-1]<<endl;
            }
    }
    ```
5. �Զ����������飬��`class`
    ```cpp
    //�����Զ�����������
    class Person{
    public:
        Person(){
    
        };
        Person(string name, int age){
            this->m_name = name;
            this->m_age = age;
        }
        string m_name;
        int m_age;
    
    };
    
    //�����ӡPerson����
    void printPersonArray(MyArray<Person> & arr){
    for(int i = 0; i < arr.get_Size(); i++){
    cout<<"����:" <<arr[i].m_name
    <<"����:" << arr[i].m_age<<endl;
    }
    }
    
    void test03(){
    MyArray<Person> arr(10);
    
    Person p1("�����", 999);
    Person p2("����", 20);
    Person p3("����", 35);
    Person p4("�ŷ�", 44);
    
    //�����ݲ��뵽������
    arr.Push_Back(p1);
    arr.Push_Back(p2);
    arr.Push_Back(p3);
    arr.Push_Back(p4);
    
    printPersonArray(arr);
    }
    ```
6. ��ģ����̳� 
   
   ����ģ�������̳�ʱ����Ҫע�����¼��㣺
   1. ������̳еĸ�����һ����ģ��ʱ��������������ʱ��Ҫָ����������T������
   2. �����ָ�����������޷�����������ڴ�
   3. ��������ָ����������T�����ͣ�����Ҳ���Ϊ��ģ��
   ```cpp
   //ʵ������̳�
   class sonArray :public MyArray<int>{ //����ָ��������T������
   public:
   sonArray(){
   cout<<"sonArray�Ĺ��캯��"<<endl;
   }
   };
   
   template<class T1 = int, class T2 = char> //��ģ��������Ϳ�����Ĭ��ֵ
   class sonArray1 :public MyArray<T1>{
   public:
   sonArray1(){
   cout<<"���๹�캯������" <<endl;
   }
   
       void show_info(){
           cout<<"�����Ϣ����:";
   //            <<"grade = " << this->m_grade<<endl;
   }
   private:
    T2 m_grade;
   };
   ```