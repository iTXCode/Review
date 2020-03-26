#include<iostream>
#include<string.h>
#include<assert.h>

class String{

  public:
    String(const char* str)
    :_str(new char[  strlen(str)+1 ])
    {
      strcpy(_str,str);
    }

    String(const String& s)
    :_str(nullptr)
    {
      String str(s._str);
      std::swap(_str,str._str);
    }

    String& operator=(const String& s){

      if(this!=&s){
        String str(s._str);
        std::swap(_str,str._str);
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
  String s("hello world!");
  String s1(s);
  return 0;
}
