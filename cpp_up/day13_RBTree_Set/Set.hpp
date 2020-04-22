#pragma once
#include"RBTree.hpp"

namespace  bite{ 
  template<class K>

    class Set{

      typedef K ValueType;
      public:
      typedef typename RBTree<K,K,ValueType>::Iterator Iterator;

      pair<Iterator,bool> Insert(const ValueType& key){
        return _t.Insert(key);
      }

      Iterator begin(){
        return _t.Begin();
      }

      Iterator end(){
        return _t.End();
      }

      bool empty(){
        return _t.Empty();
      }
 
      K& operator[](const K& key){
        K ret=_t.Insert(key);
        return ret;
      }
      private:
      RBTree<K,K,ValueType> _t;
    };
}
