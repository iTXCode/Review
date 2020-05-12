#include<iostream>
#include<queue>
#include<functional>
#include<vector>
using namespace std;

int main(){
  priority_queue<int> q;
  vector<int> v{1,4,5,3,2,6,8,7,8,0};
  for(auto& e:v){
    q.push(e);
  }
  cout<<"q.top():"<<q.top()<<endl;

  //创建小堆,将三个模板参数换成greater比较方式
  
  priority_queue<int,vector<int>,greater<int>> q2(v.begin(),v.end());
  cout<<"q2.top():"<<q2.top()<<endl;
  return 0;
}
