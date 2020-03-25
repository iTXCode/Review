#include<iostream>
#include<assert.h>
#include<string.h>

using namespace std;

class String{

  public:
    String(const char* str="")
    :_str(new char[strlen(str)+1])
    {    
      strcpy(_str,str);
    }
    
    //拷贝构造函数【现代写法】
    String(const String& s)
    :_str(nullptr) 
    {
      String tmp(s._str);
      swap(_str,tmp._str);
    }

    //传统写法
  // String &operator=(const String& s){
  //    if(this!=&s){
  //      delete[] _str;
  //      _str=new char[strlen(s._str)+1];
  //      strcpy(_str,s._str);
  //    }
  //    return *this;
  //  }
   //现代写法
    String& operator=(String s){
      swap(_str,s._str);
      return *this;
    }

    const char* c_str(){
      return _str;
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
  String s;
  cout<<s.c_str()<<endl;
  return 0;
}
