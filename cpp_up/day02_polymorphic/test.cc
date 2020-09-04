//#include<iostream>
//
//using namespace std;
//
//
//class Person{
//
//  public:
//   virtual  void BuyTicket(){
//      cout<<"Person:全价"<<endl;
//    }
//};
//
//class Student:public Person{
//  public:
//    virtual void BuyTicket(){
//      cout<<"Student:半价"<<endl;
//    }
//};
//
//void test(Person& p){
//  p.BuyTicket();
//}
//
//
//int main(){
//  Person p;
//  Student s;
//  test(p);
//  test(s);
//  return 0;
//}
//


#include<iostream>

using namespace  std;

class A{
  public:
  A(){
    cout<<"A"<<endl; 
  }
  ~A(){
    cout<<"~A"<<endl; 
  }

  static void Print(){
    cout<<"Print()"<<endl;
  }
};

class B: virtual public A{
  public:
    B(){
      cout<<"B()"<<endl;
    }

    ~B(){
      cout<<"~B()"<<endl; 
    }
};

int main(){

  A* a=new B;
  delete a;
  return 0;
}
