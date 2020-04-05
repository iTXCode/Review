//#include<iostream>
//#include<thread>
//#include<mutex>
//
//using namespace std; 
//
//
//template<class T>
//class Shared_Ptr{
//  public:
//    Shared_Ptr(T* ptr=nullptr)
//      :_ptr(ptr)
//       ,_UseCount(new int(1))
//       ,_mut(new mutex)
//  {
//
//  }
//
//    ~Shared_Ptr(){
//      Release();
//    }
//
//    Shared_Ptr(const Shared_Ptr<T>& sp)
//      :_ptr(sp._ptr)
//       ,_UseCount(sp._UseCount)
//       ,_mut(sp._mut)
//  {
//    Add_UseCount();
//  }
//
//    Shared_Ptr<T>& operator=(const Shared_Ptr<T>& sp){
//      if(_ptr!=sp._ptr){
//        //释放管理的旧的资源
//        Release();
//        //共享管理对象的资源,并增加引用计数
//        _ptr=sp._ptr;
//        _UseCount=sp._UseCount;
//        _mut=sp._mut;
//
//        Add_UseCount();
//      }
//      return *this;
//    }
//
//    T& operator*(){
//      return *_ptr;
//    }
//
//    T* operator->(){
//      return _ptr;
//    }
//    void Add_UseCount(){
//      //加锁或者使用加1的原子操作
//      //_mut->lock();
//      ++(*_UseCount);
//      //_mut->unlock();
//    }
// 
//    int UseCount(){
//      return *_UseCount;
//    }
//
//  private:
//    void Release(){
//      //用于控制引用计数
//     bool deleteFalg=false;
//
//    // _mut->lock();
//
//     if(--(*_UseCount)==0){
//       delete _ptr;
//       delete _UseCount;
//       deleteFalg=true;
//     }
//    // _mut->unlock();
//
//     if(deleteFalg==true){
//       delete _mut;
//     }
//    }
//  private:
//    T* _ptr;
//    int* _UseCount;
//    mutex* _mut;
//};

//int main(){
//  Shared_Ptr<int> sp(new int(10));
//  Shared_Ptr<int> sp1(sp);
//  *sp1=20;
//  cout<<"sp.UseCount():"<<sp.UseCount()<<endl;
//  cout<<"sp1.UseCount():"<<sp1.UseCount()<<endl;
// 
//  Shared_Ptr<int> sp2(new int(10));
//  sp1=sp2;
//  cout<<"sp.UseCount():"<<sp.UseCount()<<endl;
//  cout<<"sp1.UseCount():"<<sp1.UseCount()<<endl;
//  cout<<"sp2.UseCount():"<<sp2.UseCount()<<endl;
//
//  sp=sp2;
//
//  cout<<"sp.UseCount():"<<sp.UseCount()<<endl;
//  cout<<"sp1.UseCount():"<<sp1.UseCount()<<endl;
//  cout<<"sp2.UseCount():"<<sp2.UseCount()<<endl;
//
//  return 0;
//}

/*

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
      //_mut->lock();
      ++(*_UseCount);
      //_mut->unlock();
    }
 
    int UseCount(){
      return *_UseCount;
    }

  private:
    void Release(){
      //用于控制引用计数
     bool deleteFalg=false;

    // _mut->lock();

     if(--(*_UseCount)==0){
       delete _ptr;
       delete _UseCount;
       deleteFalg=true;
     }
    // _mut->unlock();

     if(deleteFalg==true){
       delete _mut;
     }
    }
  private:
    T* _ptr;
    int* _UseCount;
    mutex* _mut;
};


struct Date{
  int _year=1997;
  int _month=8;
  int _day=1;

  ~Date(){
    cout<<"~Date()"<<endl;
  }
};
static   Shared_Ptr<Date> sp(new Date);
void Func(){
  mutex mut;
  mut.lock();
  for(size_t  i=0;i<100;i++){
    Shared_Ptr<Date> p( sp );
    p->_year++;
    p->_month++;
    p->_day++;
  }
  mut.unlock();
  cout<<sp.UseCount()<<endl;
}

int main(){
  thread t1(Func);
  thread t2(Func);
  t1.join();
  t2.join();
 

  cout<<sp->_year<<endl;
  cout<<sp->_month<<endl;
  cout<<sp->_day<<endl;
  return 0;
}
*/ 


#include<iostream>
#include<thread>
#include<mutex>

using namespace std; 

mutex mut;

struct Date{
  int _year=1;
  int _month=1;
  int _day=1;

  ~Date(){
    cout<<"~Date()"<<endl;
  }
};


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
      if(subRef()==0){
        delete _ptr;
        delete _UseCount;
        delete _mut;
        _mut=nullptr;
        _ptr=nullptr;
        _UseCount=nullptr;
      } 
    }

    Shared_Ptr(const Shared_Ptr<T>& sp)
      :_ptr(sp._ptr)
       ,_UseCount(sp._UseCount)
       ,_mut(sp._mut)
  {
    addRef();
  }

    Shared_Ptr<T>& operator=(const Shared_Ptr<T>& sp){
  
      if(_ptr!=sp._ptr){
        if(subRef()==0){
          delete _ptr;
          delete _UseCount;
          delete _mut;
        }
        _ptr=sp._ptr;
        _UseCount=sp._UseCount;
        _mut=sp._mut;
        addRef();
      } 
      return *this;
    }

    T& operator*(){
      return *_ptr;
    }

    T* operator->(){
      return _ptr;
    }
    int  addRef(){
      //加锁或者使用加1的原子操作
      _mut->lock();
      ++(*_UseCount);
      _mut->unlock();
      return *_UseCount;
    }
 
    int UseCount(){
      return *_UseCount;
    }


    int subRef(){
      _mut->lock();
      --(*_UseCount);
      _mut->unlock();
      return *_UseCount;
    }
  private:
    T* _ptr;
    int* _UseCount;
    mutex* _mut;
};


void Test(Shared_Ptr<Date>&sp,size_t n=10000){
  for(size_t  i=0;i<n;i++){
  
    Shared_Ptr<Date> p( sp );
    mut.lock();
    p->_year++;
    p->_month++;
    p->_day++;
    mut.unlock();
  }
  cout<<sp.UseCount()<<endl;
}

int main(){
  Shared_Ptr<Date> sp(new Date);

  const size_t n=1000;
  thread t1(Test,sp,n);
  thread t2(Test,sp,n);
  t1.join();
  t2.join();


  cout<<sp->_year<<endl;
  cout<<sp->_month<<endl;
  cout<<sp->_day<<endl;
  return 0;
}
