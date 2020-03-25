//#include<iostream>
//#include<string>
//#include<string.h>
//
//using namespace std;
//
//class String{
//  public:
//    String(const char* str=""){
//      //构造string类对象时,如果传递nullptr，认为程序非法,
//      if(str==nullptr){
//        return;
//      }
//      _str=new char[strlen(_str)+1];
//      strcpy(_str,str);
//    }
//    
//    String(const String&s)
//      :_str(new char[strlen(s._str)+1])
//    {
//      strcpy(_str,s._str);
//    }
//
//    String& operator=(const String& s){
//      if(this!=&s){
//       //判断是否给自己赋值
//        char* str=new char[strlen(s._str)+1];
//        strcpy(str,s._str);
//        delete[] _str;
//        _str=str;
//      }
//      return *this;
//    }
//
//    ~String(){
//      if(_str){
//        delete[] _str;
//        _str=nullptr;
//      }
//    }
//
//  private:
//    char* _str;
//};
//
//int main(){
//    
//  return 0;
//}
// 
//
//



//现代写法

#include<iostream>
#include<string>
#include<string.h>

using namespace std;

class String{
  public:
    String(const char* str=""){
      if(str==nullptr)
      {
        str="";
      }
      _str=new char[strlen(str)+1];
      strcpy(_str,str);
    }

    String(const String& s)
    :_str(nullptr)
    {
      String tmp(s._str);
      swap(_str,tmp._str);
    }

    String& operator=(String s){
      if(this!=&s){
        String str(s);
        swap(_str,str._str);
      }
      return *this;
      //释放自己的空间,将别人的空间拿过来用
    }

    ~String(){
      if(_str){
        delete[] _str;
        _str=nullptr;
      }
    }
  private:
    char * _str;
};

int main(){

  return 0;
}
