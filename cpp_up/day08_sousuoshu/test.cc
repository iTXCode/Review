#include"Bitree.hpp"


void TestTree(){
  BSTree<int> bt;
  bt.Insert(10);
  bt.InorderTravel();
  bt.Insert(2); 
  bt.InorderTravel();
  bt.Insert(1111); 
  bt.InorderTravel();
  bt.Insert(5); 
  bt.InorderTravel();
  bt.Insert(8); 
  bt.InorderTravel();
  bt.Insert(9); 
  bt.InorderTravel();

}

int main(){
  TestTree();
  return 0;
}
