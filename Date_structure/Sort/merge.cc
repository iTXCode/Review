#include<iostream>

void Swap(int* a,int* b){
  int tmp=*a;
  *a=*b;
  *b=tmp;
}

void Print(int* array,int size){
  for(int i=0;i<size;i++){
    std::cout<<array[i]<<" ";
  }
  std::cout<<std::endl;
}

void _Merge(int* array,int left,int mid,int right,int* arr){
   int index=0;
    int size=right-left;
    int start=left;
    int end=mid;

    while(start < mid && end<right){
      if(array[start] <= array[end]){
        arr[index]=array[start++];
      }else{
        arr[index]=array[end++];
      }
      index++;
    }
    
    while(start<mid){
      arr[index++]=array[start++];
    }

    while(end<right){
      arr[index++]=array[start++];
    }

    for(int i=0;i<size;i++){
      array[left+i]=arr[i];
    }
  
}

void Merge(int* array,int left,int right,int* arr){

  if(right ==left+1){
    return;
  }

  if(left>=right){
    return; 
  }

  int mid=(right-left)/2 +left; 
  Merge(array,left,mid,arr);
  Merge(array,mid,right,arr);
  _Merge(array,left,mid,right,arr);
}

void MergeSort(int* array,int len){
  int * arr=new int[len];
  Merge(array,0,len-1,arr);
  free(arr);
}

int main(){
  int array[]={9,0,1,4,3,2,7,6,5,8,2};
  int size=sizeof(array)/sizeof(array[0]);
  MergeSort(array,size);
  return 0;
}
