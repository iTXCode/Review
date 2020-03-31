#include<iostream>
#include<string>
#include<string.h>
using namespace std;
template<class T>
void Copy(T* dst,const T* src,size_t size){
  memcpy(dst,src,sizeof(T)*size);
}

int main(){
  string s[3]={"11","22","33"};
  string s1[3];
  Copy(s1,s,3);
  return 0;
}
