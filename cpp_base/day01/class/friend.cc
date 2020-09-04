#include<iostream>
 
using namespace  std;
class A{
 friend  void Add();
  public:
    class B{
      void Print(){
       A::ADD();
       //内部类可以访问外部类的静态成员函数


      A AA;
      AA.Del();
      cout<<AA.a<<endl;
      }
      private:
        int b=10;
    };
     static void ADD(){
        
    }
     void Del(){
       cout<<"Del()"<<endl;
     }
  private:
    int a=10;
};


void Add(){
  A A_a;
  cout<< A_a.a<<endl;
  A::ADD();
}

int main(){

  A a;
  //外部类的大小不包括内部类的大小
  std::cout<<sizeof(a)<<std::endl;
  Add();
  a.ADD();
  a.Del();
  return 0;
}
