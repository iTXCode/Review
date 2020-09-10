#include<iostream>

void Swap(int *a,int *b){
  int tmp=*a;
  *a=*b;
  *b=tmp;
}

void InsertSort(int* array,int  size){
     
  for(int i=1;i<size;i++){
    int tmp=array[i]; 
    int j=0;
    for( j=i-1;j>=0;j--){
      if(array[j] <  tmp){
        break;
      }else{
        array[j+1]=array[j];
      }
    }
    array[j+1]=tmp;
  }
}

void Sort(int* array,int gap,int size){
  for(int i=gap ;i<size;i++){
    int tmp=array[i];
    int j=0;
    for(j=i-gap;j>=0;j-=gap){
      if(array[j] >=  tmp){
       break;
      }else{
        array[j+gap]=array[j];
      }
    }
    array[j+gap]=tmp;
  }
}

void ShellSort(int *array,int size){
  int gap=size;
  while(1){
    gap/=3;
    Sort(array,gap,size);
    if(gap==1){
      return;
    }
  }
}


void Print(int *array,int size){
  for(int i=0;i<size;i++){
    std::cout<<array[i]<<" ";
  }
  std::cout<<std::endl;
}

int main(){
  int array[]={1,4,3,2,5,8,6,7,8};
  int size=sizeof(array)/sizeof(array[0]);
  InsertSort(array,size);
  Print(array,size);
  ShellSort(array,size);
  Print(array,size);
  return 0;
}
