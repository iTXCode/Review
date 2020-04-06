#include<iostream>

using namespace  std;


int main(){
  const int a=10;
  int *pa;
  pa=const_cast<int*>(&a);
  *pa=20;
  cout<<"*pa="<<*pa<<endl;
  cout<<"a="<<a<<endl;
  return 0;
}
