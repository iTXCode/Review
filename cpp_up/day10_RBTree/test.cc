#include"RBTree.hpp"


int main(){
  RBTree<int> rbt;

  int arr[]={5,7,9,1,3,4,10,6,8};
  for(auto& e:arr){
    rbt.Insert(e);
  }
  rbt.Inorder();
  return 0;
}
