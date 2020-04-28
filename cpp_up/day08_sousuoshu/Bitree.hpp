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



    //删除
    bool Erase(const T& val){
      if(_root==nullptr){
        return false;
      }

      pNode cur=_root;
      pNode parent=nullptr;
      while(cur){
  
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
        if(cur!=_root){
          //让父亲结点对应的位置为空
          if(parent->_left==cur){
            parent->_left=nullptr;
          }else{
            parent->_right=nullptr;
          }
        }else{
          //删除_root.树为空
          _root=nullptr;
        }
        delete cur;
        cur=nullptr;
      }else if(cur->_left==nullptr){
        //父亲结点的一个孩子结点(左孩子)为空
          if(cur!=_root){
            //首先确定当前结点在其父亲结点的左边还是右边
            //对应位置设为cur->right 
            if(parent->_left==cur){
              parent->_left=cur->_right;
            }else{
              parent->_right=cur->_right;
            }
          }else{
            //更新根
            _root=_root->_right;
          }
          delete cur;
          cur=nullptr;
        }else if(cur->_right==nullptr){
          if(cur!=_root){
            if(parent->_left==cur){
              //当前结点只有左孩子没有右孩子的情况
              parent->_left=cur->_left;
            }else{
              //当前结点只有左孩子没有右孩子的情况
              parent->_right=cur->_left;
            }
          }else{
            _root=_root->_left;
          }
          delete cur;
          cur=nullptr;
        }else{
       //   //左右孩子都存在
       //   //1.寻找替换节点
       //   pNode pNext=cur->_left;//从其左子树中找一个最大的结点来替换
       //   parent=cur;
       //   //找到左子树的最右结点
       //   //没有右子树则其左孩子即为左子树中最大结点
       //   while(pNext->_right){
       //     parent=pNext;
       //     pNext=pNext->_right;
       //   }

       //   //2.置换
       //   cur->_value=pNext->_value;
       //   //问题
       //   if(parent->_right==pNext)
       //     parent->_right=nullptr;

       //   if(pNext->_left){
       //     parent->_right=pNext->_left;
       //   }
       //   //若pNext所指向的子节点是叶子结点
       //   if(pNext->_left== nullptr&& pNext->_right==nullptr){
       //      parent->_left=nullptr;
       //   }
//     //     if(pNext->_left){
//     //       parent->_left=pNext->_left;
//     //     }else if(pNext->_right){
//     //       parent->_left=pNext->_right;
//     //     }else{
//     //       cur->_left=nullptr;
//     //     }

       //   
       //   delete pNext;
       //   pNext=nullptr;
        


        pNode pNext=cur->_left;
        parent=cur;

        if(pNext->_left==nullptr && pNext->_right==nullptr){
          cur->_value=pNext->_value;
          cur->_left=nullptr;
        }
        if(pNext->_left&&pNext->_right==nullptr){
          parent->_left=pNext->_left;
        }else{
          while(pNext->_right){
            parent=pNext;
            pNext=pNext->_right; 
          }

          cur->_value=pNext->_value;
          if(pNext->_left){
            parent->_right=pNext->_left;
          }
          if(parent->_right==pNext){
            parent->_right=nullptr; 
          }
        }
        
        delete pNext;
        pNext==nullptr;
        }
      return true; 
    }
 
    void PreOrderTravel(){
      _preorderTravel(_root);
      std::cout<<std::endl;
    }


    void PostOrderTravel(){
      _postorderTravel(_root);
      std::cout<<std::endl;
    }

    ~BSTree(){
      std::cout<<"~BSTree()"<<std::endl;
      Distory(_root);
    }
  private:
    //将析构函数内部的删除函数封装成私有的
    void Distory(pNode root){
      if(root){
        Distory(root->_left);
        Distory(root->_right);
        delete root;
        root=nullptr;
      }
    }

    
    void _inorderTravel(pNode& root){
      if(root!=nullptr){
        _inorderTravel(root->_left);
        std::cout<<root->_value<<" ";
        _inorderTravel(root->_right);
      } 
    }

    void _preorderTravel(pNode& root){
      if(root!=NULL){
        std::cout<<root->_value<<" ";
        _preorderTravel(root->_left);
        _preorderTravel(root->_right);
      }
    }

     void _postorderTravel(pNode& root){
      if(root!=NULL){
        std::cout<<root->_value<<" ";
        _postorderTravel(root->_left);
        _postorderTravel(root->_right);
      }
    }
 
  private:
    pNode  _root;
};

