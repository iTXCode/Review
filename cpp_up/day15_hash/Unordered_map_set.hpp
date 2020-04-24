#pragma once
#include"hash.hpp"

template <class K,class V>

class UnorderedMap{
  public:
    typedef pair<K,V> ValueType;

    struct MapKeyOfValue{
      const K& operator()(const pair<K,V>& data){
        return data.first; 
      }
    };
  public:
    typedef typename HashTable<K,ValueType,MapKeyOfValue>::Iterator   Iterator;

    Iterator Begin(){
      return _ht.begin();
    }

    Iterator End(){
      return _ht.end();
    }
  public:


    bool  Insert(const pair<K,V>&  data){
        return _ht.Insert(data);
    }
  private:
    HashTable<K,ValueType,MapKeyOfValue> _ht;
};


template <class K>

class UnorderedSet{
 public:   
  struct SetKeyOfValue{
    const K& operator()(const K& data){
      return data;
    }
  };
  typedef typename HashTable<K,K,SetKeyOfValue>::Iterator Iterator;

  Iterator Begin(){
    return  _ht.begin(); 
  }

  Iterator End(){
    return _ht.end();
  }
  public:
   bool Insert(const K& data){
     return   _ht.Insert(data);
  }
  private:
    HashTable<K,K,SetKeyOfValue> _ht;
};
