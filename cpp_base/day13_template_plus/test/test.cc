#include<iostream>

using namespace std;

template <class T1,class T2>
class Data{
  public:
    Data(){
      cout<<"Data<T1,T2>"<<endl;
    }

  private:
    T1 _d1;
    T2 _d2;
};


template<>
class Data<int,char>{
  public:
    Data(){
      cout<<"Data<int,char>"<<endl;
    } 
};

void Test(){
  Data<int,int> d1;
  Data<int,char> d2;
}

int main(){
  Test();
  return 0;
};
