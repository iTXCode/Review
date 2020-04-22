#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<set>


using namespace std;

int main(){

  set<int> s;
  s.insert(1);

  unordered_map<int,int> map;
  map.insert(make_pair(0,1));
  map.insert(make_pair(4,2));
  map.insert(make_pair(9,5));
  map.insert(make_pair(5,6));
  auto it=map.begin();
  while(it!=map.end()){
    cout<<it->first<<" "<<it->second<<endl;
    it++;
  }
  cout<<map.max_size()<<endl;
  return 0;
}



//#include<iostream>
//#include<map>
//#include<unordered_map>
//#include<unordered_set>
//
//using namespace std;
//
//int main(){
//  map<int,int> map;
//  map.insert(make_pair(0,1));
//  map.insert(make_pair(4,2));
//  map.insert(make_pair(9,1));
//  map.insert(make_pair(5,2));
//  auto it=map.begin();
//  while(it!=map.end()){
//    cout<<it->first<<" "<<it->second<<endl;
//    it++;
//  }
//
//  return 0;
//}
