#include<iostream>
#include<stack>

using namespace std;


int main(){
  stack<int> s;
  s.push(1);
  s.push(2);
  s.push(3);
  cout<<"s.size():"<<s.size()<<endl;
  cout<<"s.empty():"<<s.empty()<<endl;
  cout<<"s.top():"<<s.top()<<endl;
  cout<<"pop before:"<<endl;
  cout<<"s.top():"<<s.top()<<endl;
  s.pop();
  cout<<"pop after:"<<endl;
  cout<<"s.top():"<<s.top()<<endl;
  return 0;
}
