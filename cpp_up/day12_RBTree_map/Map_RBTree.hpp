#include"RBTree.hpp"
#include<string>

namespace bite{
  //封装红黑树
  template <class K,class V>
    class Map{
      typedef pair<K,V> ValueType;

      //该内部类的作用是:将value中的key提取出来
      struct KeyOfValue{
        const K&operator()(const ValueType& data){
          return data.first;
        }
      };

 
      public:
     typedef typename   RBTree<ValueType,KeyOfValue>::Iterator Iterator;

      public:
      Map()
        :_t()
      {

      }
      Iterator begin(){
        return _t.Begin();
      }

      Iterator end(){
        return _t.End();
      }

      size_t size()const{
        return _t.Size();
      }

      bool empty()const{
        return _t.Empty();
      }

      Iterator find(const K& key){
        return _t.Find(make_pair(key,V()));
      }

      //下标运算符
      V& operator[](const K& key){
        return (*(( _t.Insert(ValueType(key,V()) )).first)).second;
      }

      const V& operator[](const K& key)const{
        return (*(( _t.Insert(ValueType(key,V()) )).first)).second;
      }

      pair<Iterator,bool> Insert(const ValueType& data){
        cout<<"Map:"<<data.first<<" "<<data.second<<endl;
        return _t.Insert(data);
      }


      Iterator Insert(Iterator position,const V& x){
        return _t.Insert(position,x);
      }

      template<class InputIterator>

        void Insert(InputIterator first,InputIterator second){
          _t.Insert(first,second);
        }
      private:
        RBTree<ValueType,KeyOfValue> _t;
    };
}
