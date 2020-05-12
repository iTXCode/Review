#include<iostream>
#include<assert.h>

using namespace std;

template <class T>
struct ListNode{
  ListNode(const T&val=T())
  :_prev(nullptr)
   ,_next(nullptr)
   ,_data(val)
  {}
  ListNode<T>* _prev;
  ListNode<T>* _next;
  T _data;
};

template <class T,class Ref,class Ptr>
struct ListIterator{
  typedef ListNode<T>* pNode;
  typedef ListIterator<T,Ref,Ptr> self;
  pNode _node;
  ListIterator(pNode node)
  :_node(node)
  {

  }

  //++iterator 
  self& operator++(){
    _node=_node->_next;
    return *this;
  }

  //iterator++
  self& operator++(int){
    self tmp(*this);
    _node=_node->_next;
    return tmp;
  }

  //--iterator 
  self& operator--(){
    _node=_node->_prev;
    return *this;
  }

  //iterator--
  
  self& operator--(int ){
    self tmp(*this);
    _node=_node->_prev;
    return tmp;
  }

  //比较两个节点不是同一个节点
  self& operator!=(const self& l){
    return _node!=l._node;
  }
  //解引用迭代器中的值
  //*iterator 
  Ref operator*(){
    return _node->_data;
  }
  Ptr operator->(){
    return &_node->_data;
  }
};
template <class T>

class List{
  public:
    typedef ListNode<T> Node;
    typedef ListNode<T>* pNode;
    typedef ListIterator<T,T&,T*>* iterator;
    typedef ListIterator<T,const T& ,const T*> const_iterator;
    List(const T& val=T())
      :_head(new Node(val))
    {
      _head->_prev=_head;
      _head->_next=_head;
      //只有一个节点的循环双链表
    }

    //拷贝构造的实现
    List(const List<T> & l){
       _head=new Node;
      _head->_prev=_head;
      _head->_next=_head;
      //需要将l中的值全部赋值到新申请的空间中
      for(auto e:l){
        Push_Back(e);
      }
    }

    //实现Push_Back()
    void Push_Back(const T& val){
      pNode ptr=new Node(val);
      _head->_prev->_next=ptr;
      ptr->_prev=_head->_prev;
      _head->_prev=ptr;
      ptr->_next=_head;
    }

//    ~List(){
//      if(_head){
//        delete[] _head;
//        _head=nullptr;
//      }
//    }
//

    //赋值运算符重载
    List<T>& operator=(const List<T>& lst ){
      if(this!=&lst){
        swap(_head,lst._head);
      }
      return *this;
    }

    void Push_Front(const T& val){
      pNode new_node=new Node(val);
      _head->_prev->_next=new_node;
      new_node->_prev=_head->_prev;
      new_node->_next=_head;
      _head->_prev=new_node;
      _head=new_node;
    }
    void Insert(iterator pos,const T& val){

      pNode new_node=new Node(val);
      pNode tmp=pos->_node;
      tmp->_prev->_next=new_node;
      new_node->_prev=tmp->_prev;
      new_node->_next=tmp;
      tmp->_prev=new_node;
    }

    void Print(const List<T>& l){
      pNode cur=l._head;
      cout<<cur->_data<<" ";
      cur=cur->_next;
      while(cur!=_head){
        cout<<cur->_data<<" ";
        cur=cur->_next;
      }
      cout<<endl;
    }
    //迭代器的定义和实现
    iterator begin(){
     return iterator(_head); 
    }

    iterator end(){
      return iterator(_head);

    }

    iterator rbegin(){
      return iterator( _head );
    }

    iterator rend(){
      return iterator(_head->_next );
    }
    const_iterator cbegin(){
      return iterator( _head->_next );
    }

    const_iterator cend(){
      return iterator( _head );
    }
  private:
    ListNode<T>* _head;
};


void Test(){
  List<int> l(1);
  l.Push_Back(2);
  l.Push_Back(3);
  l.Push_Front(4);
  l.Print(l);
  l.Insert(l.begin(),8);
  l.Print(l);
  l.Insert(l.end(),9);
  l.Print(l);
}

int main(){
  Test();
  return 0;
}
