//#include<iostream>
//#include<malloc.h>
//using namespace  std;
//
//class Test{
//  public:
//    Test(int data=0)
//      :_data(data)
//    {
//      cout<<"Test()"<<this<<endl;              
//    }
//
//    ~Test(){
//      cout<<"~Test():"<<this<<endl;
//    }
//  private:
//    int _data;
//    static int _sta;
//};
//
//int main(){
//  Test* ptr=(Test*)malloc(sizeof(Test));
//  new(ptr) Test(9);
//  delete (ptr);
//  cout<<sizeof(Test)<<endl;
//  return 0;
//}


#include<iostream>

using namespace std;

class Singleton{
  public:
    static Singleton* GetInstance(){
      return &_sigleton;
    }
  private:
    Singleton(){};
    Singleton(const Singleton& ){};
    static Singleton _sigleton;
};

Singleton Singleton::_sigleton;

int main(){

  cout<<Singleton::GetInstance()<<endl;

  cout<<Singleton::GetInstance()<<endl;
  return 0;
}
