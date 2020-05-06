#pragma once 
#include<iostream>

using namespace  std; 

void PrintArray(int * array,int size){
  for(int  i=0;i<size;i++){
    cout<<array[i]<<" ";
  }
  cout<<endl;
}


void InsertSort(int * array,int size){

  for(int i=1;i<size;i++){
    int k=array[i];
    int j;
    for( j=i-1;j>=0;j--){
      if(array[j]<=k){
        //需要进行前移操作
       break;  
      }else{
        array[j+1]=array[j];
      }
    }
    array[j+1]=k;
  }
}


//逆序的排列方式
void InsertSortWithGap(int * array,int size,int gap){

  for(int i=gap;i<size;i++){
    int k=array[i];
    int j;
    for( j=i-gap;j>=0;j-=gap){
      if(array[j]>k){
        //需要进行前移操作
       break;  
      }else{
        array[j+gap]=array[j];
      }
    }
    array[j+gap]=k;
  }
}


void ShellSort(int* array,int  size){
  int gap=size;

  while(1){
    gap=gap/3;

    InsertSortWithGap(array,size,gap);

    if(gap==1){
      return;
    }
  }
}
