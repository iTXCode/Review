#include<iostream>
#include<vector>
#include<map>
using namespace std;

template <class T>

class Vector{
  public:
    //满足单参构造,不能满足有参数列表的构造
    Vector(size_t n)
      :_start(new T[n])
    {

    }

    //满足多参构造
    Vector(initializer_list<T> ls)
      :_start(new T[ls.size()])
    {
      size_t sz=0;

      for(auto &e: ls){
        _start[sz++]=e;
      }
    }
  private:
    T* _start;
};

int  test(){
  auto i=10;
  std::map<std::string,std::string> map;
  std::map<std::string,std::string>::iterator it=map.begin();
  decltype(1+2) a; //根据表达式的类型推导出定义变量的类型
  auto it2=map.begin();
  return 1;
}


//委派构造函数:减少构造的代码量
class B{
  public:
    B()
      :_a(1)
       ,_b(2)
       ,_c(3)
       ,_d(4)
  {}

    B(int a,int d)
      :_a(a)
       ,_b(2)
       ,_c(3)
       ,_d(d)
  {}

    B(int a)
    :B()
    {
      _a=a;
    }

  private:
    int _a;
    int _b;
    int _c;
    int _d;
};
int main(){
  //初始化列表
  int i{2};
  vector<int> v={1,2,3,4};
  map<int,int> m{{1,1},{2,2},{3,3}};
  Vector<int> v1={1,2,3,4,5};
  //单对象创建,编译器默认支持初始化列表
  Vector<int> v3(1);//单参数构造函数隐式类型转换
  //多对象创建,实现接收initializer_list构造函数
  
  Vector<string> v2={"we","are","soldier"}; 
  
  const int &a=test();

  const int & ra=1;
  int &&rra=2;
  return 0;
}
