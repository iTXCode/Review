#include<iostream>
#include<string.h>
#include<assert.h>


using namespace std;

class String{

  public:

    String(const char* str){
      if(str==nullptr){
        assert(str);
        return ;
      }
      _str=new char[strlen(str)+1];
      strcpy(_str,str);
    }

    String(const String&s)
    :_str(new char[strlen(s._str)+1])
    {
      strcpy(_str,s._str);
    }

    String& operator=(const String&s){
      if(this!=&s){
        char *str=new char[strlen(s._str)+1];
        strcpy(str,s._str);
        delete[] _str;
        _str=str;
      }
      return *this;
    }

    ~String(){
      if(_str){
        delete[] _str;
        _str=nullptr;
      }
    }
  private:
    char* _str;
};

int main(){
  String s("hello bit!");
  String s1(s);
  return 0;
}
