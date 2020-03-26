#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void printVector(vector<int> &v){
    auto vit1 = v.begin();
    while (vit1 != v.end()){
          cout << *vit1 << " ";
              vit1++;
                
    }
      cout << endl;

}

void Print(vector<int> &v){
  auto vit=v.begin();
  while(vit!=v.end()){
    cout<<*vit<<" ";
    vit++;
  }
  cout<<endl;
}
void Testfind() {

  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  v.push_back(5);
  Print(v);
  vector<int>::iterator pos=find(v.begin(),v.end(),9);
  //没有找到的时候,返回的是v.end()的位置
  v.insert(pos,6);
  //指定位置插入内容,将后面的内容往后弄
  Print(v);
}

//erase删除位置的迭代器

void testErase(){
  vector<int> v(10, 2);
  v.erase(v.begin());
  printVector(v);
  v.erase(v.begin(), v.end()-3);
  //迭代器可以进行加减运算
  printVector(v);
}

int main(){
  testErase();
  Testfind();
  return 0;
}


