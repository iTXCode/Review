#include<iostream>

using namespace  std;

template <class T>
struct AVL_Node{
  AVL_Node(const T& val=T())
    :_data(val)
     ,_left(nullptr)
     ,_right(nullptr)
     ,_parent(nullptr)
     ,_bf(0)
  {

  }

  T _data;
  AVL_Node<T>* _left;
  AVL_Node<T>* _right;
  AVL_Node<T>* _parent;
  //平衡因子
  int _bf;
};


template <class T>

class Avl_Tree{
  public:
   typedef   AVL_Node<T>  Node;
   typedef Node* pNode;

   //插入
   bool Insert(const T& val){
     if(_root==nullptr){
       _root=new Node(val);
       return true;
     }

     pNode cur=_root;
     pNode parent=nullptr;
    
     //先要找到合适的插入点
     while(cur){
       parent=cur;
       if(cur->_data>val){
         cur=cur->_left;
       }else if(cur->_data<val){
         cur=cur->_right;
       }else{
         return false;
       }
     }

     //进行插入
     pNode New_Node=new Node(val);

     if(parent->_data>val){
       parent->_left=New_Node;
     }else{
       parent->_right=New_Node;
     }

     New_Node->_parent=parent;
     
     cur=New_Node;//调整平衡因子的时候需要往回指
     //调整平衡因子
     while(parent){
       //更新当前结点的平衡因子
       if(parent->_left==cur){
         --parent->_bf;
       }
       else{
         ++parent->_bf;
       }
        //检查平衡因子，bf==0.高度 没有发生变化,停止更新
       if(parent->_bf==0){
         break;
       }
       //高度加1,需要去更新此路径上的祖先结点的平衡因子
       if(parent->_bf==1 || parent->_bf==-1){
         cur=parent; //向上调整的cur所指的结点需要不断更新
         parent=parent->_parent;
       }else if(parent->_bf==2 || parent->_bf==-2){
         //不平衡需要进行调整
         //左旋
         if(parent->_bf==2 && parent->_right->_bf==1){
           RotateL (parent);
         }else if(parent->_bf==-2 && parent->_left->_bf==-1){
           //右旋
           RotateR(parent);
           //调整完毕,已经平衡.结束调整
       
         }else if(parent->_bf==-2 && cur->_bf==1){
           //左右双旋
           //左旋:RotateL(subL);
           //右旋:RotateR(parent)
           pNode subL=parent->_left;
           pNode subLR=subL->_right;
           int bf=subLR->_bf;
           RotateL(cur);
           RotateR(parent);

           if(bf==1){
             parent->_bf=0;
             subL->_bf=-1;
           }else if(bf==-1){
             parent->_bf=1;
             subL->_bf=0;
           }
           
         }else if(parent->_bf==2 && cur->_bf==-1){
           //右左双旋
           pNode subR=parent->_right;
           pNode subRL=subR->_left; 
           int bf=subRL->_bf; 
           RotateR(cur);
           RotateL(parent);
           if(bf==1){
             subR->_bf=0;
             parent->_bf=-1;
           }else if(bf==-1){
             parent->_bf=0;
             subR->_bf=1;
           }

         
         }
         //旋转结束,已经平衡,结束调整
        break;
       }
     }
     return true;
   }


   void RotateL(pNode parent){
     //左旋的过程
     pNode subR=parent->_right;
     pNode subRL=subR->_left;

     //旋转
     subR->_left=parent;
     parent->_right=subRL;

     //更新三叉链
     //1.链接subR与parent
     if(subRL){
       subRL->_parent=parent;
     }
     //链接subR 与 parent的parent
     if(parent!=_root){
       //若parent不是根
       pNode gParent=parent->_parent;
      //判断parent之前是parent->_parent 的那一边结点
      //把subR链接到对应的那边
       if(gParent->_left==parent)
         gParent->_left=subR;
       else 
         gParent->_right=subR;
       //更新subR的parent
       subR->_parent=gParent;
     }else{
       //parent为根,subR就变成新的根结点
       subR->_parent=nullptr;
       _root=subR;
     }

     //链接subR和parent
     parent->_parent=subR;
     //更新平衡因子
     subR->_bf=parent->_bf=0;
   }

   //更新平衡因子之后
   //bf==0:停止向上更新,已平衡
   //bf==1/-1:继续向上更新
   //bf==2,孩子结点bf==1\-1:左旋，停止更新,已平衡
  

   //右旋
   //parent->_bf==-2,孩子结点->_bf==-1;
   //以parent为轴,右旋,subL->_right=parent 
   //2.subLR存在:subLR->_parent=parent 
   //3.链接subL与parent->_parent
   //a.parent != _root 
   //parent->_parent->_left=parent 
   //parent->_parent->_left=subL 
   //否则:parent->_parent->_right=subL
   //subL->_parent=parent->_parent 
   //b.parent==root 
   //subL->_parent=nullptr; 
   // root=subL 
   // 4.链接subL与parent:parent->_parent=subL 
   //5.更新平衡因子：subL 与 parent:parent->_parent=0; 
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
     if(parent!=_root){
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
       _root=subL; 
     }
     //4.向上链接parent,subL 
     parent->_parent=subL;

     //更新平衡因子
     subL->_bf=parent->_bf=0;
   }

   
   //验证AVL树
   
   void Inorder(){
     _inorder(_root);
   }
   
   bool Isbalance(){
     return _isBalance(_root);
   }


   //求子树的高度
   int Height(pNode cur){
     if(cur==nullptr)
       return 0;
     int left=Height(cur->_left);
     int right=Height(cur->_right);
     return left>right?left+1:right+1;
   }
  private:
   void _inorder(pNode root){
     if(root){
       _inorder(root->_left);
       std::cout<<root->_data<<"-->"<<root->_bf<<std::endl;
       _inorder(root->_right);
     }
   }

   //判断AVL树是否为平衡树
   bool _isBalance(pNode root){
     if(root==nullptr)
       return true;

     int left=Height(root->_left);
     int right=Height(root->_right);

     if(root->_bf != (right-left)){
       return false;
     }
     return abs(root->_bf)<2 && _isBalance(root->_left) && _isBalance(root->_right);

   }
  private:
   pNode _root=nullptr;
};
