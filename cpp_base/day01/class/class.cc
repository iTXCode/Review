//#include<iostream>
//
//class Person{
//  public:
//  private:
//};
//
//class Person1{
//  public:
//  private:
//    int _a;
//    int _b;
//};
//int main(){
//
//  Person s;
//  Person1 s1;
//  std::cout<<sizeof(s)<<std::endl;
//  std::cout<<sizeof(s1)<<std::endl;
//  return 0;
//}
//



//#include<iostream>
//
//using namespace std;
//
//class Date{
//  public:
//    void Print(){
//      cout<<this->_year<<"-"<<_month<<"-"<<_day<<endl;
//    }
//  private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//int main(){
//  Date d;
//  d.Print();
//  return 0;
//}



#include<iostream>

using namespace std;

class Date{
  public:
    Date(){
      cout<<"Date()"<<endl;
      _year=0;
      _month=0;
      _day=0;
    }

    ~Date(){
      cout<<"~Date()"<<endl;
    }
  private:

    int _year;
    int _month;
    int _day;
};


class Time{
  private:
    int _hour;
    int _minute;
    int _second;

    Date _d;
    //可以发现自定义的Date类型定义的变量
    //会自动调用其类型的构造函数
};

int main(){
  Time t;
  return 0;
}
