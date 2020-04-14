#include"avl.hpp"

void testAVL(){
  //int arr[]={16,3,7,11,9,26,18,14,15};
  //int arr[]={4,2,6,1,3,5,15,7,16,14};
  int arr[]={5,1,6,3,4};
  Avl_Tree<int> avl;
  for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
    avl.Insert(arr[i]);
  }
  avl.Isbalance();
  avl.Inorder();
}
int main(){
  testAVL();
  return 0;
}
