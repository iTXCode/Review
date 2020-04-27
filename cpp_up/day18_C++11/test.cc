#include<iostream>
#include<vector>
#include<map>
using namespace std;

//template <class T>
//
//class Vector{
//  public:
//    //满足单参构造,不能满足有参数列表的构造
//    Vector(size_t n)
//      :_start(new T[n])
//    {
//
//    }
//
//    //满足多参构造
//    Vector(initializer_list<T> ls)
//      :_start(new T[ls.size()])
//    {
//      size_t sz=0;
//
//      for(auto &e: ls){
//        _start[sz++]=e;
//      }
//    }
//  private:
//    T* _start;
//};
//
//int  test(){
//  auto i=10;
//  std::map<std::string,std::string> map;
//  std::map<std::string,std::string>::iterator it=map.begin();
//  decltype(1+2) a; //根据表达式的类型推导出定义变量的类型
//  auto it2=map.begin();
//  return 1;
//}
//
//
////委派构造函数:减少构造的代码量
//class B{
//  public:
//    B()
//      :_a(1)
//       ,_b(2)
//       ,_c(3)
//       ,_d(4)
//  {}
//
//    B(int a,int d)
//      :_a(a)
//       ,_b(2)
//       ,_c(3)
//       ,_d(d)
//  {}
//
//    B(int a)
//    :B()
//    {
//      _a=a;
//    }
//
//  private:
//    int _a;
//    int _b;
//    int _c;
//    int _d;
//};
//int main(){
//  //初始化列表
//  int i{2};
//  vector<int> v={1,2,3,4};
//  map<int,int> m{{1,1},{2,2},{3,3}};
//  Vector<int> v1={1,2,3,4,5};
//  //单对象创建,编译器默认支持初始化列表
//  Vector<int> v3(1);//单参数构造函数隐式类型转换
//  //多对象创建,实现接收initializer_list构造函数
//  
//  Vector<string> v2={"we","are","soldier"}; 
//  
//  const int &a=test();
//
//  const int & ra=1;
//  int &&rra=2;
//  return 0;
//
//}
//


template <class T>

class String{
  public:
    String(const T& str)
      :_str(str)
    {

    }
  private:
    T* _str;
};

#include<algorithm>

struct Greater{
  bool operator()(const int a,const int b){
    return a>b;
  }
};
void TestLambda(){
  vector<int> v={1,2,3,4,-1,0,5,-2,-7};
  for(const auto& e:v){
    cout<<e<<" ";
  }
  cout<<endl;
  sort(v.begin(),v.end());

  for(const auto& e:v){
    cout<<e<<" ";
  }
  cout<<endl;

  sort(v.begin(),v.end(),Greater());

  for(const auto& e:v){
    cout<<e<<" ";
  }
  cout<<endl;

  sort(v.begin(),v.end(),[](const int a,const int b){
      return a<b;
      });
   for(const auto& e:v){
    cout<<e<<" ";
  }
  cout<<endl;

  auto more=[](const int a,const int b){
    return a>b;
  };  //将lambda的结果赋值给变量more

  sort(v.begin(),v.end(),more);
  for(const auto& e:v){
    cout<<e<<" ";
  }
  cout<<endl;


}



void Lmabda(){
  int a=10;
  //[a]()->bool{a=20;return true;}; 
  //捕捉到的内容是以值的形式传递过来的,变量是const属性的
  [a]()mutable->bool{a=20;return true;}; 

//lambda表达式
//[](){}
//捕捉列表[]:捕捉父作用域的变量
//参数列表():类似于普通函数的参数列表
//返回值->类型:
//函数体{}:
//mutable:去除捕捉列表中以值的形式传递过来的变量的const属性
  [&a]()->bool{a=20;return true;};
}

auto fun=[](int a,int b)->bool{return a==b;};

int main(){
  TestLambda();
  return 0;
}
