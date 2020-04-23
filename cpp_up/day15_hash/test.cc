#include"hash.hpp"
#include"Unordered_map_set.hpp"

void TestUnordered(){
  UnorderedMap<int,int> map;
  map.Insert(make_pair(1,1));
  map.Insert(make_pair(2,2));
  map.Insert(make_pair(3,3));
  map.Insert(make_pair(4,4));
  map.Insert(make_pair(5,5));


  UnorderedSet<int> set;
  set.Insert(1);
  set.Insert(2);
  set.Insert(3);
  set.Insert(4);
  set.Insert(5);

}
void Test(){
  Closed::HashTable<int,int> ht;

  ht.Insert(make_pair(1,1));
  ht.Insert(make_pair(2,2));
  ht.Insert(make_pair(3,3));
  ht.Insert(make_pair(4,4));
  ht.Insert(make_pair(5,5));
  ht.Insert(make_pair(6,6)); 
}

int main(){
  //Test();
  TestUnordered();
  return 0;
}
