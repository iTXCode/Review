#include"Bitree.hpp"

int main(){
  BSTree<int> root;
  root.Insert(1);
  root.Insert(2);
  root.Insert(0);
  root.Insert(9);
  root.PreOrder();
  root.InOrder();
  root.LevelOrder();
  root.Erase(1);
  root.InOrder();
  cout<<root.Erase(0)<<endl;
  root.InOrder();
  cout<<root.Erase(2)<<endl;
  root.InOrder();
  return 0;
}
