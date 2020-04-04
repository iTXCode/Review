#include<iostream>
#include<thread>
#include<mutex>

using namespace std; 


template<class T>
class Shared_Ptr{
  public:
    Shared_Ptr(T* ptr=nullptr)
      :_ptr(ptr)
       ,_UseCount(new int(1))
       ,_mut(new mutex)
  {

  }

    ~Shared_Ptr(){
      Release();
    }

    Shared_Ptr(const Shared_Ptr<T>& sp)
      :_ptr(sp._ptr)
       ,_UseCount(sp._UseCount)
       ,_mut(sp._mut)
  {
    Add_UseCount();
  }

    Shared_Ptr<T>& operator=(const Shared_Ptr<T>& sp){
      if(_ptr!=sp._ptr){
        //释放管理的旧的资源
        Release();
        //共享管理对象的资源,并增加引用计数
        _ptr=sp._ptr;
        _UseCount=sp._UseCount;
        _mut=sp._mut;

        Add_UseCount();
      }
      return *this;
    }

    T& operator*(){
      return *_ptr;
    }

    T* operator->(){
      return _ptr;
    }
    void Add_UseCount(){
      //加锁或者使用加1的原子操作
      _mut->lock();
      ++(*_UseCount);
      _mut->unlock();
    }
 
    int UseCount(){
      return *_UseCount;
    }

  private:
    void Release(){
      //用于控制引用计数
     bool deleteFalg=false;

     _mut->lock();

     if(--(*_UseCount)==0){
       delete _ptr;
       delete _UseCount;
       deleteFalg=true;
     }
     _mut->unlock();

     if(deleteFalg==true){
       delete _mut;
     }
    }
  private:
    T* _ptr;
    int* _UseCount;
    mutex* _mut;
};

int main(){
  Shared_Ptr<int> sp(new int(10));
  Shared_Ptr<int> sp1(sp);
  *sp1=20;
  cout<<"sp.UseCount():"<<sp.UseCount()<<endl;
  cout<<"sp1.UseCount():"<<sp1.UseCount()<<endl;
 
  Shared_Ptr<int> sp2(new int(10));
  sp1=sp2;
  cout<<"sp.UseCount():"<<sp.UseCount()<<endl;
  cout<<"sp1.UseCount():"<<sp1.UseCount()<<endl;
  cout<<"sp2.UseCount():"<<sp2.UseCount()<<endl;

  sp=sp2;

  cout<<"sp.UseCount():"<<sp.UseCount()<<endl;
  cout<<"sp1.UseCount():"<<sp1.UseCount()<<endl;
  cout<<"sp2.UseCount():"<<sp2.UseCount()<<endl;

  return 0;
}
