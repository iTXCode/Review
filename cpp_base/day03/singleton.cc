#include<iostream>

//饿汉模式
//优点:简单
//缺点:可能会导致进程启动慢
//如果多个单例模式同时启动它们的启动顺序不能确定

 using namespace  std; 

class Singleton{
  public:
    static Singleton* getSingleton(){
      return &_sin;
    }
  private:

    Singleton(const Singleton& s)=delete;
    Singleton(){
      cout<<"Singleton:"<<&_sin<<endl;
    }

    //Singleton(const Singleton& s)=delete;
    //或者只声明不实现的方式也是可以的
    
    static Singleton _sin;

};

Singleton Singleton::_sin;

void Test(){
  Singleton *s=Singleton::getSingleton();
  Singleton *rs(s);
  cout<<rs<<endl;
  Singleton * rrs=Singleton::getSingleton();
  cout<<rrs<<endl;
}
int main(){
 Test(); 
  return 0;
}
