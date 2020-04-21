#include"RBTree.hpp"
namespace  bite{ 
  template <class K,class V>
    class Set{
      typedef pair<K,V> SetType;

      //该内部类用于将Value中的key提取出来
      struct KeyOfValue{
        const K&operator()(const SetType& kv){
          return kv.first;
        }
      };


      public:
      typedef  typename RBTree<K,pair<K,V>,SetType>::Iterator Iterator;

      Set()
        :_set()
      {

      }

      Iterator begin(){
        return _set.Begin();
      }

      Iterator end(){
        return _set.End();
      }

      size_t size()const{
        return _set.Size();
      }

      bool empty()const{
        return _set.Empty();
      }

      Iterator find(const K& key){
        return _set.Find(make_pair(key,V()));
      }

      //下标运算符
      V& operator[](const K& key){
        pair<Iterator,bool> ret=Insert(make_pair(key,V()));
        return ret.first->second;
      }

      pair<Iterator,bool> Insert(const SetType& data){
        return _set.Insert(data);
      }
      private:
      RBTree<K,pair<K,V>,SetType> _set;
    }; 
}
