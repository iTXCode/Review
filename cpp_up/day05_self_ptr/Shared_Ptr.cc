#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

mutex mux;

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

  private:
    T* _Ptr;
    int *_UseCount;
    mutex *_Mux;

  public:
    Shared_Ptr(T* ptr)
      :_Ptr(ptr)
       ,_UseCount(new int(1))
       ,_Mux(new mutex)
  {

  }

    Shared_Ptr(const Shared_Ptr<T>& sp)
      :_Ptr(sp._Ptr)
       ,_UseCount(sp._UseCount)
       ,_Mux(sp._Mux)
  {
    addRef();
  }

    int addRef(){
      _Mux->lock();
      ++(*_UseCount);
      _Mux->unlock();
      return *_UseCount;
    }

    Shared_Ptr<T>& operator=(const Shared_Ptr<T>& sp){
      if(_Ptr!=sp._Ptr){
        if(subRef()==0){
          delete _Ptr;
          delete _UseCount;
          delete _Mux;
          _Ptr=nullptr;
          _UseCount=nullptr;
          _Mux=nullptr;
        }
        _Ptr=sp._Ptr;
        _UseCount=sp._UseCount;
        _Mux=sp._Mux;
      }
      return *this;
    }
    int subRef(){
      _Mux->lock();
      --(*_UseCount);
      _Mux->unlock();
      return *_UseCount;
    }

    ~Shared_Ptr(){
      if(subRef()==0){
        delete _Ptr;
        delete _UseCount;
        delete _Mux;
        _Mux=nullptr;
        _UseCount=nullptr;
        _Ptr=nullptr;
      }
    }

    T& operator*(){
      return *_Ptr;
    }

    T* operator->(){
      return _Ptr;
    }

    int UseCount(){
      return *_UseCount;
    }
};


Shared_Ptr<Date> sp(new Date);

void Test(){

  for(size_t i=0;i<1000;i++){
    Shared_Ptr<Date> p(sp);
    mux.lock();
    
    p->_year++;
    p->_month++;
    p->_day++;
    mux.unlock();
  }

}


int main(){

  thread t1(Test);
  thread t2(Test);

  t1.join();
  t2.join();
  
   cout<<sp->_year<<endl;
   cout<<sp->_month<<endl;
   cout<<sp->_day<<endl;
  return 0;
}
