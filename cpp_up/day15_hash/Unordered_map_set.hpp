#pragma once
#include"hash.hpp"
#include<string>

template <class K>
struct HFun{
  const K&operator()(const K&a){
    return a;
  }
};

template<>
struct HFun<string>{
  size_t operator()(const string& str){
    size_t hash=0;
    for(const auto& e:str){
      hash=hash*131 +e;
    }
    return hash;
  }
};
template <class K,class V,class HashFun=HFun<K>>

class UnorderedMap{
  public:
    typedef pair<K,V> ValueType;

    struct MapKeyOfValue{
      const K& operator()(const pair<K,V>& data){
        return data.first; 
      }
    };
  public:
    typedef typename HashTable<K,ValueType,MapKeyOfValue,HashFun>::Iterator   Iterator;

    V& operator[](const K& key){
      pair<Iterator,bool> ret=_ht.Insert(key);
      return ret.first->second;
    }

    Iterator Begin(){
      return _ht.begin();
    }

    Iterator End(){
      return _ht.end();
    }
  public:


    pair<Iterator,bool>  Insert(const pair<K,V>&  data){
        return _ht.Insert(data);
    }
  private:
    HashTable<K,ValueType,MapKeyOfValue,HashFun> _ht;
};


template <class K,class HashFun=HFun<K>>

class UnorderedSet{
 public:   
  struct SetKeyOfValue{
    const K& operator()(const K& data){
      return data;
    }
  };
  typedef typename HashTable<K,K,SetKeyOfValue,HashFun>::Iterator Iterator;

  Iterator Begin(){
    return  _ht.begin(); 
  }

  Iterator End(){
    return _ht.end();
  }
  public:
   pair<Iterator,bool>  Insert(const K& data){
     return   _ht.Insert(data);
  }
  private:
    HashTable<K,K,SetKeyOfValue,HashFun> _ht;
};
