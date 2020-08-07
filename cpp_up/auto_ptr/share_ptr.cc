//#include<iostream>
//#include<memory>
//
//using namespace  std; 
//
//struct Date{
//  int _year;
//  int _month;
//  int _day;
//  ~Date(){
//    cout<<"~Date()"<<endl;
//  }
//};
//
//int main(){
//  shared_ptr<Date> s1(new Date);
//  shared_ptr<Date> s2=s1;
//  s1->_year=1997;
//  s2->_month=8;
//  s1->_day=1;
//  cout<<s1->_year<<"-"<<s1->_month<<"-"<<s1->_day<<endl;
//  cout<<s1.use_count()<<endl;
//  return 0;
//}


//#include<iostream>
//
//using namespace std;
//
//struct Date{
//  int _year;
//  int _month;
//  int _day;
//  Date(int year=1997,int month=8,int day=1)
//  :_year(year)
//   ,_month(month)
//   ,_day(day)
//  {
//
//  }
//
//  ~Date(){
//    cout<<"~Date()"<<endl;
//  }
//};
//
//
//template <class T>
//class Share_ptr{
//  public:
//    Share_ptr(T* ptr)
//    :_ptr(ptr)
//     ,_UseCount(new int(1))
//    {
//
//    }
//
//    Share_ptr(const Share_ptr<T>& ptr)
//      :_ptr(ptr._ptr)
//      ,_UseCount(ptr._UseCount)
//    {
//      ++(*_UseCount);
//    }
//
//    ~Share_ptr(){
//      if(--(*_UseCount)==0){
//        delete _ptr;
//        delete _UseCount;
//        _ptr=nullptr;
//        _UseCount=nullptr;
//      }
//    }
//
//    T& operator*(){
//      return *_ptr;
//    }
//
//    T* operator->(){
//      return _ptr;
//    }
//
//    Share_ptr<T>& operator=(const Share_ptr<T>& ptr){
//      if(_ptr!=ptr._ptr){
//        if(--(*_UseCount)==0){
//          delete _ptr;
//          delete _UseCount;
//        }
//        _ptr=ptr._ptr;
//        _UseCount=ptr._UseCount;
//        ++(*_UseCount);
//      }
//    }
//    int UseCount(){
//      return *_UseCount;
//    }
//
//  private:
//  T* _ptr;
//  int* _UseCount; //此处使用指针的原因是为了让所有对象
//  //都指向同一片地址
//};
//
//
//int main(){
//  Share_ptr<Date> s1(new Date);
//  Share_ptr<Date> s2=s1;
//  cout<<s1.UseCount()<<endl;
//  return 0;
//}
//


#include<iostream>
#include<memory>
using namespace  std; 




struct ListNode{
  int _data;
  weak_ptr<ListNode> _prev;
  weak_ptr<ListNode> _next;
  ~ListNode(){ 
    cout << "~ListNode()" << endl;  
  }
};

int main(){

  shared_ptr<ListNode> node1(new ListNode);
  shared_ptr<ListNode> node2(new ListNode);
  cout << node1.use_count() << endl;
  cout << node2.use_count() << endl;
  node1->_next = node2;
  node2->_prev = node1;
  cout << node1.use_count() << endl;
  cout << node2.use_count() << endl;
  return 0; 
}
