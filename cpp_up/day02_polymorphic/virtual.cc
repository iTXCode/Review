#include<iostream>

using namespace std;

class Person{

  public:
    virtual void Buy(){
      cout<<"Person::Buy"<<endl;
    }
  private:
};

class Student:public Person{
  public:
    virtual void Buy(){
      cout<<"Student::Buy"<<endl;
    }
};

void Func(Person& p){
  p.Buy();
  //同一件事情不同的对象做的结果不同
}

int main(){
  Person ps;
  Student st;
  Func(ps);
  Func(st);
  return 0;
}


