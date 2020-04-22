#include"Set.hpp"
#include<iostream>

using namespace std;

void TestSet(){
  bite::Set<int> set;
  set.Insert(0);
  set.Insert(9);

  //先去执行operator[]操作(既插入的结点中first为[]中的值,second值为默认的类型值) 
  //执行完插入操作之后,执行return ret.first->second 
  //(既return ret.first.operator->()后去执行->second)
  //其中operator->()返回的值结点中kv的地址,
  //返回后将set[3]中second中默认的值改为100


  for(auto& e:set){
    cout<<e<<endl;
  }

  cout<<"该容器中是否为空:"<<set.empty()<<endl;
}


int main(){
  TestSet();
  return 0;
}
