//#include<iostream>
//
//using namespace std; 
//
////懒汉模式特点：
////第一次使用时候就创建好一个整个类唯一一个实例
//class Singleton{
//  public:
//    static Singleton* getSingleton(){
// 
//      //为了保证只有第一次调用函数的时候才会申请资源
//      //所以加上判断指向该类的指针是否为空
//      //(判断是否为第一次调用使用该函数)
//      if(_pInstance==nullptr){
//        _pInstance= new Singleton; 
//      }
//      return _pInstance;
//    }
//  private:
//
//    Singleton(){
//      cout<<"Singleton()"<<endl;
//    };
//    
//    Singleton(const Singleton& s)=delete; 
//
//    Singleton *operator=( Singleton const & );
//
//    static Singleton*  _pInstance;
//};
//
//Singleton* Singleton::_pInstance=nullptr;
//
//void Test(){
//  Singleton *s=Singleton::getSingleton();
//}
//
//int main(){
//  Test();
//  return 0;
//}
// 该版本在多线程程序中存在线程的不安全问题
// 在获取资源的过程中线程因为抢占式的执行特点
//会导致资源的分配出现问题
//




#include<iostream>
#include<thread>
#include<mutex>


using namespace std; 

//懒汉模式特点：
//第一次使用时候就创建好一个整个类唯一一个实例
class Singleton{
  public:
    static Singleton* getSingleton(){
 
      //为了保证只有第一次调用函数的时候才会申请资源
      //所以加上判断指向该类的指针是否为空
      //(判断是否为第一次调用使用该函数)
      
      if(_pInstance==nullptr)
      {
        //保证只有第一次申请资源的时候才会
        //获取到线程安全锁
        m_mut.lock();
        if(_pInstance==nullptr){

          //为保证线程安全提供线程锁
          _pInstance= new Singleton;

        }
        m_mut.unlock(); 
      }
      return _pInstance;

    }

    /*
    ~Singleton(){
      if(_pInstance){
        delete _pInstance;
        //由于delete底层实现过程中是通过
        //调用析构函数来实现资源的释放的
        //所以在该过程是通过使用delete会造成
        //无线递归调用
        _pInstance=nullptr; 
      }
    }*/


    //此处通过内部类的方式来达成资源释放的目的
    //内部类是外部类的友元函数
    //然而该过程需要有一个触发机制
    //既在程序结束的时候会调用这个内部类
    //所以在使用的过程中,需要在外部类中定义一个变量

    
    class ClearSingleton{

      public:
        ~ClearSingleton(){
          if(_pInstance){
            delete _pInstance;
            _pInstance=nullptr;
            cout<<"~ClearSingleton()"<<endl;
          }
        }
    };

    static ClearSingleton clear;
  private:

    Singleton(){
      cout<<"Singleton()"<<endl;
    };
    
    Singleton(const Singleton& s)=delete; 

    Singleton *operator=( Singleton const & );

    static Singleton*  _pInstance;

     static mutex m_mut;//互斥锁,保证线程的安全
};

Singleton* Singleton::_pInstance=nullptr;
Singleton::ClearSingleton clear; 
mutex Singleton::m_mut; 

void Test(){
  for(int i=0;i<10;++i)
  {     
    cout<<Singleton::getSingleton()<<endl;
  }
}

int main(){
  Singleton* s=Singleton::getSingleton();
  Singleton* s1=Singleton::getSingleton();

  thread t1(Test);
  thread t2(Test);
  t1.join();
  t2.join();
  //不加锁，只有单个检查的时候两个进程会抢着执行
  //，有可能同行输出
  //加上锁单检查还是抢着执行,可能同行输出
  //加上锁双检查还是抢着执行,可能同行输出
  return 0;
}
