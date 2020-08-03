#include<iostream>

using namespace std;

class Parent{
  public: 
    void Print(){
      cout<<"In Parent!"<<endl;
    }
   int sum=1;
};

class child1:public Parent{
  public:
    void Print(){
      cout<<"In child1!"<<endl;
    }
    int sum=2;
};


int main(){
  Parent p;
  child1 c1;
  p.Print();
  c1.Print();

  cout<<"p.sum="<<p.sum<<endl;
  cout<<"c1.sum="<<c1.sum<<endl;
  cout<<"c1.Parent::sum="<<c1.Parent::sum<<endl;
  cout<<"c1.child1::sum="<<c1.child1::sum<<endl;
  return 0;
}
