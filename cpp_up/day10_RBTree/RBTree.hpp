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
  T _kv;
  Color _color=Red;
  RBTNode<T>* _left=nullptr;
  RBTNode<T>* _right=nullptr;
  RBTNode<T>* _parent=nullptr;
};

template <class T>

class RBTree{
  public:
    typedef RBTNode<T> Node;
    typedef RBTNode<T>* pNode;

    RBTree()
      :_head(new Node)
    {
      _head->_left=_head;
      _head->_right=_head;
    }

    bool Insert(T& kv){
      if(_head->_parent==nullptr){
        //第一次插入的时候插入的是根结点,且颜色为黑色
        pNode _root=new Node;
        _root->_kv=kv;
        _root->_color=Black;
        _root->_parent=_head;
        _head->_left=_root;
        _head->_right=_root;
        return true;
      }

      //处理存在根结点的情况
      pNode cur=_head->_parent;
      pNode parent=nullptr;
      while(cur){
    
        if(cur->_kv > kv){
          parent=cur;
          cur=cur->_left;
        }else if(cur->_kv < kv){
          parent=cur;
          cur=cur->_right;
        }else{
          return false;
        }
      }
      
      //进行插入
      cur=new Node;
      cur->_kv=kv;

      if(parent->_kv>cur->_kv){
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
            cur=parent;
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
        //红黑树根始终是黑色的
        _head->_parent->_color=Black;
        //为了实现后续的迭代器,将head的左右指针指向最大,最小的值
        _head->_left=leftMost();
        _head->_right=rightMost();
        return true;
      }
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
          cout << "违反红黑树性质二：根节点必须为黑�  �" << endl;
          return false;
        }
      // 获取任意一条路径中黑色节点的个数
      size_t blackCount = 0;
      pNode pCur = pRoot;
      while (pCur)
      {
        if (Black == pCur->_color)
          blackCount++;
        pCur = pCur->_pLeft;
      }
      // 检测是否满足红黑树的性质，k用来记录路径中黑色节点的个数
      size_t k = 0;
      return _IsValidRBTree(pRoot, k, blackCount);
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
      pNode pParent = pRoot->_pParent;
      if (pParent && Red == pParent->_color && Red == pRoot->_color)
      {
        cout << "违反性质三：没有连在一起的红色节点" << endl;
        return false;
      }
      return _IsValidRBTree(pRoot->_pLeft, k, blackCount) &&
        _IsValidRBTree(pRoot->_pRight, k, blackCount);
    }
  private:
    void _Inorder(pNode parent){
      if(parent){
        _Inorder(parent->_left);
        cout<<parent->_kv<<" ";
        _Inorder(parent->_right);
      }
    }
  private:
    pNode _head;
};
