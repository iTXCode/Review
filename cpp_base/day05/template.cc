#include<iostream>

using namespace std;

template <class  T>

T Add(T a,T b){
  cout<<"a="<<a<<endl;
  cout<<"b="<<b<<endl;
  return a+b;
}

template <class T>
void  Swap(T& a,T& b){
  T temp=a;
  a=b;
  b=temp;
}


int main(){
  int a=10;
  int c=20;
  double b=12.10;
  cout<<Add<int>(a,b)<<endl;
  //其中的Add<int>是显示的指出了该函数调用的是
  //int类型的参数
  cout<<Add(a,c)<<endl;
  Swap(a,c);
  cout<<"change after a="<<a<<endl;
  cout<<"change after c="<<c<<endl;
  return 0;
}
