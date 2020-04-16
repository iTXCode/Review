#include"RBTree.hpp"


int main(){
  RBTree<int> rbt;

  int arr[]={5,7,9,1,3,4,10,6,8};
  for(auto& e:arr){
    rbt.Insert(e);
  }
  rbt.Inorder();
  cout<<"rbt is a 红黑树:"<<rbt.IsValidRBTree()<<endl;

  return 0;
}
