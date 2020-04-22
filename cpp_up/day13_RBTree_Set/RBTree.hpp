#pragma  once
#include<iostream>
#include<functional>
using namespace std;
 
enum Color{
  Red,
  Black
};

template <class T>

struct RBTNode{
  RBTNode(const T& kv=T(),Color color=Red)
    :_kv(kv)
     ,_color(color)
     ,_left(nullptr)
     ,_right(nullptr)
     ,_parent(nullptr)
  {

  }
  T  _kv;
  Color _color;
  RBTNode<T>* _left;
  RBTNode<T>* _right;
  RBTNode<T>* _parent;
};

template <class T>
struct RBTreeIterator{
  typedef RBTNode<T> Node;
  typedef Node* pNode;
  typedef RBTreeIterator<T> Self;

  RBTreeIterator(pNode  PNode)
    :_pNode(PNode)
  {

  }

  RBTreeIterator()
    :_pNode(nullptr)
  {

  }

  RBTreeIterator(const Self&  s)
    :_pNode(s._pNode)
  {

  }
  //具有指针的操作
  T& operator*(){
    return _pNode->_kv;
  }

  T*  operator->(){
    //return &(operator*());
    //一般不直接取,通过解引用的方式来取地址
    return &_pNode->_kv;
  }

  //迭代器的移动
  //前置++
  Self& operator++(){
    Increament();
    return *this;
  }

  Self operator++(int){
    Self temp(*this);
    Increament();
    return temp;
  }

  //前置--
  Self& operator--(){
    DeIncreament();
    return *this;
  }

  Self operator--(int){
    Self temp(*this);
    DeIncreament();
    return temp;
  }

  bool operator==(const Self& s)const{
    return _pNode==s._pNode;
  }

  bool operator!=(const Self& s)const{
    return _pNode!=s._pNode;
  }

  private:

  void Increament(){
    if(_pNode->_right){
      _pNode=_pNode->_right;
      while(_pNode->_left){
        _pNode=_pNode->_left;
      }
    }else{
      //比_pNode大的元素可能在其双亲中
      Node* parent=_pNode->_parent;
      while(_pNode==parent->_right){
        _pNode=parent;
        parent=_pNode->_parent;
      }

      //根结点没有右子树,并且迭代器正好在根结点的位置
      if(_pNode->_right!=parent)
        _pNode=parent;
    }
  }

  void DeIncreament(){
    //end--能够走到最大节点的位置

    if (_pNode->_parent->_parent == _pNode&& Red==_pNode->_color){
    
      //当_pNode符合_pNode->_parent->_parent==_pNoded 
      //的时候说明_pNode是根结点或者_head,
      //_pNode->_color==Red则派出了_pNode是根结点的情况
      //则_pNode指向的是_head,其--指向了该树种最大的结点
      _pNode = _pNode->_right;
    }
    else if (_pNode->_left){
      //如果左子树存在,在左子树中找最大的节点
      _pNode = _pNode->_left;
      while (_pNode->_right){
        _pNode = _pNode->_right;
      }
    }
    else{
      //如果这个左子树不存在,就从该节点开始向上找
      Node* pParent = _pNode->_parent;
      while (_pNode == pParent->_left){
        _pNode = pParent;
        pParent = _pNode->_parent;
      }
      _pNode = pParent;
    }
  
  }
    private:
  Node* _pNode;
};

template <class K,class V,class KeyOfValue>

//因为关联式容器中的存储的是<Key,Value>的键值对,因此k为Key的类型
//ValueType:如果是map，则为pair<k,V>;如果是set，则为K
//KeyOfValue;通过value来获取key的一个仿函数
class RBTree{
  public:
    typedef RBTNode<V> Node;
    typedef Node*  pNode;
    typedef RBTreeIterator<V> Iterator;
   

    Iterator Begin(){
      return Iterator(_head->_left);
    }

    Iterator End(){
      return Iterator(_head);
    }

    Iterator Find(const V&data)const{
      pNode cur=_head->_parent;

      while(cur){
        if(KeyOfValue(data)==KeyOfValue(cur->_kv)){
          return Iterator(cur);
        
        }else if(KeyOfValue(data)<KeyOfValue(cur->_kv)) {
          cur=cur->_left;
        }else{
          cur=cur->_right;
        }
       return End();//没找到
    }
  }

    bool Empty()const{
      return _head->_parent==nullptr;
    }

