//#include<iostream>
//#include<malloc.h>
//using namespace  std;
//
//class Test{
//  public:
//    Test(int data=0)
//      :_data(data)
//    {
//      cout<<"Test()"<<this<<endl;              
//    }
//
//    ~Test(){
//      cout<<"~Test():"<<this<<endl;
//    }
//  private:
//    int _data;
//    static int _sta;
//};
//
//int main(){
//  Test* ptr=(Test*)malloc(sizeof(Test));
//  new(ptr) Test(9);
//  delete (ptr);
//  cout<<sizeof(Test)<<endl;
//  return 0;
//}


//#include<iostream>
//
//using namespace std;
//
//class Singleton{
//  friend Singleton* Singleton();
//  public:
//    static Singleton* GetInstance(){
//      return &_sigleton;
//    }
//  private:
//    Singleton()
//
//    {};
//    Singleton(const Singleton& ){};
//    static Singleton _sigleton;
//};
//
//Singleton Singleton::_sigleton;
//
//
//int main(){
//
//  cout<<Singleton::GetInstance()<<endl;
//
//  cout<<Singleton::GetInstance()<<endl;
//
//  return 0;
//}


#include<iostream>
#include<mutex>
#include<thread>


using namespace std;

class Singleton{
  public:
    static Singleton* GetInstance(){
      if(m_Instance==nullptr){
        //添加双检查保证效率
        //不添加的话,第二次执行到这里就会先获取锁在进行判断
        //添加这个可以保证只有第一次执行的时候才能获取到锁
        _mut.lock();
        if(m_Instance==nullptr){
          //该层判断的目的在于保证不会再次调用构造函数
           m_Instance=new Singleton();
          
        } 
        _mut.unlock();
      }

      return m_Instance;
    }

    ~Singleton(){
      cout<<"~Singleton()"<<endl;
    }

  
    class ClearInstance{
      public:
      ~ClearInstance(){
        if(m_Instance){
          delete m_Instance;
          m_Instance=nullptr;
          cout<<"~ClearInstance()"<<endl;
        }
      }
    };

    static ClearInstance clear;
   private:
    Singleton(){};
    Singleton(const Singleton& )=delete;
    Singleton& operator =(Singleton const&)=delete;
  private:
    static Singleton* m_Instance;
    static mutex _mut;

};


mutex Singleton::_mut;
Singleton* Singleton::m_Instance=nullptr;
Singleton::ClearInstance clear;

void Fun(){
  for(int i=0;i<10;i++){
    cout<<Singleton::GetInstance()<<endl;
  }
}
int main(){

  Singleton* s=Singleton::GetInstance();
  Singleton* s1=Singleton::GetInstance();


  thread t1(Fun);
  thread t2(Fun);
  t1.join();
  t2.join();
  return 0;
}
