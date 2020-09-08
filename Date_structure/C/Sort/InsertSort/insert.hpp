#include<iostream>


void InsertSort(int* array,int size){

  for(int i=1;i<size;i++){
    int k=array[i];
    int j=0;
    for( j=i-1;j>=0;j--){
      if(array[j]<= k){
        break;
      }else{
        array[j+1]=array[j];
      }
    }
    array[j+1]=k;
  }
}


void Print(int* array,int size){
  for(int i=0;i<size;i++){
    std::cout<<array[i]<<" ";
  }
  std::cout<<std::endl;
}

namespace ShellSort{
  void ShInsert(int* array,int size,int gap){

    for(int i=gap;i < size; i++){
      int flag = array[i];
      int j=0;
      
      for(j=i-gap;j >= 0;j-=gap){
        if(array[j] >=  flag){
            break;
        }else{
            array[j+gap]=array[j];
        }
     
      }
     array[j+gap]=flag;
    }
  }
  
  void Shell(int* array,int size){
    int gap=size;
    
    while(1){
      gap=gap/3;

      ShInsert(array,size,gap);
    
      if(gap==1){
        return;
      }
    }
  }
  
}
