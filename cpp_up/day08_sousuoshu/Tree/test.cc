#include"Bitree.hpp"

int main(){
  BSTree<int> root;
  root.Insert(5);
  root.Insert(3);
  root.Insert(8);
  root.Insert(1);
  root.Insert(4);
  root.Insert(7);
  root.Insert(9);
  root.Insert(6);
  root.Insert(0);
  root.Insert(2);
  root.PreOrder();
  root.InOrder();
  root.LevelOrder();
  root.Erase(5);
  root.InOrder();
  root.LevelOrder();
  root.Erase(9);
  root.InOrder();
  root.Erase(7);
  root.InOrder();
  root.Erase(2);
  root.InOrder();
  return 0;
}
