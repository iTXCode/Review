#include<iostream>
#include<functional>
#include<set>

using namespace std;

void TestSet(){
  set<int,greater<int>> testSet;
  testSet.insert(1);
  testSet.insert(2);
  testSet.insert(3);
  testSet.insert(5);
  testSet.insert(7);
  testSet.insert(4);
  testSet.insert(9);
  testSet.insert(8);

  for(const auto& e:testSet){
    cout<<e<<endl;
  }
}

int main(){
  TestSet();
  return 0;
}

