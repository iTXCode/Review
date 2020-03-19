#include<iostream>

int main(){
  int *p1=NULL;
  *p1=1;
  std::cout<<*p1<<std::endl;
  //出现野指针,出现段错误
  int *p2=NULL;
  int a=10;
  p2=&a;
  std::cout<<*p2<<std::endl;
  return 0;
}
