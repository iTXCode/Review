#include<iostream>

using namespace std; 


void PrintSort(int *array,int size){
  for(int i=0;i<size;i++){
    cout<<array[i]<<" "; 
  }
  cout<<endl;
}

void Swap(int *a,int *b){
  int tmp=*a;
  *a=*b;
  *b=tmp;
}
//直接选择排序
//每次选最小的数
void SelectSort(int *array,int size){
  for(int i=0;i<size;i++){
    //遍历所有从下标为i往后的数字,找到最小数字的下标
    int min=i;

    for(int j=i+1;j<size;j++){
      if(array[j]<array[min]){
        min=j;
      }
    }

    //交换 最小的数到下标为i的位置
    if(i!=min){
      Swap(array+min,array+i);
    }
  }
}


void SelectSortR(int *array,int size){
  for(int i=0;i<size;i++){
    int max=i;

    for(int j=i+1;j<size;j++){
      if(array[j]>array[max]){
        max=j;
      }
    }

    //进行交换
  
    if(max!=i){
      Swap(array+max,array+i);
    }
  }
}

//进化版
//一次既找最大也找最小

void SelectSortXN(int *array,int size){
  int minSpace = 0; //用于存储最小数的下标
  int maxSpace = size- 1; //用于存放最大数值的下标

  while(minSpace < maxSpace ){
    int min=minSpace;
    int max=minSpace; 

    for(int j=minSpace+1;j<=maxSpace;j++){
      if(array[j]<array[min]){
        min=j;
      }

      if(array[j]>array[max]){
        max=j;
      }
    }

    if(min!=minSpace){  
      Swap(array+min,array+minSpace);
    }

    if(minSpace==max){
      max=min;
    }

    if(max!=minSpace) {  
      Swap(array+max,array+maxSpace);
    }

    minSpace++;
    maxSpace--;
  }
}


