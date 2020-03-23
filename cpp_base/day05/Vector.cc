#include<iostream>
#include<assert.h>

//使用类模板实现动态顺序表
using namespace std;
template<class T>

class Vector{
  public:
    Vector(size_t capacity=5)
      :_data(new T[capacity])
       ,_size(0)
       ,_capacity(0)
    {

    }

    ~Vector(){
      if(_data){
        delete[] _data;
        _data=nullptr;
        _size=0;
        _capacity=0;
      }
    }

    void pushBack(const T value){
      //判断插入的位置是否合法
      
      if(_size>=0 || _size< _capacity){
        //进入该判断的位置是合法的
        _data[_size]=value;
        ++_size;
      }else{
        //走到这里就需要扩容了
        _capacity=2*_capacity;
        _data[_size]=value;
        ++_size; 
      }
    }

    size_t Size(){
      return _size; 
    }

    void Pop(){
      if(_size==0){
        cout<<"顺序表为空"<<endl;
      }else{
        --_size; 
      }
    }
    
    T& operator[](size_t i){
      assert(i<_size);
      return _data[i];
    }
  private:
    T* _data;
    size_t  _size;
    size_t  _capacity;
};

int main(){
  Vector<int> v1;
  v1.pushBack(1);
  v1.pushBack(2);
  v1.pushBack(3);
  v1.pushBack(4);
  v1.pushBack(5);
  v1.pushBack(6);
    
  v1.Pop();

  cout<<v1.Size()<<endl;
  for(size_t i=0;i<v1.Size();++i){
    cout<<v1[i]<<endl;
  }

  Vector<char> v;
  v.pushBack('i');
  cout<<v[0]<<endl;
  return 0;
}
