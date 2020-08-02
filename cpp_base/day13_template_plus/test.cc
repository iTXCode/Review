//#include<iostream>
//
//using namespace  std;
//
//template<class T>
//
//T Add(T& a,T& b){
//  cout<<"Add(&a,&b)"<<endl;
//  return a+b;
//}
//
//
//
////template<class T>
////
////T Add(T a,T b){
////
////  cout<<"Add(a,b)"<<endl;
////  return a+b;
////}
////
//int main(){
//  int a=10.0;
//  int b=20;
//  double c=10.0;
//
//  cout<<Add<int>(a,c)<<endl;
//  //cout<<Add<int>(a,c)<<endl;
//  return 0;
//}



#include<iostream>

using namespace std;

template<class T1,class T2>

class Data{
  public:
    Data(){
      cout<<"Data(T1,T2)"<<endl;
    }
};

template <class T>

class Data<T,int>{
public:
  Data(){
    cout<<"Data(T,int)"<<endl;
  }
};


template<class T1,class T2>
class Data<T1*,T2*>{
  public:
  Data(){
    cout<<"Data<T1*,T2*>"<<endl;
  }
};

template<class T1,class T2>
class Data<T1&,T2&>{
  public:
    Data(){
      cout<<"Data(T1&,T2&)"<<endl;
    }
};

int main(){
  Data<double,int> d1;
  Data<int,double> d2;
  Data<int*,int*> d3;
  Data<int&,int&> d4;
  return 0;
}
