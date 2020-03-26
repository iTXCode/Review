//#include<iostream>
//#include<assert.h>
//#include<string.h>
//using namespace std; 
//class String{
//  public:
//    String (const char* s)
//    {
//      if(nullptr==s){
//        assert(false);
//        return; 
//      }
//      _str= new char[strlen(s)+1];
//      strcpy(_str,s);
//    }
//
//    ~String(){
//      if(_str){
//        delete[] _str;
//        _str=nullptr;
//      }
//    }
//  private:
//    char* _str;
//
//};
//int main(){
//  String s1("hello bit!");
//  String s2(s1);
//  return 0;
//}
//



//#include<iostream>
//#include<assert.h>
//#include<string.h>
//using namespace std; 
//class String{
//  public:
//
//    String (const char* str=""){
//      cout<<"String(cosnt char*)"<<endl;
//    }
//    String(const String& ){
//      cout<<"String(const String&)"<<endl;
//    }
//
//    String(){
//      cout<<"String()"<<endl;
//    }
//
//    ~String(){
//      cout<<"~String()"<<endl;
//    }
//  private:
//    char* _str;
//
//};
//int main(){
//  String s1("hello bit!");
//  String s2(s1);
//
//  return 0;
//}
//
//
//



#include<iostream>
#include<string>

using namespace std;


int main(){
  string s("hello world!");
  string s1=s;
  string s2;
  s2=s;

  cout<<"s adress:"<<&s<<endl;
  cout<<"s1 adress:"<<&s1<<endl;
  cout<<"s2 adress:"<<&s2<<endl;
  printf("adress s:%x\n",s.data());
  printf("adress s1:%x\n",s1.data());
  printf("adress s2:%x\n",s2.data());

  s1="abc";
  s2="cde";
  cout<<"s adress:"<<&s<<endl;
  cout<<"s1 adress:"<<&s1<<endl;
  cout<<"s2 adress:"<<&s2<<endl;

  
  printf("adress s:%x\n",s.data());
  printf("adress s1:%x\n",s1.data());
  printf("adress s2:%x\n",s2.data());
  return 0;
}
