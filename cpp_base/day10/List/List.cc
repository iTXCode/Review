#include<iostream>

using namespace std;

template <class T>
struct ListNode{

  ListNode(const T& val=T())
    :_prev(nullptr)
     ,_next(nullptr)
     ,_data(val)
  {

  }

  ListNode<T>* _prev;
  ListNode<T>* _next;
  T _data;
};

template <class T,class Ref,class Ptr>
struct ListIterator{
  typedef ListNode<T>* pNode;
  typedef ListIterator<T,Ref,Ptr>  self;
  pNode _node;
  ListIterator(pNode node)
  :_node(node)
  {}

  //++iterator 
  self& operator++(){
    _node=_node->_next;
    return *this;
  }

  //iterator++ 
  self& operator++(int){
    self tmp(*this);
    _node=_node->_next;
    return *tmp;
  }

  self& operator--(){
    _node=_node->_prev;
    return *this;
  }

  self& operator--(int){
    self tmp(*this);
    _node=_node->_prev;
    return tmp;
  }
  bool operator!=(const self& it){
    return _node!=it._node;
  }

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
    typedef   ListNode<T> Node;
    typedef  ListNode<T>* pNode;
    typedef ListIterator<T,T&,T*> iterator;
    typedef ListIterator<T,const T&,const T*> const_iterator;

    //const对象不能调用非const成员函数只能调用const成员函数operator++,
//operator--就不能执行了,不能修改成员_node的值
//导致const迭代器无法执行++，--操作,故这样定义const迭代器不可行
    List(const T& val=T())
      :_head(new Node(val))
    {
      _head->_prev=_head;
      _head->_next=_head;
    }

    List(const List<T>& lst){
      _head=new Node;
      _head->_next=_head;
      _head->_prev=_head;

      pNode cur=lst._head->_next;

      while(cur!=lst._head){
        Push_Back(cur->_data);
        cur=cur->_next;
      }
    }


    ~List(){
      Clear();
      if(_head){
        delete[] _head;
        _head=nullptr;
      }
    }
    void Push_Back(const T& val){
     // pNode new_node=new Node(val);
     // _head->_prev->_next=new_node;
     // new_node->_prev=_head->_prev;
     // new_node->_next=_head;
     // _head->_prev=new_node;
     Insert(end(),val);
    }
 
    void Print(const List<T>& l){
    
      pNode cur=l._head->_next;
      while(cur!=_head){
        cout<<cur->_data<<" ";
        cur=cur->_next;
      }
      cout<<endl;
    }

    List<T>& operator=( List<T>& lst){
      if(this!=&lst){
        pNode cur=lst._head->_next;
        while(cur!=lst._head){
          Push_Back(cur->_data);
          cur=cur->_next;
        }
      }
      return *this;
    }
    void Push_Front(const T& val){
     // pNode new_node=new Node(val);
     // pNode cur=_head->_next;
     // cur->_prev=new_node;
     // new_node->_prev=_head;
     // new_node->_next=cur;
     // _head->_next=new_node;
     
      Insert(begin(),val);
    }

    //迭代器实现
    
    iterator begin(){
      return iterator(_head->_next);
    }

    iterator end(){
      return iterator(_head);
    }

    iterator rbegin(){
      return iterator(_head);
    }

    iterator rend(){
      return iterator(_head->_next);
    }

    const_iterator cbegin() const{
      return const_iterator(_head->_next);
    }

    const_iterator cend() const{
      return const_iterator(_head);
    }

    void Insert(iterator pos,const T& val){
      pNode new_node=new Node(val);
      pNode cur=pos._node;
      pNode prev=cur->_prev;
      prev->_next=new_node;
      new_node->_prev=prev;
      new_node->_next=cur;
      cur->_prev=new_node;
    }

    void Clear(){
      if(_head){
        pNode cur=_head->_next;
        while(cur!=_head){
          pNode next=cur->_next;
          delete cur;
          cur=next;
        }
        _head->_next=_head;
        _head->_prev=_head;
      }
    }

    //Erase:迭代器失效
    //获取Erase的返回值,更新迭代器
    //返回的是当前被删除节点的下一个节点
    iterator Erase(iterator pos){
      if(pos!=end()){
        pNode cur=pos._node;
        pNode prev=cur->_prev;
        pNode next=cur->_next;
        prev->_next=next;
        next->_prev=prev;
        delete cur;
        pos=iterator(next);
      }
      return pos;
    }


    void PopFront(){
      Erase(begin());
    }

    void PopBack(){
      Erase(end());
    }
 
  private:
    ListNode<T>* _head;
};



template <class T>
void Print(const  List<T>& l){
  auto it=l.cbegin();
  while(it!=l.cend()){
    cout<<*it<<" ";
    ++it;
  }
  cout<<endl;
}

void Test(){
  List<int> l;
  l.Push_Back(1);
  l.Push_Back(2);
  l.Push_Back(3);
  l.Push_Front(5);
  l.Print(l);


  cout<<"l.begin():"<<l.begin()._node->_data<<endl;
  cout<<"l.end():"<<l.end()._node->_data<<endl;
  cout<<"l.rbegin():"<<l.rbegin()._node->_data<<endl;
  cout<<"l.rend():"<<l.rend()._node->_data<<endl;
  Print(l);
}


void Test1(){
  List<int> l;
  l.Push_Back(9);
  l.Push_Front(1);
  l.Push_Back(1);
  l.Push_Back(2);
  l.Push_Back(3);
  l.Push_Front(5);
  l.Print(l);
  cout<<"l.begin():"<<l.begin()._node->_data<<endl;
  cout<<"l.end():"<<l.end()._node->_data<<endl;
  cout<<"l.rbegin():"<<l.rbegin()._node->_data<<endl;
  cout<<"l.rend():"<<l.rend()._node->_data<<endl;
  l.Print(l);

  l.Insert(l.begin(),7);
  l.Insert(l.end(),6);
  l.Print(l);
 
  List<int> l1;
  l1=l;
  cout<<"l1:";
  Print(l1);

  List<int> l2(l);
  cout<<"l:";
  Print(l);
  cout<<"l2:";
  Print(l2);
}
int main(){
  Test();
  Test1();
  return 0;
}
