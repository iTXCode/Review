#include<iostream>


using namespace std; 

double Division(double& left,double& right){
  if(right==0){
    throw  "Division by zero condition!";
  }else{
    return (left/right);
  }
}

void Func(){
  try{
    double left;
    double  right;
    cout<<"请输入两个操作数:";
    cin>>left>>right;
    cout<<Division(left,right)<<endl;

  }
  catch(const char* msg){
    cout<<msg<<endl;
  }
  catch(...){
   cout<<"unknow exption!"<<endl;
  }
}

int main(){
  try{
    Func();
  }
  catch (const char* msg){
    cout<<msg<<endl;
  }
  return 0;
}
