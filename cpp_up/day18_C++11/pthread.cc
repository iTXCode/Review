#include<iostream>
#include<map>
#include<thread>
#include<mutex>
#include<atomic>

using namespace std;
 
//int num=0;
//void fun1(int n){
//  for(int i=0;i<n;i++){
//    ++num;
//  }
//}
//
//int main(){
//  int n=0;
//  cin>> n;
//  thread t1(fun1,n);
//  thread t2(fun1,n);
//  t1.join();
//  t2.join();
//  cout<<num<<endl;
//  return 0;
//}



//进行加锁
int num=0;
mutex _mtx;
void fun1(int n){
  for(int i=0;i<n;i++){
   // _mtx.lock();
    ++num;
    //_mtx.unlock();
  }
  cout<<"num"<<endl;
}

int main(){
  int n=0;
  cin>> n;
  thread t1(fun1,n);
  thread t2(fun1,n);
//  t1.join(); 
//  t2.join();
      //会和式:主线程必须等待子线程结束,回收资源
      
  
  t1.detach(); //分离后主线程直接会退出
  t2.detach(); //分离式:主线成无需等待子线程执行结束,系统在线程结束之后,系统回收资源
  cout<<num<<endl;
  return 0;
}
