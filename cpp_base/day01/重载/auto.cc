#include<iostream>
#include<stdio.h>
#include<typeinfo>
using namespace std;

int main(){
  int a = 10;
  auto b = a;
  double c = 20.3;
  auto d = c;
  cout <<typeid(a).name() << endl;
  cout << typeid(b).name() << endl;
  cout << typeid(c).name() << endl;
  cout << typeid(d).name() << endl;

  return 0;

}

