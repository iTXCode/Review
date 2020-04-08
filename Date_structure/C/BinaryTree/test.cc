#include"BinaryTree.hpp"

void TestTree(){
  BiTree root;
  CreateTree(&root);
  printf("前序遍历:");
  PreOrderTravel(root);
  printf("\n");
  printf("中序遍历:");
  InOrderTreavel(root);
  printf("\n");
  printf("后序遍历:");
  PostOrderTravel(root);
  printf("\n");

 int leaf= PostOrder(root);
 printf("该树共有%d个叶子结点;\n",leaf);

 int hight=TreeDepth(root);
 printf("该树的高度为:%d\n",hight);

 printf("层序遍历的结果:");
 Levelordertravel(root);
 printf("\n");

 printf("输入你所要查找的值:");
 char val='\0';
 std::cin>>val;
 TreeNode* cur=Tree_Vlaue_Find(root,val);
 std::cout<<cur<<std::endl;

}

int main(){
  TestTree();
  return 0;
}
