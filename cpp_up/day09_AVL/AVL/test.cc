#include"avl.hpp"


int main(){
  AVL<int> root;
  root.Insert(1);
  root.Insert(2);
  root.Insert(3);
  root.Insert(4);
  root.InOrder();
  return 0;

}
