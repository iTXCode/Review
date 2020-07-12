#include<iostream>

using namespace std;

class A{
  public:
    A(){

    }

    void Add(){
      cout<<"Add()"<<endl;
    }

    static void Sum(){
      cout<<A::i<<endl;
      //cout<<A::a<<endl;//静态成员函数不能访问非静态的成员变量
      //Add(); //不能调用非静态的成员函数
    }
      static int i;
  private:

      int a;
};

int A::i=1;

int main(){
  A a;
  A b;

  cout<<a.i<<" "<<b.i<<endl;
  return 0;
}
