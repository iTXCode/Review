#pragma  once 
#include<iostream>

using namespace std; 

enum Color{
  Red,
  Black 
};


template <class T>

struct RBTNode{
  RBTNode(const T& val=T(),Color color=Red)
  :_left(nullptr)
   ,_right(nullptr)
   ,_parent(nullptr)
   ,_color(color)
   ,_val(val)
  {

  }
  RBTNode<T>* _left;
  RBTNode<T>* _right;
  RBTNode<T>* _parent;
  Color _color;
  T _val;
};

template <class T>

class RBTree{
  typedef RBTNode<T> Node;
  typedef Node* pNode;
  public:
  RBTree()
  :_head(new Node)
  {
    _head->_left=_head;
    _head->_right=_head;
  }

  bool Insert(T& val){
    if(_head->_parent==nullptr){
      //第一次插入的时候头结点的父亲指针指向为空
      pNode _root=new Node(val);
      _root->_color=Black;
      _root->_parent=_head;
      _head->_left=_root;
      _head->_right=_root;
      _head->_parent=_root;
      return true;
    }
  }
  private:
    pNode _head;
};
