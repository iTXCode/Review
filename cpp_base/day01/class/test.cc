#include<iostream>
#include<string.h>
#include<string>
using namespace std;

class Person{

  public:
    Person(char* name="jack",char *sex="男"){
      cout<<"Person()"<<endl;
      cout <<"name="<<name<<"sex="<<sex<<endl;
    }

    ~Person(){
      cout<<"~Person"<<endl;
    }

    Person(const Person& p){
      cout<<"Person(const Person&)"<<endl;
    }

    Person& operator =(const Person& p){
      cout<<"Person& operator="<<endl;
      return *this;
    }
  private:
    char* _name;
    char* _sex;
};

int main(){
  cout<<"p"<<endl;
  Person p("phil","女");
  cout<<"p1"<<endl;
  Person p1(p);
  cout<<"p2"<<endl;
  Person p2=p1;
  cout<<"p3"<<endl; 
  Person p3;
  p3=p;
  return 0;
}
