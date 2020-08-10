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
      if(_root==nullptr){
        return false;
      }

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

      if(cur->_left==nullptr && cur->_right==nullptr){
        if(cur!=_root){
          if(parent->_left==cur){
            parent->_left=nullptr;
          }else if( parent->_right==cur ){
            parent->_right=nullptr;
          }
        }else{
          _root=nullptr;
        }
        delete cur;
        cur=nullptr;
      }else if(cur->_right==nullptr){
        if(cur!=_root){
          //右子树为空,左子树不为空的情况
          if(parent->_left==cur){
            parent->_left=cur->_left;
          }else if(parent->_right==cur){
            parent->_right=cur->_left;
          }
        }else{
          _root=cur->_left;
        }
        delete cur;
        cur=nullptr;
      }else if(cur->_left==nullptr){
        if(cur!=_root){
          //左子树为空,右子树不为空的情况
          if(parent->_left==cur){
            parent->_left=cur->_right;
          }else if(parent->_right==cur){
            parent->_right=cur->_right; 
          }
        }else{
          _root=cur->_right;
        }
        delete cur;
        cur=nullptr;

      }else{
        //左右子树都不为空的情况
        pNode pNext=cur->_left; 
        parent=cur;
        
        if(pNext->_right){
          while(pNext->_right){
            parent=pNext;
            pNext=pNext->_right;
          }

          cur->_val=pNext->_val;
          if(pNext->_left){
            parent->_right=pNext->_left;
          }
          
          if(pNext->_left==nullptr){
            parent->_right=nullptr; 
          }
        }else if(pNext->_left){
          cur->_val=pNext->_val;
          cur->_left=pNext->_left;
        }else{
          //pNext的左右子树都为空
          cur->_val=pNext->_val;
          cur->_left=nullptr;
        }
        delete pNext;
        pNext=nullptr;
      }
      return true;
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
