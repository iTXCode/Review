#include<iostream>

using namespace std;

//实现只能在栈上申请资源的类

class StackOnly{
  public:
    static StackOnly getStack(){
      return StackOnly();
    }
  private:
    StackOnly(){

    }
};


class Stack{
  public:
  void *operator new(size_t n)=delete;
  private:
  Stack(){}
};
void Test(){
  //StackOnly *ps = new StackOnly;
  //已将构造函数私有化,所以new关键字不能再申请资源
  StackOnly s=StackOnly::getStack();
  //静态成员函数的调用方式,类型::函数名的方式
  StackOnly cp(s);
  //Stack ps=new Stack; //new方式被堵截
}
int main(){
 Test();
  return 0;
}
