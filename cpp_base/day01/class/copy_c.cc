//#include<iostream>
//
//using namespace std;
//
//class Date{
//  public:
//    Date(int year=1997,int month=8,int day=1){
//      _year=year;
//      _month=month;
//      _day=day;
//      cout<<"Date()"<<endl;
//    }
//
//    ~Date(){
//      cout<<"~Date()"<<endl;
//    }
//    Date(const Date& d){
//
//      cout<<"Date(const &)"<<endl;
//      _year=d._year;
//      _month=d._month;
//      _day=d._day; 
//    }
//
//  private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//int main(){
//  Date d1(1998,1,28);
//  Date d2(d1);
//  return 0;
//}


#include<iostream>
#include<string.h>


using namespace std;

class String{

  public:
    String(const char* str="jack"){
      _str=(char*)malloc(sizeof(str)+1);
      strcpy(_str,str);
      cout<<"_str="<<_str<<endl;
    }

    ~String(){
      cout<<"~String"<<endl;
      free(_str);
    }

    String(const String& str){
      cout<<"String(const&)"<<endl;
    }

  private:
    char* _str;
};
int main(){
  String s1("hello");
  String s2(s1);
  return 0;
}
