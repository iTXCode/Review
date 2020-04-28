#include"Bitree.hpp"


void TestTree(){
  BSTree<int> bt;
  bt.Insert(5);
  bt.InorderTravel();
  bt.Insert(3); 
  bt.InorderTravel();
  bt.Insert(4); 
  bt.InorderTravel();
  bt.Insert(1); 
  bt.InorderTravel();
  bt.Insert(2); 
  bt.InorderTravel();
  bt.Insert(0); 
  bt.InorderTravel();
  bt.Insert(7);
  bt.Insert(6);
  bt.Insert(8);
  bt.Insert(9);
  std::cout<<"前序遍历:";
  bt.PreOrderTravel();
  std::cout<<"中序遍历:";
  bt.InorderTravel();
  std::cout<<"后序遍历:";
  bt.PostOrderTravel();
  bt.Erase(5);
  bt.InorderTravel();
  bt.Erase(8);
  bt.InorderTravel();
  bt.Erase(0);
  bt.InorderTravel();
  bt.Erase(1);
  bt.InorderTravel();
  bt.Erase(2);
  bt.InorderTravel();
  bt.Erase(4);
  bt.InorderTravel();
  bt.Erase(3);
  bt.InorderTravel();
  bt.Erase(7);
  bt.InorderTravel();
  bt.Erase(6);
  bt.InorderTravel();
  bt.Erase(9);
  bt.InorderTravel();
}

int main(){
  TestTree();
  return 0;
}
