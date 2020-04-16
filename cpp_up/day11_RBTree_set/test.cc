#include"RBTree.hpp"
#include<functional>

int main(){
  RBTree<int,int> rbt;

  int arr[]={5,7,9,1,3,4,10,6,8};
  for(const auto& e:arr){
    rbt.Insert(make_pair(e,e));
  }
  rbt.Inorder();
  cout<<"rbt is a 红黑树:"<<rbt.IsValidRBTree()<<endl;

  return 0;
}
