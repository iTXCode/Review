#include<iostream>


using namespace std; 

template <class T>
class BSTNode{

  public:
    BSTNode(const T& val=T())
      :_value(val)
       ,_left(nullptr)
       ,_right(nullptr)
  {

  }
    T _value;
    BSTNode<T>* _left;
    BSTNode<T>* _right;
};

template <class T>
class BSTree{
  public:
    typedef BSTNode<T> Node;
    typedef Node* pNode;

    BSTree( pNode root=nullptr)
      :_root(root)
    {

    }

    pNode Find(const T& val){
      if(_root==nullptr){
        return nullptr;
      }

      pNode cur=_root;
      //确定根是否为查找的结点
      if(cur->_value==val){
        return cur;
      }

      while(cur!=nullptr){
        if(cur->_value==val){
          return cur;
        }
        //查看左子树中的内容
        else if(cur->_value>val){
          //如果其值大于需要查找的值,就到其右子树中去找
          cur=cur->_left;
        }else{
          cur=cur->_right;
        }
      }
      //没有找到的情况
      return nullptr;
    }

    bool Insert(const T& val){
      //先找到叶子结点
      //首先判断根节点是否存在
      if(_root==nullptr){
        _root=new Node(val);
        return true;
      }

      //判断插入值与结点值的大小关系决定
      //插入的位置
      pNode cur=_root;
      pNode parent=nullptr;
      while(cur){
        parent=cur;
        if(cur->_value>val){
          cur=cur->_left;
        }else if(cur->_value<val){
          cur=cur->_right;
        }else{
          return false;
        }
      }
      pNode new_node=new Node(val);

      if(parent->_value>val){
        parent->_left=new_node;
      }else{
        parent->_right=new_node;
      }
      return true; 
    }

    void InorderTravel(){
      _inorderTravel(_root);
      std::cout<<std::endl;
    }

    void _inorderTravel(pNode& root){
      if(root!=nullptr){
        _inorderTravel(root->_left);
        std::cout<<root->_value<<" ";
        _inorderTravel(root->_right);
      }
      
    }


    //删除
    bool Erase(const T& val){
      if(_root==nullptr){
        return false;
      }

      pNode cur=_root;
      pNode parent=nullptr;
      while(cur){
        parent=cur;
        if(cur->_value==val){
          break;
        }else if(cur->_value>val){
          parent=cur;
          cur=cur->_left;
        }else{
          parent=cur;
          cur=cur->_right;
        }
      }

      //删除的操作过程
      //先确定删除的结点是否为根结点
      //1.删除叶子结点
      if(cur->_left==nullptr && cur->_right==nullptr){  
        if(parent!=_root){
          if(parent->_left==cur){
            parent->_left=nullptr;
          }else{
            parent->_right=nullptr;
          }
        }else{
          _root==nullptr;
        }
        delete cur;
          cur=nullptr;
        }else if(cur->_left==nullptr){
        //父亲结点的一个孩子结点为空
          if(cur!=_root){
            if(parent->_left==cur){
              parent->_left=cur->_right;
            }else{
              parent->_right=cur->_right;
            }
          }else{
            _root=_root->_right;
          }
          delete cur;
          cur=nullptr;
      }
      ///TODO: 49:23

    }


    ~BSTree(){
      std::cout<<"~BSTree()"<<std::endl;
    }
  private:
    pNode  _root;
};

