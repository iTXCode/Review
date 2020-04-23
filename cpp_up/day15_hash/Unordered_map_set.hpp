#include"hash.hpp"

template <class K,class V>

class UnorderedMap{
  public:

    struct MapKeyOfValue{
      const K& operator()(const pair<K,V>& data){
        return data.first; 
      }
    };
  public:
    bool  Insert(const pair<K,V>&  data){
        return _ht.Insert(data);
    }
  private:
    Opend::HashTable<K,pair<K,V>,MapKeyOfValue> _ht;
};


template <class K>

class UnorderedSet{
 public:   
  struct SetKeyOfValue{
    const K& operator()(const K& data){
      return data;
    }
  };
  public:
   bool Insert(const K& data){
     return   _ht.Insert(data);
  }
  private:
    Opend::HashTable<K,K,SetKeyOfValue> _ht;
};
