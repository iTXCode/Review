#include<iostream>

class A{
  public:
    void Display(){
      std::cout<<_a<<std::endl;
    }

    static void Print();
  private:
    static int _a;
};

void A::Print(){
  std::cout<<_a<<std::endl;
}

int A::_a=10;

int main(){

  A a;
  a.Display();
  a.Print();
  return 0;
}
