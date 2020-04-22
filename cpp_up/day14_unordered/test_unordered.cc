#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<time.h>
#include<vector>


using namespace std;

//int main(){
//
//  unordered_map<int,int> map;
//  map.insert(make_pair(0,1));
//  map.insert(make_pair(4,2));
//  map.insert(make_pair(9,5));
//  map.insert(make_pair(5,6));
//  auto it=map.begin();
//  while(it!=map.end()){
//    cout<<it->first<<" "<<it->second<<endl;
//    it++;
//  }
//  cout<<map.max_size()<<endl;
//  return 0;
//}

void Test(){
  unordered_set<int> uset;
  set<int> set;
  
  srand(time(nullptr));

  int n;
  cin>>n; 
  vector<int> v;
  for(int i=0;i<n;i++){
    v.push_back(rand());
  }

 size_t begin1=clock();
  for(const auto& e:v){
    set.insert(e);
  }
size_t end1=clock();
 
size_t begin2=clock();
for(const auto& e:v){
    uset.insert(e);
  }
size_t end2=clock();
cout<<"set insert time:"<<end1-begin1<<endl;
cout<<"Uset insert time:"<<end2-begin2<<endl;
}


int main(){
  Test();
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
