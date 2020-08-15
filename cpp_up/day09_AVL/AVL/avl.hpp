#include<iostream>

using namespace  std;

template <class T> 

struct  AVL_Node{
  AVL_Node(const T& val=T())
  :_left(nullptr)
   ,_right(nullptr)
   ,_parent(nullptr)
   ,_val(val)
   ,_bf(0)
  {

  }
  AVL_Node<T>* _left;
  AVL_Node<T>* _right;
  AVL_Node<T>* _parent;
  T _val;
  int _bf;
};

template <class T>
class AVL{
  typedef AVL_Node<T> Node;
  typedef Node* pNode;
public:
  bool Insert(const T val){
    if(_root==nullptr){
      _root=new Node(val);
      return true;
    }

    //当根结点不为空的时候
    pNode cur=_root;
    pNode parent=nullptr;

    while(cur){
      if(cur->_val>val){
        parent=cur;
        cur=cur->_left;
      }else if(cur->_val<val){
        parent=cur;
        cur=cur->_right;
      }else{
        return false;
      }
    }

    //找到合适的插入点
    cur=new Node(val);
    if(parent->_val>val){
      parent->_left=cur;
    }else if(parent->_val<val){
      parent->_right=cur;
    }

    cur->_parent=parent;
    
    while(parent){
      if(parent->_left==cur){
        --parent->_bf;
      }else if(parent->_right==cur){
        ++parent->_bf;
      }

      if(parent->_bf==0){
        break;
      }
      if(parent->_bf==-1 || parent->_bf==1){
        //该结点平衡继续向上调整
        cur=parent;
        parent=parent->_parent;
      }else if(parent->_bf==-2 || parent->_bf==2){
        //不平衡的状态
        if(parent->_bf==2 && parent->_right->_bf==1){
          //右边的右边高
          RotateL(parent);
        }else if(parent->_bf==-2 && parent->_left->_bf==-1){
          //左边的左边高
          RotateR(parent);
        }else if(parent->_bf ==2 && cur->_bf==-1){
          //右边的左边高
          //右左双旋
          pNode subR=cur;
          pNode subRL=subR->_left; 
          int bf=subRL->_bf; 


          RotateR(subR);
          RotateL(parent);

          if(bf==1){
            subR->_bf=0;
            parent->_bf=-1;
          }else if(bf==-1){
            subR->_bf=1;
            parent->_bf=0;
          }
        }else if(parent->_bf== -2 && cur->_bf==1){
          //左边的右面高
          //先左旋再右旋
          pNode subL=cur;
          pNode subLR=subL->_right;
          int bf=subLR->_bf; 

          RotateL(cur);
          RotateR(parent);

          if(bf==1){
            subL->_bf=-1;
            parent->_bf=0;
          }else if(bf==-1){
            subL->_bf=0;
            parent->_bf=1;
          }
        }
        break;
      }
    }
    return true;
  }    



  void InOrder(){
    if(!_root){
      return;
    }
    _InOrder(_root);
    cout<<endl;
  }

private:

  void RotateL(pNode parent){
    pNode subR=parent->_right;
    pNode subRL=subR->_left; 

    //开始旋转
    subR->_left=parent;
    parent->_right=subRL;

    if(subRL){
      subRL->_parent=parent;
    }

    if(parent!=_root){
      //若根节点不是parent
      pNode gParent=parent->_parent; 
      
      if(gParent->_left==parent){
        gParent->_left=subR;
      }else{
        gParent->_right=subR;
      }
      subR->_parent=gParent;
    }else{
      //parent为根结点
      _root=subR;
      subR->_parent=nullptr;
    }

    parent->_parent=subR;
    subR->_bf=parent->_bf=0;
  }

  void RotateR(pNode parent){
    //右旋的情况
    pNode subL=parent->_left;
    pNode subLR=subL->_right;

    //开始旋转
    subL->_right=parent;
    parent->_left=subLR;

    if(subLR){
      subLR->_parent=parent;
    }

    if(parent!=_root){
      //处理不是根结点的情况
      pNode gParent=parent->_parent; 
      if(gParent->_left==parent){
        gParent->_left=subL;
      }else{
        gParent->_right=subL;
      }
      subL->_parent=gParent;
    }else{
      //处理parent是根结点的情况
      subL->_parent=nullptr;
      _root=subL;
    }

    parent->_parent=subL;
    parent->_bf=subL->_bf=0;
  }



  void _InOrder(pNode root){
    if(root){
      _InOrder(root->_left);
      cout<<root->_val<<"-->";
      _InOrder(root->_right);
    }
  }
  pNode _root;
};
