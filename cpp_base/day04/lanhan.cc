#include<iostream>

using namespace std; 

//懒汉模式特点：
//第一次使用时候就创建好一个整个类唯一一个实例
class Singleton{
  public:
    static Singleton* getSingleton(){
 
      //为了保证只有第一次调用函数的时候才会申请资源
      //所以加上判断指向该类的指针是否为空
      //(判断是否为第一次调用使用该函数)
      if(_pInstance==nullptr){
        _pInstance= new Singleton; 
      }
      return _pInstance;
    }
  private:

    Singleton(){
      cout<<"Singleton()"<<endl;
    };
    
    Singleton(const Singleton& s)=delete; 

    Singleton *operator=( Singleton const & );


    static Singleton*  _pInstance;
};

Singleton* Singleton::_pInstance=nullptr;

void Test(){
  Singleton *s=Singleton::getSingleton();
}
int main(){
  Test();
  return 0;
}
