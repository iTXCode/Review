#include<iostream>

int main(){
  int arr[]={1,2,3,4,5,6,7,8,9,0};
  int size=sizeof(arr)/sizeof(arr[0]);
  for(int i=0;i<size;++i){
    std::cout<<arr[i]<<std::endl;
  }

  for(auto& e:arr){
    std::cout<<e<<std::endl;
    e++;
  }
  return 0;
}
