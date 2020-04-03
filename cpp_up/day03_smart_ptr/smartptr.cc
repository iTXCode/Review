#include<iostream>
#include<memory>
using namespace std;

template <class T>
class SmartPtr{
  public:
    SmartPtr(T* ptr)
      :_ptr(ptr)
    {

    }


    ~SmartPtr(){
      if(_ptr!=nullptr){
        delete _ptr;
        _ptr=nullptr;
        cout<<"~SmartPtr"<<endl;
      }
    }

    T& operator*(){
      return *_ptr;
    }

    T* operator->(){
      return _ptr;
    }

    SmartPtr& operator=(const SmartPtr& p){
      if(this!=&p){
        _ptr=p._ptr;
      }
      return *this;
    }



  private:
    T* _ptr;
};
struct Date{
  int _year=1997;
  int _month=8;
  int _day=01;
  ~Date(){
    cout<<"~Date()"<<endl;
  }
};

int main(){
  SmartPtr<int> ptr(new int[1]);
  cout<<*ptr<<endl;
  *ptr=10;
  cout<<*ptr<<endl;

  SmartPtr<Date> p(new Date);
  cout<<p->_year<<"年"<<p->_month<<"月"<<p->_day<<"日"<<endl;

  p->_year=1998;
  p->_month=1;
  p->_day=28;
  cout<<p->_year<<"年"<<p->_month<<"月"<<p->_day<<"日"<<endl;

  return 0;
}
