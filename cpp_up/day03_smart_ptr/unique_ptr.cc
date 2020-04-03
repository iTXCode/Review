
//using unique_ptr 
//#include<iostream>
//#include<memory>
//
//using namespace std;
//
//struct Date{
//
//  int _year=1997;
//  int _month=8;
//  int _day=1;
//  ~Date(){
//    cout<<"~Date()"<<endl;
//  }
//};
//int main(){
//  unique_ptr<Date> d;
//  cout<<d->_year<<"年"<<d->_month<<"月"<<d->_day<<"日"<<endl;
// // unique_ptr<Date> d1=d;
// // unique_ptr<Date> d2(d);
//  //unique_ptr解决了拷贝和赋值的问题
//  //解决办法就是将拷贝构造函数删除了
//  return 0;
//}

//realize unique_ptr

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

class Unique_Ptr{
  public:
    Unique_Ptr(T* ptr)
    :_ptr(ptr)
    {

    }

    Unique_Ptr(const Unique_Ptr& p)=delete;

    ~Unique_Ptr(){
      if(_ptr){
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
  private:
    T* _ptr;
};

int main(){
  Unique_Ptr<Date> d(new Date);
  cout<<d->_year<<"年"<<d->_month<<"月"<<d->_day<<"天"<<endl;

//  Unique_Ptr<Date> d1=d;
//  Unique_Ptr<Date> d2(d);
//

  cout<<d->_year<<"年"<<d->_month<<"月"<<d->_day<<"天"<<endl;

  return 0;
}
