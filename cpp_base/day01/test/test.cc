#include<iostream>
#include<cstddef>

class Test{

  public:
  private:
    char a;
    char b;
    double c;
};


class A{
  public:
  char a;

  int t;
  char c;
  char b;
  double e;
};

int main(){
  Test t;
  A a;
  std::cout<<sizeof(t)<<std::endl;
  std::cout<<sizeof(a)<<std::endl;
 // printf ("offsetof(class A,a) is %d\n",(int)offsetof(class A,a));
 // printf ("offsetof(class A,t) is %d\n",(int)offsetof(class A,t));
 // printf ("offsetof(class A,c) is %d\n",(int)offsetof(class A,c));
 // printf ("offsetof(class A,b) is %d\n",(int)offsetof(class A,b));
 // printf ("offsetof(class A,e) is %d\n",(int)offsetof(class A,e));
  return 0;
}
