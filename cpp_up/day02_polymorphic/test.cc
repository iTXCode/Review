#include<iostream>

using namespace std;


class Person{

  public:
   virtual  void BuyTicket(){
      cout<<"Person:全价"<<endl;
    }
};

class Student:public Person{
  public:
    virtual void BuyTicket(){
      cout<<"Student:半价"<<endl;
    }
};

void test(Person& p){
  p.BuyTicket();
}


int main(){
  Person p;
  Student s;
  test(p);
  test(s);
  return 0;
}