    size_t Size()const{
      return _size;
    }
    /////////////////////////////////// 
    //Modify
    //在红黑树中插入data的键值对
    //若data中的key已经在红黑树中,则插入失败,返回<该结点的Iteator,false>
    //若data中的key不存在,则插入成功,返回<新的结点的迭代器，true>
    

  public:
    RBTree()
      :_size(0)
    {
      _head=new Node;
      _head->_left=_head;
      _head->_right=_head;
    }


    pair<Iterator,bool>  Insert(const V& kv){

      pNode pRoot=GetRoot();
      pNode pNewNode=nullptr;
    
      if(pRoot==nullptr){

        //第一次插入的时候插入的是根结点,且颜色为黑色
        /*pNode _root=new Node(kv);
        _root->_color=Black;
        _root->_parent=_head;
        _head->_left=_root;
        _head->_right=_root;
        _head->_parent=_root;
        return true;
        */
        pNewNode=pRoot=new Node(kv,Black);
        pRoot->_parent=_head;
        _head->_parent=pRoot;
        _head->_left=pRoot;
        _head->_right=pRoot;
        ++_size;
        return make_pair(Iterator(pNewNode),true);
      }
      else 
      {  //处理存在根结点的情况


        pNode cur=pRoot;

        pNode parent=nullptr;
        while(cur){
          parent=cur;
          if(KeyOfValue(cur->_kv) > KeyOfValue(kv)){
          
            cur=cur->_left;
          }else if(KeyOfValue(kv) > KeyOfValue(cur->_kv)){

            cur=cur->_right;
          }else{
            return make_pair(Iterator(cur),false);
          }
        }

        //进行插入
       pNewNode=cur=new Node(kv);


        if(KeyOfValue(cur->_kv) < KeyOfValue(parent->_kv)){
          parent->_left=cur;
        }else{
          parent->_right=cur;
        }

        cur->_parent=parent;

        //进行调整变色
        while(cur!=pRoot && parent->_color==Red){
   
          pNode gparent=parent->_parent;
          if(gparent->_left==parent){
            pNode uncle=gparent->_right;
            //u存在且为红
            if(uncle && uncle->_color==Red){
              //情况一
              parent->_color=Black;
              uncle->_color=Black;
              gparent->_color=Red;
              cur=gparent;
              parent=cur->_parent;
            }else{
              //u不存在 / 存在且为黑
              //1.以g为轴右旋
              //2.调整颜色,p为黑色,g为红色

              //检查是否为双旋场景:左右双旋
              if(parent->_right==cur){
                RotateL(parent);
                swap(parent,cur);
              }
              RotateR(gparent);
              parent->_color=Black;
              gparent->_color=Red;
              break;
            }
          }else{
            pNode uncle=gparent->_left;
            if(uncle && uncle->_color==Red){
              parent->_color=uncle->_color=Black;
              gparent->_color=Red;
              cur=gparent;
              parent=cur->_parent;

            }else{
              //u存在且为黑/u不存在
              if(parent->_left==cur){
                RotateR(parent);
                swap(cur,parent);
              }

              RotateL(gparent);
              gparent->_color=Red;
              parent->_color=Black;
              break; 
            }
          }

        }
      } 

      ++_size;
      //红黑树根始终是黑色的
      pRoot->_color=Black;
      //为了实现后续的迭代器,将head的左右指针指向最大,最小的值
      _head->_left=leftMost();
      _head->_right=rightMost();

      return make_pair(Iterator(pNewNode),true); 

    }

    pNode leftMost(){

      pNode pRoot=GetRoot();

      if(pRoot==nullptr){
        return _head;
      }
      pNode cur=pRoot;
      while(cur && cur->_left){
        cur=cur->_left;
      }
      return cur;
    }

    pNode rightMost(){

      pNode pRoot=GetRoot();
      if(pRoot==nullptr){
        return _head;
      }
      pNode cur=pRoot;
      while(cur && cur->_right){
        cur=cur->_right;
      }
      return cur;
    }

    void RotateL(pNode parent){
      pNode subR=parent->_right;
      pNode subRL=subR->_left;

      subR->_left=parent;
      parent->_right=subRL;

      if(subRL){
        subRL->_parent=parent;
      }

      if(parent!=_head->_parent){
        pNode gparent=parent->_parent;

        //判断parent之前是parent->_parent 的那一边的结点
        //把subR链接到对应的边
        if(gparent->_left==parent)
          gparent->_left=subR;
        else 
          gparent->_right=subR;
        //更新subR的parent
        subR->_parent=gparent;
      }
      else {
        //如果parent是根,subR变成新的根
        subR->_parent=_head;
        _head->_parent=subR;
      }

      //链接subR与parent
      parent->_parent=subR;      
    }

