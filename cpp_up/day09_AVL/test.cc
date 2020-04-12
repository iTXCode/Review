#include"avl.hpp"

void testAVL(){
  int arr[]={16,3,7,11,9,26,18,14,15};
  Avl_Tree<int> avl;
  for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
    avl.Insert(arr[i]);
  }

  avl.Inorder();
}
int main(){
  testAVL();
  return 0;
}
