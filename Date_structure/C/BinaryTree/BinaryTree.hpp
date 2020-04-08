#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<queue>

typedef char  TreeType;

typedef struct TreeNode{
  struct TreeNode* _pLeft;
  struct TreeNode* _pRight;
  TreeType _data;
}TreeNode,* BiTree;

void CreateTree(BiTree* root){
  TreeType val;
  scanf("%c",&val);

  if(val=='#'){
    *root=NULL;
  }else{
    *root=(BiTree)malloc(sizeof(TreeNode));
    (*root)->_data=val;
    CreateTree(&(*root)->_pLeft);
    CreateTree(&(*root)->_pRight);
  }
}


//先序遍历
void PreOrderTravel(BiTree root){
  if(root!=NULL){
    printf("%c ",root->_data);
    PreOrderTravel(root->_pLeft);
    PreOrderTravel(root->_pRight);
  }
}

//中序遍历
void InOrderTreavel(BiTree root){
  if(root!=NULL){
    InOrderTreavel(root->_pLeft);
    printf("%c ",root->_data);
    InOrderTreavel(root->_pRight);
  }
}

//后序遍历
void PostOrderTravel(BiTree root){
  if(root!=NULL){
    PostOrderTravel(root->_pLeft);
    PostOrderTravel(root->_pRight);
    printf("%c ",root->_data);
  }
}

//输出树中的叶子结点的值
void PreOrder(BiTree root){
  if(root!=NULL) {  
    if(root->_pLeft==NULL && root->_pRight==NULL)
      printf("%c ",root->_data);
    PreOrder(root->_pLeft);
    PreOrder(root->_pRight); 
  }
}

//输出二叉树中叶子结点的个数
//定义一个全局变量记录叶子结点个数
int LeftCout=0;

int PostOrder(BiTree root){
  if(root!=NULL){
    PostOrder(root->_pLeft);
    PostOrder(root->_pRight);
    if(root->_pLeft==NULL&& root->_pRight==NULL){
      ++LeftCout;
    }
  }
  return LeftCout;
}

int Leaf(BiTree root){
  int leaf=0;
  
  if(root==NULL){
    leaf=0;
  }else if((root->_pLeft==NULL)&&(root->_pRight==NULL)){
    leaf=1;
  }else{
    leaf=Leaf(root->_pLeft)+Leaf(root->_pRight);
  }
  return leaf;
}

//求二叉树的高度或深度
int TreeDepth(BiTree root){
  if(root==NULL){
    return 0;
  }

  int left=TreeDepth(root->_pLeft);
  int right=TreeDepth(root->_pRight);

  return 1+(left>right?left:right);
}


//求第K层的结点个数
int KNode(BiTree root,int k){
  if(root==NULL){
    return 0;
  }

  if(k==1){
    return 1;
  }

  //根节点存在且k值大于等于2时
  return KNode(root->_pLeft,k-1)+KNode(root->_pRight,k-1);
}


TreeNode* Tree_Vlaue_Find(BiTree root,char value){
  if(root==NULL){
    return NULL;
  }
  if(root->_data==value){
    return root;
  }
  TreeNode* left=Tree_Vlaue_Find(root->_pLeft,value);
  if(left!=NULL)
  return left;
  TreeNode* right=Tree_Vlaue_Find(root->_pRight,value);
  if(right!=NULL){
    return right;
  }else{
    return NULL;
  }
}

//二叉树的层序遍历

void Levelordertravel(TreeNode* root){
  if(root==NULL)
    return;
  //只有一个根节点的时候
  if(root->_pLeft==NULL && root->_pRight==NULL){
    printf("%c",root->_data);
    return;
  }

  //拥有多个结点的时候
  //借助对列来实现层序遍历
  //先将根节点存放在队列中,将根结点取出的
  //同时将其左右子结点放到队列中
  std::queue<TreeNode*> qu;
  qu.push(root);

  while(!qu.empty()){
    //首先取出队列中的队首元素,并将其子结点压入队列
    TreeNode* front=qu.front();
    qu.pop();
    printf("%c ",front->_data);

    if(front->_pLeft!=NULL){
      qu.push(front->_pLeft);
    }

    if(front->_pRight!=NULL){
      qu.push(front->_pRight);
    }
  }
}
