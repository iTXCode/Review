#pragma  once
#include<iostream>
#include<functional>
using namespace std;
 
enum Color{
  Red,
  Black
};

template <class K,class V>

struct RBTNode{
  RBTNode(const  pair<K,V>& kv=pair<K,V>(),Color color=Red)
    :_kv(kv)
     ,_color(color)
     ,_left(nullptr)
     ,_right(nullptr)
     ,_parent(nullptr)
  {

  }
  pair<K,V>  _kv;
  Color _color;
  RBTNode<K,V>* _left;
  RBTNode<K,V>* _right;
  RBTNode<K,V>* _parent;
};

template <class K,class V>
struct RBTreeIterator{
  typedef RBTNode<K,V> Node;
  typedef RBTreeIterator<K,V> Self;

  RBTreeIterator(Node* pNode)
    :_pNode(pNode)
  {

  }

  //具有指针的操作
  pair<K,V>& operator*(){
    return _pNode->_kv;
  }

  pair<K,V>* operator->(){
    return &(operator*());
    //一般不直接取,通过解引用的方式来取地址
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

    if (_pNode->_pParent->_pParent == _pNode&& Red==_pNode->_color){
     
      _pNode = _pNode->_pRight;
    }
    else if (_pNode->_pLeft){
      //如果左子树存在,在左子树中找最大的节点
      _pNode = _pNode->_pLeft;
      while (_pNode->_pRight){
        _pNode = _pNode->_pRight;
      }
    }
    else{
      //如果这个左子树不存在,就从该节点开始向上找
      Node* pParent = _pNode->_pParent;
      while (_pNode == pParent->_pLeft){
        _pNode = pParent;
        pParent = _pNode->_pParent;
      }
      _pNode = pParent;
    }
  
  }
    private:
  Node* _pNode;
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

    bool Insert(const pair<K,V>& kv){
      if(_head->_parent==nullptr){
        //第一次插入的时候插入的是根结点,且颜色为黑色
        pNode _root=new Node(kv);
        _root->_color=Black;
        _root->_parent=_head;
        _head->_left=_root;
        _head->_right=_root;
        _head->_parent=_root;
        return true;
      }

      //处理存在根结点的情况
      pNode cur=_head->_parent;
      pNode parent=nullptr;
      while(cur){
        parent=cur;
        if(cur->_kv.first> kv.first){
          cur=cur->_left;
        }else if(cur->_kv.first < kv.first){
          cur=cur->_right;
        }else{
          return false;
        }
      }
      
      //进行插入
      cur=new Node(kv);


      if(parent->_kv.first>cur->_kv.first){
        parent->_left=cur;
      }else{
        parent->_right=cur;
      }

      cur->_parent=parent;

      //进行调整变色
      while(cur!=_head->_parent && cur->_parent->_color==Red){
        pNode parent=cur->_parent;
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
      //红黑树根始终是黑色的
      _head->_parent->_color=Black;
      //为了实现后续的迭代器,将head的左右指针指向最大,最小的值
      _head->_left=leftMost();
      _head->_right=rightMost();
      return true;

    }

    pNode leftMost(){
      pNode cur=_head->_parent;
      while(cur && cur->_left){
        cur=cur->_left;
      }
      return cur;
    }

    pNode rightMost(){
      pNode cur=_head->_parent;
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
        subR->_parent=nullptr;
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
       subL->_parent=nullptr;
       _head->_parent=subL; 
     }
     //4.向上链接parent,subL 
     parent->_parent=subL;
   }


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

    pNode GetRoot(){
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
};
