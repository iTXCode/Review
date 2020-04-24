#include"hash.hpp"
#include"Unordered_map_set.hpp"
#include"bitSet.hpp"

void TestUnordered(){
  UnorderedMap<int,int> map;

  map.Insert(make_pair(1,1));
  map.Insert(make_pair(2,2));
  map.Insert(make_pair(3,3));
  map.Insert(make_pair(4,4));
  map.Insert(make_pair(5,5));

  UnorderedMap<int,int>::Iterator mit=map.Begin();
  UnorderedMap<int,int>::Iterator e=map.End();
  while(mit!=map.End()){
    cout<<mit->first<<"-->"<<mit->second<<endl;
    ++mit; 
  }
  
  UnorderedSet<int> set; 
  set.Insert(1);
  set.Insert(2);
  set.Insert(3);
  set.Insert(4);
  set.Insert(5);
  
  UnorderedSet<int>::Iterator sit=set.Begin();
  while(sit!=set.End()){
    cout<<*sit<<endl;
    ++sit; 
  }
}


void TestbitSet(){
  bitSet bset(1000);
  bset.Set(5);
  cout<<bset.TestBSet(5)<<endl;
  bset.Set(2);
  bset.ReSet(5);
}

int main(){
  //Test();
  //TestUnordered();
  TestbitSet();
  return 0;
}
