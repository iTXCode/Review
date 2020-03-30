#include<iostream>
#include<deque>


using namespace std;


void Print(const deque<int>& d){
  auto it=d.begin();
  while(it!=d.end()){
    cout<<*it<<" ";
    it++;
  }
 cout<<endl;
}




void Testiterator(const deque<int> & d){
  for(auto cit=d.cbegin();cit!=d.cend();cit++){
    cout<<*cit<<" ";
  }
  cout<<endl;

  for(auto it=d.rbegin();it!=d.rend();it++){
    cout<<*it<<" ";
  }
  cout<<endl;
}

void TestDeque(){
  deque<int> d{3,4,5};
  d.push_back(6);
  d.push_front(2);

  cout<<"d.size():"<<d.size()<<endl;
  cout<<"d.front():"<<d.front()<<endl;
  cout<<"d.back():"<<d.back()<<endl;
  Print(d);
  d.emplace_back(7);
  d.emplace_front(1);
  Print(d);
}
int main(){
  deque<int> d(10,5);
  Print(d);
  int array[]={0,1,2,3,4,5,6,7,9,8,10};
  deque<int> d1(array,array+sizeof(array)/sizeof(array[0]));
 
  
  Print(d1);
  deque<int> d2(d);
  Print(d2);
  Testiterator(d1);
  TestDeque();
  return 0;
}
