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

int main(){

  return 0;
}
