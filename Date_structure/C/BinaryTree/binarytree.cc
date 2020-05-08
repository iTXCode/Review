#include<iostream>
#include<stdlib.h>
#include<vector>
#include<queue>

using namespace std;

template <class T>
struct TreeNode{

  TreeNode(T data=T())
    :_left(nullptr)
     ,_right(nullptr)
     ,_data(data)
  {}
 TreeNode* _left;
 TreeNode* _right;
 T _data;
};

template <class T>

class Bitree{
  public:
  typedef TreeNode<T> Node;
  typedef Node* pNode;
  public:
  Bitree()
    :_root(nullptr)
  {}

  pNode getroot(){
    return _root;
  }
  void CreateTree(Bitree<T>* tree){
    _CreateTree(&(tree->_root));  
  }

  void PreOrderTravel(pNode root){
    if(root==nullptr){
      return;
    }
   cout<<root->_data;
   PreOrderTravel(root->_left);
   PreOrderTravel(root->_right);
  }


  //输出叶子结点
  void PreOrder(pNode root){
    if(root!=nullptr){
      if(root->_left==nullptr && root->_right==nullptr){
        cout<<root->_data<<" ";
      }
      PreOrder(root->_left);
      PreOrder(root->_right);
    }
  }


  //层序遍历
 
  void LevelTravel(pNode root){

    if(root==NULL){
      return;
    }
  
    if(root->_left==nullptr&&root->_right==nullptr){
      cout<<root->_data<<" ";
      return;  
    }
    queue<pNode> qu;
    qu.push(root);

    while(!qu.empty()){
      
      pNode node=qu.front();
      qu.pop();
      cout<<node->_data<<" ";

      if(node->_left){
        qu.push(node->_left);
      }
      if(node->_right){
        qu.push(node->_right);
      }
    }
  }

 //在二叉树中差找指定的值
  pNode Tree_Value_Find(pNode root,T value){
    if(root==nullptr){
      return nullptr;
    }
    if(root->_data==value){
      return root;
    }

    //往其左右孩子中去寻找该值
    pNode left=Tree_Value_Find(root->_left,value);
    if(left){
      return left;
    }
    pNode right=Tree_Value_Find(root->_right,value);
    if(right){
      return right;
    }
    return nullptr;
  }

  //计算叶子结点个数
  int Tree_Leaf_Num(pNode root){
    if(root==nullptr){
      return 0;
    }

    if(root->_left==nullptr && root->_right==nullptr){
      return 1;
    }
    int left=Tree_Leaf_Num(root->_left);
    int right=Tree_Leaf_Num(root->_right);

    return left+right;
  }

  //输出第K层的结点
  void K_Node(pNode root,int K){
    if(root==nullptr)
     return ;
    if(K==1){
      cout<<root->_data<<" ";
    }
    
    K--;
    K_Node(root->_left,K);
    K_Node(root->_right,K);
  }


  int K_Node_Num(pNode root,int K){
    if(root==nullptr)
      return 0;
    if(K==1){
      return 1;
    }

    K--;//此处先进行K--,是为了避免发生在执行递归过程中出现层数的错误
    return K_Node_Num(root->_left,K)+K_Node_Num(root->_right,K);
  }


  //求二叉树的高度或者深度
  int Tree_Height(pNode root){
    if(root==nullptr){
      return 0;
    }

    int left=Tree_Height(root->_left);
    int right=Tree_Height(root->_right);

    if(left>right){
      return 1+left;
    }else{
      return 1+right;
    }
  }


  bool IsComplete(pNode* root){
    if(root==nullptr){
      return nullptr;
    }

    if()
  }
  private:
  pNode _root;

  void _CreateTree(pNode* root){
    T _val;
    cin>>_val;
    if(_val=='#'){
      *root=nullptr;
    }else{
      if(*root==nullptr){
        (*root)=new Node(_val);
      }

      (*root)->_data=_val;
      _CreateTree(&( (*root)->_left ));
      _CreateTree(&( (*root)->_right ));
    }
  }
};


int main(){
  Bitree<char> tree;

  tree.CreateTree(&tree);
  TreeNode<char>*  root=tree.getroot();
  cout<<"前序遍历:";
  tree.PreOrderTravel(root);
  cout<<endl;
  
  //输出叶子结点
  cout<<"输出叶子结点:";
  tree.PreOrder(root);
  cout<<endl;

  //层序遍历
  cout<<"层序遍历结果:";
  tree.LevelTravel(root);
  cout<<endl;

  cout<<"请输入要查询的值";
  char find;
  cin>>find;
  TreeNode<char>* node=tree.Tree_Value_Find(root,find);
  if(node){
    cout<<"您要差找的值已经找到!"<<endl;
  }else{
    cout<<"您所差找的值不存在!"<<endl;
  }

  int num=tree.Tree_Leaf_Num(root);
  cout<<"叶子结点个数:"<<num<<endl;
 cout<<"请输出该二叉树那层上的结点:";
  int K;
  cin>>K;
 
  tree.K_Node(root,K);
  cout<<endl;

  cout<<"请输入您要求那一层的结点个数:";
  int num1;
  cin>>num1;

  int size=tree.K_Node_Num(root,num1);
  cout<<"第"<<num1<<"层共有"<<size<<"个结点!"<<endl;

  cout<<"该树的高度是:"<<tree.Tree_Height(root)<<endl;
  return 0;
}
