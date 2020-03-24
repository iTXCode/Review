#include<iostream>
#include<string>
 using namespace std;

int main(){
  string s="I am a teacher!";
  string s1("hello bit!");
  string s2(10,'s');
  cout<<"s:"<<s<<endl;
  cout<<"s1:"<<s1<<endl;
  cout<<"s2:"<<s2<<endl;
  cout<<"s.size: "<<s.size()<<endl;
  cout<<"s1.length:"<<s1.length()<<endl;
  cout<<"s1.capacity:"<<s1.capacity()<<endl; 
  s1.clear();
  cout<<"s1.capacity:"<<s1.capacity()<<endl; 
  cout<<"s1.size: "<<s1.size()<<endl;
  //使用clear()函数之后,其容量大小没变
  //但是字符串的有效字符为0
   cout<<s.empty()<<endl;
   cout<<"s[0]:"<<s[0]<<endl;
  return 0;
}
