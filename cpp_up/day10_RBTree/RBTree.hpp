#include<iostream>

using namespace std;
 
enum Color{
  Red,
  Black
};

template <class K,class V>

struct RBTNode{
  pair<K,V> _kv;
  Color _color=Red;
  RBTNode<K,V>* _left=nullptr;
  RBTNode<K,V>* _right=nullptr;
  RBTNode<K,V>* _parent=nullptr;
};

template <class K,class V>

class RBTree{
  public:
    typedef RBTNode<K,V> Node;
    typedef RBTNode<K,V>* pNode;

    RBTree()
      :_head(new Node)
    {
      _head->_left=_head;
      _head->_right=_head;
    }
  private:
    pNode _head;
};
