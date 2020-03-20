#include<iostream>

using namespace std;

class A{
  public:
    A()
      :_a(10)
    {
      cout<<"A()"<<endl;
    }


    ~A(){
      cout<<"~A()"<<endl;
    }
  private:
    int _a;
};

int main(){
  A* a=new A;
  cout<<&a<<endl;
  delete a;
  return 0;
}
