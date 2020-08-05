#include<iostream>

using namespace  std;

template <class T>

class Unique_ptr{

  public:
    Unique_ptr(T* ptr=nullptr)
    :_ptr(ptr)
    {

    }

    ~Unique_ptr(){
      if(_ptr){
        delete _ptr;
        _ptr=nullptr;
        cout<<"~Unique_ptr()"<<endl;
      }
    }

    T& operator*(){
      return *_ptr;
    }

    T* operator->(){
      return _ptr;
    }
  private:
    //该类智能指针的缺点时不能进行拷贝和赋值
    Unique_ptr(const Unique_ptr<T>& ptr)=delete;
    Unique_ptr<T>&  operator=(const T& ptr)=delete;
    T* _ptr;
};

struct Date{
  int _year;
  int _month;
  int _day;

  ~Date(){
    cout<<"~Date()"<<endl;
  }
};

int main(){
  Unique_ptr<Date> u1(new Date);
  cout<<u1->_year<<endl;

 // Unique_ptr<Date> u2=u1;
 // Unique_ptr<Date> u3(u1);
 // 不允许使用拷贝和赋值功能
  return 0;
}
