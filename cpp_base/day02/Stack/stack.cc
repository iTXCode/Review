#include<iostream>

using namespace std;


//只能在栈上,既杜绝一切在栈上申请资源的可能途径


class Stack{
  public:
    static Stack getStack(){
      return Stack(); 
      //此处的Stack会调用内部的私有化的构造函数
      //私有化的构造函数也杜绝了外部的new关键字
      //调用构造函数
    }
  private:
    Stack(){
      cout<<"Stack()"<<endl;
    };


    void* operator new(size_t n);
    void operator delete(void *p);
    //此时将operator new 和operator delete 
    //写成私有化的函数
};

int main(){
  Stack stack=Stack::getStack();
  //私有函数的调用方式类::函数名的形式
  Stack s(stack);
   
  return 0;
}
