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

  UnorderedMap<string,string> m;
 
  m.Insert(make_pair("my","name"));
  m.Insert(make_pair("you","name"));

  auto it1=m.Begin();
  while(it1!=m.End()){
    cout<<it1->first<<"-->"<<it1->second<<endl;
      ++it1;
  }
}


void TestbitSet(){
  bitSet bset(1000);
  bset.Set(5);
  cout<<"该位图中是否存在数字5:"<<bset.TestBSet(5)<<endl;
  bset.Set(2);
  bset.ReSet(5);
}

int main(){
  //Test();
  //TestUnordered();
   TestbitSet();
  return 0;
}
