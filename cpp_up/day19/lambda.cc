#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//仿函数的使用

struct Compare{
  bool operator()(int a,int b){
    return a>b;
  }
};
void Test(){
  vector<int> v={0,-1,-5,9,8,4,2,1};
 
  for(auto& e:v){
    cout<<e<<" ";
  }
  cout<<endl;
  //对其进行排序可以使用std::sort 
  cout<<"默认排序:";
  sort(v.begin(),v.end());
  for(auto& e:v){
    cout<<e<<" ";
  }
  cout<<endl;
 
  //如果拍排序元素为自定义类型,需要用户定义排序时规则
  cout<<"仿函数方式排序:"; 
  sort(v.begin(),v.end(),Compare());
  for(auto& e:v){
    cout<<e<<" ";
  }
  cout<<endl;

}

int main(){
   Test();  
  return 0;
}
