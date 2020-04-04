#include<iostream>

using namespace std;

struct Date{
  int _year=1997;
  int _month=8;
  int _day=1;

  ~Date(){
    cout<<"~Date()"<<endl;
  }
};
 
template<class T>
class Shared_Ptr{
  public:
    Shared_Ptr(T* ptr)
    :_ptr(ptr)
     ,_useCount(new int(1))
    {

    }

    Shared_Ptr(const Shared_Ptr<T>& sp)
    :_ptr(sp._ptr)
     ,_useCount(sp._useCount)
    {
      ++(*_useCount);
    }

    Shared_Ptr<T>& operator=(const Shared_Ptr<T>& sp){
      if(_ptr!=sp._ptr){
        if(--(*_useCount)==0){
          delete _ptr;
          delete _useCount;
        }
        _ptr=sp._ptr;
        _useCount=sp._useCount;
        ++(*_useCount);
      }
      return *this;
    }
    ~Shared_Ptr(){
      if(--(*_useCount)==0){
        delete _ptr;
        delete _useCount;
        _ptr=nullptr;
        _useCount=nullptr;
      }
    }

    T* operator->(){
      return _ptr;
    }

    T& operator*(){
      return *_ptr;
    }

    int useCount(){
      return *_useCount;
    }
  private:
    T* _ptr;
    int* _useCount;
};
int main(){
  Shared_Ptr<Date> sp(new Date);
  cout<<"sp.useCount():"<<sp.useCount()<<endl;
  Shared_Ptr<Date> spcopy(sp);
  Shared_Ptr<Date> sp2(new Date);
  cout<<"sp2.useCount():"<<sp2.useCount()<<endl;
  cout<<"sp.useCount():"<<sp.useCount()<<endl;
  sp2=sp;
  cout<<"sp.useCount()"<<sp.useCount()<<endl;
  cout<<"sp2.useCount()"<<sp2.useCount()<<endl;
  return 0;
}
