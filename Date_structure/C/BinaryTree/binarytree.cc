#include<iostream>
#include<stdlib.h>
#include<vector>

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
      _CreateTree(&(*root)->_left);
      _CreateTree(&(*root)->_right);
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
  return 0;
}
