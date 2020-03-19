#include<iostream>

class A{
  public:
    class B{
      private:
        int b;
    };
  private:
    int a=10;
};

int main(){

  A a;
  //外部类的大小不包括内部类的大小
  std::cout<<sizeof(a)<<std::endl;
  A::B b;
  return 0;
}
