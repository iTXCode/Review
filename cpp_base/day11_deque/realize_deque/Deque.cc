#include<iostream>

using namespace std; 

//迭代器的实现
//为了实现迭代器的模板化(普通迭代器和const迭代器的代码复用

inline size_t _deque_buf_size(size_t n,size_t sz){
  return n!=0?n:(sz<512?size_t(512/sz):size_t(1));
}

//如果n不为0,传回n,表示buffer_size 由使用者自定
//如果n为0,表示buffer size使用预设值,那么
//如果sz(元素大小,sizeof(value_type))小于512，传回512/sz/如果sz不小于512,传回1；
template <class T,class Ref, class Ptr,size_t BufSiz>


class DequeIterator{
  public:
    typedef DequeIterator<T,T&,T*,BufSiz> iterator;
    typedef DequeIterator<T,const T&,const T*,BufSiz> const_iterator;

    typedef T** map_pointer;
    static size_t buffer_size(){
      return _deque_buf_size(BufSiz,sizeof(T));
    }

    void set_node(map_pointer new_node){
      _node=new_node;
      _frist=*new_node;
      _last=_frist+ (buffer_size());

      //TODO:此处的_last指针的位置需要重新设定
    }

    Ref operator*()const{
      return *_cur;
    }

    Ptr operator->() const{
      return &(operator*());
    }
  private:
    T* _frist;//指向缓冲区的第一个位置
    T* _last;//指向缓冲区的最后一个位置
    T* _cur; //此迭代器所指向的缓冲区的现行元素,用于"遍历"缓冲区
    T** _node;//指向中控的指针
};


template <class T>

class Deque{
typedef DequeIterator<T,T&,T*>* iterator;
typedef const DequeIterator<T,T&,T*>* const_iterator;
  public:
    iterator begin(){
      return _start;
    }

    iterator end(){
      return _finish;
    }

    size_t size(){
      return _finish-_start;
    }
  private:
    iterator _start;
    iterator _finish;
    T** map;//指向
    size_t map_size;//用于记录map的长度
};
