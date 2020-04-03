//using auto_ptr
#include<iostream>
#include<memory>

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

class Auto_Ptr{
  public:
    Auto_Ptr(T* ptr)
    :_ptr(ptr)
    {

    }

    Auto_Ptr(Auto_Ptr<T>& ap)
    :_ptr(ap._ptr)
    {
      ap._ptr=nullptr;
    }

    ~Auto_Ptr(){
      if(_ptr!=nullptr){
        delete _ptr;
        _ptr=nullptr;
      }
    }

    T* operator->(){
      return _ptr;
    }

    T& operator*(){
      return *_ptr;
    }

    Auto_Ptr& operator=(Auto_Ptr<T> &ap){
      if(this!=&ap){
        //释放当前对象中的资源
        if(_ptr){
          delete _ptr;
          _ptr=ap._ptr;
          ap._ptr=nullptr;
        }
      }
      return *this;
    }
  private:
    T* _ptr;
};

// 在拷贝赋值的过程中,将原来指针制空,来避免二次释放的问题
int main(){
  Auto_Ptr<Date> d(new Date);
  Auto_Ptr<Date> d1=d;
  return 0;
}
