#include"Map_RBTree.hpp"

void testMap(){
  bite::Map<int ,string> m;
  m.Insert(pair<int,string>(1, "你好"));
  //m.Insert(pair<int,string>(2,"中国"));
  //m.Insert(pair<int,string>(3,"中国"));
  m.Insert(pair<int,string>(4,"将来"));
  m.Insert(make_pair(2,"比特"));

  m[3] = "中国";



  bite::Map<int,string>::Iterator t=m.begin(); 
  while(t!=m.end()){
    cout<<t->first<<" "<<t->second<<endl;
    t++;
  }

}

int main(){
  testMap();
  return 0;
}
