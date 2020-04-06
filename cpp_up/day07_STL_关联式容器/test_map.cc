#include<iostream>
#include<map>
#include<string>

using namespace std;


int main(){
  map<int,string,greater<int>> testMap;
  testMap[0]="中国";
  testMap[1]="英国";
  testMap[2]="美国";
  testMap[3]="法国";
  testMap[4]="阿拉伯";
  testMap[5]="塞而维亚";
  testMap.insert(pair<int,string>(12,"china"));
  testMap.insert(make_pair(11,"俄罗斯"));
  for(auto& e:testMap){
    cout<<e.first<<" "<<e.second<<endl;
  }

  int key;
 // cin>>key;
 // if(testMap.find(key)!=testMap.end()){
 //   cout<<testMap[key]<<endl;
 // }
 
  while(cin>>key){
    if(testMap.count(key))
      cout<<key<<"-->"<<testMap[key]<<endl;
    else 
      cout<<"not find key"<<endl;
  }
  return 0;
}
