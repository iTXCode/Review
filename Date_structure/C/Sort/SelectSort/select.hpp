#include<iostream>

void Swap(int *a,int *b){
  int tmp=*a;
  *a=*b;
  *b=tmp;
}

void  SelectSort(int* array,int size){
  for(int i=0;i<size-1;i++){
    int min = i;
   
    for(int j=i+1;j < size; j++){
      if(array[j] >  array[min]){
        min=j; 
      }
    }
    if(min!=i)
    Swap(array+min,array+i);
  }
}


void Print(int * array,int size){
  for(int i=0;i<size;i++){
    std::cout<<array[i]<<" ";
  }
  std::cout<<std::endl;
}


//void SelectMAXMIN(int* array,int size){
//  int minSpace = 0; //用于存储最小数的下标
//  int maxSpace = size-1; //用于存放最大数值的小标
//
//  while(minSpace < maxSpace){
//    int min=minSpace;
//    int max=minSpace; 
//
//    for(int j=minSpace+1;j<=maxSpace;j++){
//      if(array[j]<array[min]){
//        min=j;
//      }
//
//      if(array[j]>array[max]){
//        max=j;
//      }
//    }
//
//    Swap(array+min,array+minSpace);
//
//    if(minSpace == max){
//      max=min;
//    }
//    Swap(array+max,array+maxSpace);
//    minSpace++;
//    maxSpace--;
//  }
//}


void SelectMaxMin(int* array,int size){
  if(array==nullptr){
    return ;
  }

  int minSpace=0;
  int maxSpace=size-1;

  while(minSpace<maxSpace){
    int min=minSpace;
    int max=minSpace; 

    for(int i= min+1;i<=maxSpace;i++){
      if(array[i] > array[max]){
        max=i;
      }

      if(array[i] < array[min]){
        min=i;
      }
    }

    //找到范围内的最小数和最大数的下标
    Swap(array+min,array+minSpace);

    if(max == minSpace){
      //该值没有改变说明,最大值就是范围内的第一个
      max=min;
    }
    
    Swap(array+max,array+maxSpace);
    minSpace++;
    maxSpace--;
  }
}



void BubbleSort(int* array,int size){

  for(int i=0;i<size;i++){
    for(int j=0;j<size-1-i;j++){
      if(array[j]<array[j+1]){
        Swap(array+j,array+j+1);
      }
    }
  }
}


void BubbleSort1(int* array,int size){

  for(int i=0;i<size;i++){
    int flag=1;
    for(int j=0;j<size-1-i;j++){
      if(array[j]<array[j+1]){
        Swap(array+j,array+j+1);
        flag=0;
      }
    }
    if(flag==1){
      return;
    }
  }
}
