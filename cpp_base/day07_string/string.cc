//#include<iostream>
//#include<string.h>
//#include<string>
//using namespace std;
//
//class String{
//  public:
//    //字符串指针输出会作解引用,解引用空指针会奔溃
//    
//    /*~String()
//     * :_str(new char[1]){
//     *  _str[0]='\0';
//     * }
//     * 带参构造函数,需要申请和输出字符串一样大的空间
//     * 把输入字符串拷贝进去,如果只拷贝字符串指针
//     * 释放可能会有问题
//     * 1.二次释放(两个指针可能指向同一片空间)
//     * 2.如果传入的为字符串常量,析构就会奔溃(不能主动释放代码段的字符)
//     * */
//    String(const char* str="")
//      :_str(new char[strlen(str)+1])
//      {
//        strcpy(_str,str);
//      }
//
//    //析构函数
//    ~String(){
//      if(_str){
//        //判断是否为有效指针
//        cout<<"~String()"<<endl;
//        delete[] _str;
//        _str=nullptr; 
//      }
//    }
//
//    //拷贝构造的传统写法
//  //  String(const String&s)
//  //  :_str(new char[strlen(s._str)+1])
//  //  {
//  //    strcpy(_str,s._str);
//  //  }
//
//    //现代写法
//    
//    String(const String& s)
//    :_str(nullptr)
//     //若不制空,*this指针指向随机值
//     //当把其中的内容交还给tmp._str后,tmp._str调用析构函数释放的是随机指针
//    {
//      String tmp(s._str);
//      //调用析构函数生成同一份资源,使得指针交换之后
//      //两个指针指向的 内容是一样的
//      swap(_str,tmp._str);
//    }
//    
//
//    //赋值运算符:传统写法
//   // String& operator=(const String& s){
//   //   if(this!=&s){
//   //     //检查是否自己给自己赋值
//   //     delete[] _str;
//   //     _str=new char[strlen(s._str)+1];
//   //     strcpy(_str,s._str);
//   //   }
//   //   return *this;
//   // }
//   
//
//    //赋值运算符重载[现在写法]
//    //传入参数:传值调用拷贝构造,不用调用赋值运算符重载
//    //不会引发赋值运算符无群递归,通过调用拷贝构造完成拷贝
//    //传值相当于在函数栈帧中生成一个零时对象
//    //和拷贝构造相比,生成零时对象的实际不同
//    //拷贝构造:函数内部生成
//    //赋值:传值的时候生成
//    
//    String& operator=(String s){
//      String tmp(s);
//      swap(_str,tmp._str);
//      return *this;
//    }
//   
//   
//  private:
//      char* _str;
//};
//
//
//int main(){ 
//    
//  return 0;
//}


#include<iostream>
#include<string.h>
#include<assert.h>
using namespace std;

class String{
  public:
    String(const char* str)
      :_str(new char[strlen(str)+1])
    {
        strcpy(_str,str);

    }

    String(const String& s)
        :_str(nullptr)
    {
        String str(s._str);
        //str是调用构造函数构造的,出了作用域就会自动调用析构函数将str销毁
        //所以将_str初始化为空
        swap(_str,str._str);
            
    }

    String& operator=(const String& s){
      if(this!=&s){
          String tmp(s._str);
            swap(_str,tmp._str);

      }
        return *this;

    }
    /*赋值:s1=s2
     * s1将s2的空间拷贝过来,将自己原来的空间释放了
     * 所以将s1的空间与tmp的空间进行交换,当程序走出
     * 作用域的时候将tmp调用析构函数将所指的空间释放了,
     * 既达到了将s1原来空间释放的目的将新的空间付给了
     * s1，s2就是此处的s*/
    ~String(){
      if(_str){
        cout<<"~String()"<<endl;
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
