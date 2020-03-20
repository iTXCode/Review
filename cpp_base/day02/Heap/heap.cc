#include<iostream>

using namespace std;

//实现只能在堆上申请资源的类
class Heap{
  public:

    static Heap* getHeap(){
      
      return new Heap;
    }


    Heap(const Heap& hp)=delete;
  private:
    Heap(){

    }
};
//Heap::Heap(const Heap&hp){}
//显示重定义


void Test(){
  Heap *hp=Heap::getHeap();
  //Heap *hp2=new(hp) Heap; //提示Heap为私有的构造函数
  //Heap hp2(*hp);
  //提示调用已经删除的构造函数 
}
int main(){
  Test(); 
  return 0;
}

//即为实现一个不能再栈上申请资源的类
//实现方式
//1.构造函数私有化
//2.提供公共接口:在堆上创建对象
//3.在类外无法创建对象,函数用类名调用,公共接口必须为static接口
//4.方式拷贝,
//<1>拷贝构造私有化,只声明不实现
//<2>拷贝构造声明成delete函数
