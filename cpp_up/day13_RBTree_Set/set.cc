#include"Set.hpp"
#include<iostream>

using namespace std;

void TestSet(){
  bite::Set<int,int> set;
  set.Insert(pair<int,int>(10,20));
  set.Insert(make_pair(52,89));
  set[3]=100;

  auto it=set.begin();
  while(it!=set.end()){
    cout<<it->first<<" "<<it->second<<endl;
    it++;
  }

  cout<<"该容器中是否为空:"<<set.empty()<<endl;
}


int main(){
  TestSet();
  return 0;
}
