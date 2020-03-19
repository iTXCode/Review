#include<iostream>

using namespace std;

class Date{
  public:
    void Display(){
      cout<<"Display()"<<endl;
      cout<<"year:"<<++_year<<endl;
      cout<<"month:"<<_month<<endl;
      cout<<"day:"<<_day<<endl;
    }

     void Display()const{
      cout<<"Display()"<<endl;
      cout<<"year:"<<_year<<endl;
      //const修饰的是类中的this指针,其不允许
      //类中的成员变量被修改
      cout<<"month:"<<_month<<endl;
      cout<<"day:"<<_day<<endl;
    }
 
  private:
    int _year=1997;
    int _month=8;
    int _day=1;
};


void Test(){
  Date d1;
  d1.Display();

  const Date d2;
  d2.Display();
}
int main(){
  Test();
  return 0;
}
