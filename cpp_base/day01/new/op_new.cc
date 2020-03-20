#include<iostream>

  using namespace std;
      
  int main(){
    //两种处理异常的方式
    cout << "malloc:" << endl;
    char *p = (char*)malloc(0x7ffffffff);
    cout << (void*)p << endl;
    free(p);
    cout << "new:" << endl;
    try{
      char *p = new char[0X7fffffff];
      cout << (void*)p << endl;
    }
    catch (exception& e){
      cout << e.what() << endl;
      //特殊接口：e.what()
    }
    //operator new:malloc + 异常
    //operator delete<==>free(相当于)

    return 0;
  }



