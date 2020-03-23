#include<iostream>

using namespace std;
class Singleton{

  public:
    static Singleton* getSingleton(){
      return &_pIntance;
    }
  private:

    Singleton (){
      cout<<"Singleton()"<<endl;
    }

    Singleton& operator=(Singleton const&)=delete;
    Singleton(const Singleton& s)=delete;

    static Singleton _pIntance;
};

Singleton Singleton::_pIntance; 

int main(){
  Singleton *ps=Singleton::getSingleton();
  Singleton* s(ps);
  return 0;
}