   void RotateR(pNode parent){
     pNode subL=parent->_left;
     pNode subLR=subL->_right;

     //1.单向链接subL,subLR,parent
     subL->_right=parent;
     parent->_left=subLR; 
     //2.向上链接subLR,parent 
     if(subLR){
       subLR->_parent=parent;
     }
     //3.双向链接subL与parent<_parent 
     if(parent!=_head->_parent){
       pNode gParent=parent->_parent;

       if(gParent->_left==parent){
         gParent->_left=subL;
       }else{
         gParent->_right=subL; 
       }

       //把subL的父亲结点改成其祖宗结点
       subL->_parent=gParent;
     }else{
       subL->_parent=_head;
       _head->_parent=subL; 
     }
     //4.向上链接parent,subL 
     parent->_parent=subL;
   }


/*
    void RotateL(Node* pParent){
          //左单旋,pParent的右子树高度较高导致
      Node* pSubR = pParent->_right;
      Node* pSubRL = pSubR->_left;

      pParent->_right = pSubRL;
      if (pSubRL){
        pSubRL->_parent = pParent;
      }
      pSubR->_left = pParent;
      Node* pPParent = pParent->_parent;
      pParent->_parent = pSubR;
      pSubR->_parent = pPParent;
      if (pPParent == _head)
        GetRoot() = pSubR;
      else{
        if (pPParent->_left == pParent){
          pPParent->_left = pSubR;
        }
        else{
          pPParent->_right = pSubR;
        }
      }
    }

    void RotateR(Node* pParent){
      //右单旋
      Node *pSubL = pParent->_left;
      Node *pSubLR = pSubL->_right;
      pParent->_left = pSubLR;
      if (pSubLR){
        pSubLR->_parent = pParent;
      }
      pSubL->_right = pParent;

      //原先的pParent可能还有双亲节点,所以需要将其
      //双亲节点保存一下
      Node* pPParent = pParent->_parent;
      pParent->_parent = pSubL;
      pSubL->_parent = pPParent;
      //pPParent 是根节点的时候
      if (pPParent == _head){
        GetRoot() = pSubL;
      }
      else{
        if (pPParent->_left == pParent)
          pPParent->_left = pSubL;
        else
          pPParent->_right = pSubL;
      }
    }
*/ 
    void Inorder(){
      _Inorder(_head->_parent);
      cout<<endl;
    }

    bool IsValidRBTree()
    {
      pNode pRoot = GetRoot();

      // 空树也是红黑树
      if (nullptr == pRoot)
        return true;

        // 检测根节点是否满足情况
        if (Black != pRoot->_color)
        {
          cout << "违反红黑树性质一：根节点必须为黑色!" << endl;
          return false;
        }
      // 获取任意一条路径中黑色节点的个数
      size_t blackCount = 0;
      pNode pCur = pRoot;
      while (pCur)
      {
        if (Black == pCur->_color)
          blackCount++;
        pCur = pCur->_left;
      }
      // 检测是否满足红黑树的性质，k用来记录路径中黑色节点的个数
      size_t k = 0;
      return _IsValidRBTree(pRoot, k, blackCount);
    }

  private:
    void _Inorder(pNode parent){
      if(parent){
        _Inorder(parent->_left);
        cout<<"Key:"<<parent->_kv.first<<"Value:"<<parent->_kv.second<<endl;
        _Inorder(parent->_right);
      }
    }

    pNode& GetRoot(){
      return _head->_parent;
    }

    
    bool _IsValidRBTree(pNode pRoot, size_t k, const size_t blackCount) {
      //走到null之后，判断k和black是否相等
      if (nullptr == pRoot)
      {
        if (k != blackCount)
        {
          cout << "违反性质四：每条路径中黑色节点的个数必须相同" << endl;
          return false;
        }
        return true;
      }

      // 统计黑色节点的个数
      if (Black == pRoot->_color)
        k++;
      // 检测当前节点与其双亲是否都为红色
      pNode pParent = pRoot->_parent;
      if (pParent && Red == pParent->_color && Red == pRoot->_color)
      {
        cout << "违反性质三：没有连在一起的红色节点" << endl;
        return false;
      }
      return _IsValidRBTree(pRoot->_left, k, blackCount) &&
        _IsValidRBTree(pRoot->_right, k, blackCount);
    }

  private:
    pNode _head;
    size_t _size;  //用于记录有效结点个数
};
