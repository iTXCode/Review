#include<iostream>
using namespace std;

class A{
  public:
    void Display(){
      std::cout<<_a<<std::endl;
      A::Print();
    }
    
    static void ADD();
    static void Print(){
      A::Display(); //静态成员函数内部不能调用非静态的成员函数
      A::ADD(); //静态成员函数可以调用静态成员函数
      cout<<"static void Print()"<<endl;
      cout<<_a<<endl; //静态成员函数内部可以使用静态成员变量
    }
  private:
    static int _a;
};

void A::Print(){
  std::cout<<_a<<std::endl;
}

int A::_a=10;

int main(){

  A a;
  a.Display();
  a.Print();
  return 0;
}
