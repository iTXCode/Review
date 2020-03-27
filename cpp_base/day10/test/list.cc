#include<iostream>
#include<list>

using namespace std;
template <class T>

void Print(list<T>& l){
  list<int>::iterator it=l.begin();
  while(it!=l.end()){
    cout<<*it<<" ";
    ++it;
  }
  cout<<endl;
}

int main(){
  list<int> l;
  l.push_back(1);
  l.push_front(2);
  Print(l);


  list<int> l1(10,2);

  Print(l1);
  list<int> l2(l1.begin(),l1.end());
  Print(l2);

  list<int> l3(l2);
  Print(l3);

  cout<<"l.rbegin():"<<*l.rbegin()<<endl;
  cout<<"l.rend():"<<*l.rend() <<endl; 
  //返回的是最后一个元素下一个位置的reverse_itreator
  //既begin的位置
  cout<<"l.begin():"<<*l.begin()<<endl;
  cout<<"l.end():"<<*l.end()<<endl;

  return 0;
}
