#include<iostream>
#include<string.h>
#include<assert.h>
using namespace std;

template <class T>


class Vector{
  public:
typedef T* iterator;
typedef const T* const_iterator;

Vector(const int& val)
:_start(nullptr)
  ,_finish(nullptr)
  ,_end_of_storage(nullptr)
{
  _start=new int[1];
  _finish=_start+1;
  _end_of_storage=_start+1;
  *_start=val;
}

Vector(size_t n=0,const T&v=T())
    :_start(nullptr)
     ,_finish(nullptr)
     ,_end_of_storage(nullptr)
  {
    _start=new T[n];
    _finish=_start+n;
    _end_of_storage=_start+n;

    for(size_t i=0;i<n;i++){
      _start[i]=v;
    }
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
        size_t newc=((_start==_end_of_storage)?1:2*Capacity());
        Reserve(newc);
      }
      *_finish=val;
      ++_finish;
    }

    void Reserve(size_t n){
      //检查是否需要扩容
      if(n>Capacity()){
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

    iterator end(){
      return _finish;
    }

    const_iterator begin()const {
      return _start;
    }

    const_iterator end()const{
      return _finish;
    }

    iterator rbegin(){
      return _finish;
    }

    iterator rend(){
      return _start;
    }

    const_iterator rbegin()const{
      return _finish;
    }

    const_iterator rend()const{
      return _start;
    }

    //【实现插入函数】
  
    void Insert(iterator pos,const T& val){
      //1.检查插入位置的合法性
      assert(pos>=_start && pos<= _finish);
      size_t len=pos-_start;
      //计算出pos位置与首地址的距离之差,便于插入元素
      
      //2.判断是否需要扩容
      if(_finish==_end_of_storage){
        size_t newc=(_start==nullptr?1:2*Capacity());
        Reserve(newc);
      }

      //更新迭代器,由于增容现在所使用的地址空间是重新
      //申请的,所以需要重新确定pos的位置
      pos=_start+len;
      iterator end=_finish;
      //将pos位置后的元素依次往后移动一位
      while(end>pos){
        *end=*(end-1);
        end--;
      }

      //在pos位置插入指定元素
     *pos=val;
     ++_finish;
    }

    /*判断是否需要增容
     * 更新迭代器,防止迭代器失效
     * 将尾端位置开始到插入位置的元素都往后移动一位
     * 进行插入操作
     * 更新_finish位置
     * */

    //[删]
    iterator Erase(iterator pos){
      //1.判断指定位置的合法性
      assert(pos>=_start&&pos<=_finish);

      //将pos位置开始到有效位置之间的元素都向前移动一位
       iterator it=pos+1;
       while(it<_finish){
        *(it-1)=*it;
        it++;
       }
       //更新_finish位置
     --_finish;
     return pos;
    }

    void Pop_Back(){
      --_finish;
    }
    //返回重置空间的函数
    void Resize(size_t n,const T& val=T()){
      //1.检查n的合法性
      if(n<=Size()){
        _finish=_start+n;
      }else{
        if(n>Capacity()){
          Reserve(n);
        }
        while(_finish!=_start +n){
          *_finish=val;
          ++_finish; 
        }
      }
    }

    iterator Find(iterator pos1,iterator pos2,T& val){
      assert(pos1>=_start && pos1<=_finish);
      assert(pos2>= _start && pos2<=_finish);

      while(pos1!=pos2){
        if(*pos1==val){
          return pos1;
        }
        ++pos1;
      }
      return _finish;
    }
  private:
    T *_start;
    T *_finish;
    T *_end_of_storage;
};

template <class T>
void PrintIterator(const Vector<T>& v){
  auto it=v.begin();
  while(it!=v.end()){
    cout<<*it<<" ";
    ++it;
  }
  cout<<endl;
}

 
template <class T>
void TestInsert(Vector<T>& v){
  v.Insert(v.begin(),3);
  PrintIterator(v);
}

void TestPushPop()
{
  Vector<int> v;
  Vector<int> v1(3);
  Vector<int> v2(4,2);
  v.PushBack(1);
  v.PushBack(2);
  v.PushBack(5);
  v1.PushBack(9);
  TestInsert(v);
  PrintIterator(v);
  PrintIterator(v1);
  PrintIterator(v2);
}

void TestReserve(){
  Vector<char> v(2,'i');
  cout<<"Resize before:"<<endl;
  cout<<"Size():"<<v.Size()<<endl;
  cout<<"Capacity():"<<v.Capacity()<<endl;
  v.Reserve(20);
  cout<<"Resize after:"<<endl;
  cout<<"Size():"<<v.Size()<<endl;
  cout<<"Capacity():"<<v.Capacity()<<endl;
}

void TestString(){
  Vector<string> v(2,"hello");
  cout<<v[0]<<endl;
}

void TestResize(){
  Vector<char> v(10,'$');
  v.Resize(20,'@');
  PrintIterator(v);
}

int main(){
  TestPushPop();
  TestString();
  TestReserve();
  TestResize();
  return 0;
}
