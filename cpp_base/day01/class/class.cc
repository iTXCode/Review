#include<iostream>

class Person{
  public:
  private:
};

class Person1{
  public:
  private:
    int _a;
    int _b;
};
int main(){

  Person s;
  Person1 s1;
  std::cout<<sizeof(s)<<std::endl;
  std::cout<<sizeof(s1)<<std::endl;
  return 0;
}
