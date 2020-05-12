//#include<iostream>
//#include<map>
//#include<string>
//
//using namespace std;
//
//
//int main(){
//  map<int,string,greater<int>> testMap;
//  testMap[0]="中国";
//  testMap[1]="英国";
//  testMap[2]="美国";
//  testMap[3]="法国";
//  testMap[4]="阿拉伯";
//  testMap[5]="塞而维亚";
//  testMap.insert(pair<int,string>(12,"china"));
//  testMap.insert(make_pair(11,"俄罗斯"));
//  for(auto& e:testMap){
//    cout<<e.first<<" "<<e.second<<endl;
//  }
//
//  int key;
// // cin>>key;
// // if(testMap.find(key)!=testMap.end()){
// //   cout<<testMap[key]<<endl;
// // }
// 
//  while(cin>>key){
//    if(testMap.count(key))
//      cout<<key<<"-->"<<testMap[key]<<endl;
//    else 
//      cout<<"not find key"<<endl;
//  }
//  return 0;
//}
//


#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<map>


using namespace std;

//template <class T>
//void TestMap(vector<T>& words,int k){
//  map<string,int>  countMap;
//  vector<T> v;
//  for(const auto& e:words)
// {    
//   ++countMap[e];
//   cout<<countMap[e]<<endl;
// }
//  multimap<int,string,greater<int>> FrequentMap;
//
//  for(const auto& e:countMap){
//    FrequentMap.insert(make_pair(e.second,e.first));
//  }
//  for(const auto& e:FrequentMap){
//    if(k-- > 0){
//      v.push_back(e.second);
//    }else{
//      break;
//    }
//  }
//  auto it=v.begin();
//  while(it!=v.end()) {
//    cout<<*it<<" ";
//    it++;
//  }
//  cout<<endl;
//}
//
//int main(){
// vector<string> v;
// v.push_back("i");
// v.push_back("love");
// v.push_back("leetcode");
// v.push_back("i");
// v.push_back("love");
// v.push_back("coding");
//
// TestMap(v,2);
//  return 0;
//}
#include<vector>


int main(){
  map<int,int> m;
  vector<int> v={1,2,3,4,5,};
  m.insert(pair<int,int>(1,2));
  m.insert(pair<int,int>(2,3));
  m.size();
  for(auto& e:m){
    cout<<e.first<<endl;
  }

  int n=9;
  int i=1;
  int ret=0;
  while(n!=0){  
    ret+=(n&1);
    n=n>>1; 
  }
  cout<<ret<<endl;
  return 0;
}
