#include<iostream>

using namespace std;

class Person{
  public:
    virtual void  Add(int a=10,int b=20)=0;


};

class Student:public Person{
  public:
    virtual void Add(int a=10,int b=20){
      cout<<a+b<<endl;
    } 
    //重写了基类中的纯虚函数才能使用派生类来实例化 对象
};

int main(){
  Student st;
  st.Add();
  return 0;
}
