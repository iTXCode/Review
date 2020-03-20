#include<iostream>
#include<mutex>
#include<thread>

using namespace std;

class Sigleton{
  public:
    static Sigleton* getSingleton(){
      if(_sin==nullptr){

        m_mut.lock();
        if(_sin==nullptr){
          _sin=new Sigleton();
        }

        m_mut.unlock();
      }
      return _sin;
    }


   // ~Sigleton(){
   //   if(_ps){
   //     delete _ps;
   //     //delete继续调用析构函数,造成无限递归
   //     _ps=nullptr;
   //   }
   // }
   //
   
    class ClearSigleton{
      public:
        ~ClearSigleton(){
          if(_sin){
            delete _sin;
            _sin=nullptr;
            cout<<"~ClearSigleton()"<<endl;
          }
        }
    };

    static ClearSigleton clear;
  private:
    Sigleton(  )
    {
      cout<<"Sigleton()"<<endl;
    } 
    //防止拷贝
    Sigleton(const Sigleton& s)=delete;
    Sigleton &operator=(Sigleton const &)=delete;
    //阻断直接赋值的路数
    static mutex m_mut;//互斥锁
    static Sigleton* _sin; //单例对象指针
};


Sigleton* Sigleton::_sin=nullptr;
Sigleton::ClearSigleton clear;
mutex Sigleton::m_mut; 


void Test(){
  for(int i=0;i<9;++i){
    cout<<Sigleton::getSingleton()<<endl; 
  }
}
int main(){
  Sigleton *s=Sigleton::getSingleton();
  Sigleton* s1=Sigleton::getSingleton();
  thread t1(Test);
  thread t2(Test);
  t1.join();
  t2.join();
  return 0;
}
