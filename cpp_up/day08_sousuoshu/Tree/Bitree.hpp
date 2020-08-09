#include<iostream>
#include<queue>
using namespace  std;

template <class T>

struct TreeNode{
  
  TreeNode(const T val)
    :_val(val)
     ,_left(nullptr)
     ,_right(nullptr)
  {}
  T _val;
  TreeNode<T>* _left;
  TreeNode<T>* _right;
};

template <class T>
class BSTree{
  typedef TreeNode<T> Node;
  typedef Node* pNode;
  public:
    BSTree()
    :_root(nullptr)
    {

    }
   
    
    //插入结点
    bool Insert(const T val){
      if(_root==nullptr){
        _root=new Node(val);
        return true;
      }

      //根结点存在,差找合适的插入位置
      pNode cur=_root;
      pNode parent=nullptr;

      while(cur){
        parent=cur;
        if(cur->_val > val){
          cur=cur->_left;
        }else if( cur->_val < val ){
          cur=cur->_right;
        }else{
          return false;
        }
      }

      cur=new Node(val);

      if(parent->_val > val){
        parent->_left=cur;
      }else if(parent->_val<val){
        parent->_right=cur;
      }
      return true;
    }

    pNode FindNode(const T& val){
      if(_root==nullptr){
        return nullptr;
      }

      //根结点存在的情况
      pNode cur=_root;
      while(cur){
        if(cur->val > val){
          cur=cur->_left;
        }else if(cur->_val < val){
          cur=cur->_right;
        }else if(cur->_val ==val){
          return cur;
        }
      }

      //没有找到
      return nullptr;
    }


    void PreOrder(){
      if(_root==nullptr){
        return ;
      }
      cout<<"前序遍历结果:";
      _PreOrder(_root);
      cout<<endl;
    }

    void InOrder(){
      if(_root==nullptr){
        return ;
      }
      cout<<"中序遍历结果:";
      _InOrder(_root);
      cout<<endl;
    }

    void LevelOrder(){
      if(_root==nullptr){
        return;
      }

      cout<<"层序遍历:";
      _LevelOrder(_root);
      cout<<endl;
    }

    bool Erase(const T& val){
      if(_root==nullptr)
        return false; 
      pNode cur=_root;
      pNode parent=nullptr;

      while(cur){
        if(cur->_val==val){
          break;
        }else if(cur->_val>val){
          parent=cur;
          cur=cur->_left;
        }else if(cur->_val<val){
          parent=cur;
          cur=cur->_right;
        }
      }

      if(cur==_root){
        if(cur->_left==nullptr && cur->_right==nullptr){
          _root==nullptr;
        }else if(cur->_right && cur->_left==nullptr){
         _root=_root->_right;
        }else if(cur->_left && cur->_right==nullptr){
          
        }
        delete cur;
        cur=nullptr;
     }
}
  private:
    void _PreOrder(const pNode root){
      if(root==nullptr)
        return;
      cout<<root->_val<<"-->";
      _PreOrder(root->_left);
      _PreOrder(root->_right);
    }

 void _InOrder(const pNode root){
      if(root==nullptr)
        return;

      _InOrder(root->_left);
      cout<<root->_val<<"-->";
      _InOrder(root->_right);
    }


 void _LevelOrder(const pNode root){
    queue<pNode> q;
    q.push(root);

    while(!q.empty()){
      pNode head=q.front();
      q.pop();

      cout<<head->_val<<"-->";

      if(head->_left){
        q.push(head->_left);
      }

      if(head->_right){
        q.push(head->_right);
      }
    }
 }
    pNode  _root;
};
