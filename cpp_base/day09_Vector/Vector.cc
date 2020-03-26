#include<iostream>
#include<string.h>

using namespace std;

template <class T>


class Vector{
  public:
typedef T* iterator;
typedef const T* const_iterator;
    Vector()
      :_start(nullptr)
       ,_finish(nullptr)
       ,_end_of_storage(nullptr)
  {

  }

    size_t Size()const {
      return _finish-_start;
    }

    size_t  Capacity() const {
      return _end_of_storage-_start;
    }

    //实现拷贝构造函数
    Vector(const Vector<T>& v){

        T* _start=new T[v.Capacity()];
        
        for(int i=0;i<v.Size();++i){
          _start[i]=v._start[i];

      }   

      _finish=_start+v.Size();
      _end_of_storage=_start+v.Capacity();
    }
   //实现赋值运算符重载
   
    T& operator=(Vector<T>& v){
      Swap(v);
      return *this; 
    }

    void Swap(Vector<T>& v){
      swap(_start,v._start);
      swap(_finish,v._finish);
      swap(_end_of_storage,v._end_of_storage);
    }

    //实现析构函数
    
    ~Vector(){
      if(_start){
        delete[] _start;
        _start=_finish=_end_of_storage=nullptr;
      }
    }

    //【增】
    
    void PushBack(const T& val){
      //1.检查容器空间是否已经满载
      if(_finish==_end_of_storage){
        //如果两者相等话,则说明容器已经满载
        size_t newc=((_start==nullptr)?1:2*Capacity());
        Reserve(newc);
      }
      _finish=val;
      ++_finish;
    }

    void Reserve(size_t n){
      //检查是否需要扩容
      if(n>_end_of_storage){
        T* tmp=new T[n];
        size_t sz=Size();//获取原来对象的有效长度
        //进行值拷贝
        for(int i=0;i<n;++i){
          tmp[i]=_start[i];
        }

        //将原来的空间释放
        delete[] _start;
        //将_start指向新的空间
        _start=tmp;
   

        _finish=_start+sz;
        _end_of_storage=_start+n;
      }

    }

    T& operator[](size_t pos){
      //检查pos的合法性
      assert(pos<Size());
      return _start[pos];
    }


    //实现迭代器功能
    iterator begin(){
      return _start;
    }

    iterator* end(){
      return _finish;
    }

    const_iterator* begin()const {
      return _start;
    }

    const_iterator* end()const{
      return _finish;
    }

    iterator* rbegin(){
      return _finish;
    }

    iterator* rend(){
      return _start;
    }

    const_iterator* rbegin()const{
      return _finish;
    }

    const_iterator* rend()const{
      return _start;
    }

    //【实现插入函数】
    
  private:
    T *_start;
    T *_finish;
    T *_end_of_storage;
};

int main(){
  Vector<int> v;
  Vector<int> v1=v;
  return 0;
}
