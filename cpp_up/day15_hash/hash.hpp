#pragma once
#include<iostream>
#include<vector>
using namespace std;

//闭散列:线性探测
namespace Closed
{ 
  enum STATE{EMPTY,DELETE,EXIST};

  template <class K,class V>

    class HashNode{
      public:
        pair<K,V> _kv;
        STATE _state=EMPTY;
    };

  template<class K,class V>

    class HashTable{
      public:
        typedef HashNode<K,V> Node;
        typedef Node* pNode;

      public:
        HashTable(size_t N=5){
          _table.resize(N);
          _size=0;
        }

        //插入操作
        bool Insert(const pair<K,V>& kv){
          //为了减少哈希冲突的发生几率(空的存储空间数较少的时候插入元素会导致哈希冲突发生的机率变大)
          //需要负载因子(_size/_table.size())来确定是否需要增容
          CheckCapacity();

          size_t index=kv.first%_table.size(); //用来寻找插入位置的下标

          while(_table[index]._state==EXIST){

            //unorderedmap/set不允许键值Key重复
            if(_table[index]._kv.first==kv.first){
              return false;
            }

            ++index;
            if(index==_table.size()){
              index=0; //从index位置到哈希表尾部还未找到合适的插入位置
              //就开始从头开始重新查找
            }
          }
          _table[index]._kv=kv;
          _table[index]._state=EXIST;
          ++_size;
          return true;
        }

        pNode Find(const K& key){
          size_t index=key%_table.size();

          while(_table[index]._state!=EMPTY){

            if(_table[index]._state==EXIST && _table[index]._kv.first==key){
              return &_table[index];
            }
            ++index;
            if(index==_table.size()){
              index=0;
            }
          }
          return nullptr;
        }

        bool Erase(const K& key){
          pNode ret=Find(key);

          if(ret){
            ret->_state=DELETE;
            --_size;
            return true;
          }
          return false;
        }

        void CheckCapacity(){
          //如果调用该函数就需要进行性扩容操作
          if(_table.size()==0 ||  _size*10 / _table.size()>=7){   
            size_t newC=( _table.size()==0?10:2*_table.size() );
            HashTable<K,V> newHt(newC);

            for(size_t i=0;i<_table.size();i++){
              if(_table[i]._state==EXIST){
                newHt.Insert(_table[i]._kv);
              } 
            }
            _table.swap(newHt._table);
          }
        }

      private:
        vector<Node> _table;
        size_t _size;//用于记录哈希表中有效元素个数
    };
}


  template <class V>
    struct HashNode{
      HashNode<V>* _next;
      V _data;

      HashNode(const V& data)
        :_next(nullptr)
         ,_data(data)
      {

      }
    };

  //前置声明,声明函数
template<class K,class V,class KeyOfValue>
class HashTable;

template<class K,class V,class KeyOfValue>

struct  Hash_Iterator{
  typedef HashNode<V> Node;
  typedef  Node* pNode;
  typedef Hash_Iterator<K,V,KeyOfValue> Self;
  typedef  HashTable<K,V,KeyOfValue> HashT;


  pNode _node;
  HashT* _ht; 

  Hash_Iterator(pNode node,HashT* ht)
        :_node(node)
         ,_ht(ht)
      {

      }

      V& operator*(){
        return _node->_data;
      }

      V* operator->(){
        return &(operator*());
      }

      bool operator!=(const Self& it){
        return _node != it._node;
      }

      Self& operator++(){
        if(_node->_next){
          _node=_node->_next;
        }else{
          KeyOfValue Kov;
          size_t index=Kov(_node->_data)%_ht->_table.size();
          ++index;
          //向后搜索,找到第一个非空链表的头结点,既为下一个元素的位置
          for(;index<_ht->_table.size();++index){
            if(_ht->_table[index]){
              _node= _ht->_table[index];
              break;
            }
          }

          //如果走到表尾,说明无有效元素存在
          if(index==_ht->_table.size()){
            //未找到非空链表
            _node=nullptr;
          }
        }
        return *this;
      }  
 };

 template <class K,class V,class KeyOfValue>
 class HashTable{
   public:
        typedef HashNode<V> Node;
        typedef Node* pNode;
       //泛型友元声明
        //template <class K,class V,class KeyOfValue>
        //使用上述模板方式会和HashTable模板命名冲突
        template<class Key,class  Val,class  SKeyOfValue>
        friend struct Hash_Iterator;

        typedef Hash_Iterator<K,V,KeyOfValue> Iterator;

   
   public:
        Iterator begin(){
          for(size_t i=0;i<_table.size();++i){
            if(_table[i]){
              return Iterator(_table[i],this);
            }
           
          }
          //空表
          return Iterator(nullptr,this);
        }
     
        Iterator end(){
          return Iterator(nullptr,this);
        }
      public:

        //插入
        bool Insert(const V& data){
          CheckCapacity();
          KeyOfValue Kov;
          size_t index=Kov(data)%_table.size();

   
          pNode cur=_table[index];
 

          while(cur){
            if(Kov(cur->_data)== Kov(data)){
              return false;
            }
            cur=cur->_next;
          }

          //找到单链表的最后一个结点还没有找到对应的值
          //就对该链表进行头插操作,申请新的结点用来存储该值
          
          cur=new Node(data);
          cur->_next=_table[index];
          _table[index]=cur;
          ++_size;
          return true;
        }

        void CheckCapacity(){
          if(_size==_table.size()){
            size_t newC=_table.size()==0?10:2*_table.size();

            KeyOfValue Kov;
            vector<pNode> newHt;
            //新建一个表,将原来表中的元素赋值到新的表中
            newHt.resize(newC);
            for(size_t i=0;i<_table.size();i++){
              pNode cur=_table[i];

              while(cur){
                pNode next=cur->_next;
                //位置要重新计算
                size_t index=( Kov(cur->_data) )%newHt.size();
                //头插
                cur->_next=newHt[index];
                newHt[index]=cur;
                cur=next;
              }
              _table[i]=nullptr;
            }
            //新表和原来的表进行交换
            _table.swap(newHt);
          }
        }
      private:
       vector<pNode> _table;
       size_t _size=0;
    };



