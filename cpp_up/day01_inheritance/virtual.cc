#include <iostream>
#include <string>

using namespace std;

class GFather{

  public:
    int _num=3;
};

class Father:virtual public GFather{
  public:
    int _id=2;
};

class Mother:virtual public GFather{
  public:
    int _n=1; 
};


class My:public Mother,public Father{
  public:
    int num=10;
};
int main(){
  My m;
  cout<<m._num<<endl;
  cout<<m.Father::_num<<endl;
  cout<<m.Mother::_num<<endl;
  return 0;
}
