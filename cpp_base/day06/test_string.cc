//#include<iostream>
//#include<string>
// using namespace std;
//
//int main(){
//  string s="I am a teacher!";
//  string s1("hello bit!");
//  string s2(10,'s');
//  cout<<"s:"<<s<<endl;
//  cout<<"s1:"<<s1<<endl;
//  cout<<"s2:"<<s2<<endl;
//  cout<<"s.size: "<<s.size()<<endl;
//  cout<<"s1.length:"<<s1.length()<<endl;
//  cout<<"s1.capacity:"<<s1.capacity()<<endl; 
//  s1.clear();
//  cout<<"s1.capacity:"<<s1.capacity()<<endl; 
//  cout<<"s1.size: "<<s1.size()<<endl;
//  //使用clear()函数之后,其容量大小没变
//  //但是字符串的有效字符为0
//   cout<<s.empty()<<endl;
//   cout<<"s[0]:"<<s[0]<<endl;
//  return 0;
//}


#include<iostream>
#include<string>


using namespace std;
 

int main(){
  string s;
  cout<<s.size()<<endl;
  cout<<s.capacity()<<endl;
  cout<<hex<<(int*)s.c_str()<<endl;
  s.resize(10,'&');
  cout<<s.size()<<endl;
  //计算并输出s字符串的有效字符个数
  cout<<s<<endl;

  s.resize(20,'2');
  //对s进行了扩容,并将多处的空间初始化为'5'
  cout<<s<<endl; 
  cout<<s.size()<<endl;
  cout<<s.length()<<endl;


  s.insert(3,4,'$');
  cout<<s<<endl;
  return 0;
}
