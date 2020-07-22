#include<iostream>

using namespace std;

inline int Add(int& a,int& b){
  return a+b;
}

int main(){
  int a=10;
  int b=20;

  cout<<Add(a,b)<<endl;
  return 0;
}
