#include<iostream>

using namespace std;

class Ehan{
  public:
    static Ehan* GetEhan(){
      return _ehan;
    }

  private:
     static Ehan* _ehan;
     Ehan(){
       cout<<"Ehan()"<<endl; 
     }

     Ehan(const Ehan& ehan)=delete;
     Ehan& operator=(const Ehan& han)=delete; 
};

Ehan* Ehan::_ehan;

int main(){
  return 0;
}
