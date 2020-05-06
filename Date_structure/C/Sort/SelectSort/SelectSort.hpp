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


//选择排序的逆排序
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
//双向选择
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

    //存在的情况为minSpace位置的下标即为最大数的位置下标
    //则会导致交换完成后数组的大小顺序未变
//    if(minSpace==max){
//      max=min;
//    }
//
    if(max!=minSpace) { //该判断条件会是我们规避上述情况的发生 
      Swap(array+max,array+maxSpace);
    }

    minSpace++;
    maxSpace--;
  }
}




//堆排序

void AdjustDown(int *array,int size,int root){
  while(1){
    int left=2*root+1;
    int max=left;

    if(left>=size){
      return;
    }

    int right=2*root+2;

    if(right<size && array[right] > array[left]){
      max=right; 
    }

    if(array[max] <= array[root]){
      return;
    }

    Swap(array+root,array+ max);
    root=max;
  }
}

void CreateHeap(int *array,int size){
  if(array==nullptr){
    return;
  }

  for(int i=(size-2)/2;i>=0;i--){
    AdjustDown(array,size,i);
  }
}


//建大堆,排升序
void HeapSort(int *array,int size){

  CreateHeap(array,size);

  for(int i=0;i<size-1;i++){
    Swap(array,array+size-1-i);
    AdjustDown(array,size-i-1,0);
  }
}



//交换排序
//冒泡排序
//排逆序
void BubbleSort(int *array,int size){
  for(int i=0;i<size;i++){
    for(int j=i+1;j<size;j++){
     if(array[i]<array[j])
      Swap(array+i,array+j);
    }
  }
}


//优化版本

void BubbleSort1(int *array,int size){
  for(int i=0;i<size;i++){
    int flag=1;

    for(int j=i+1;j<size;j++){
      if(array[i]>array[j])
      { 
        Swap(array+i,array+j); 
      } 
      flag=0;
    }

    if(flag==1){
      return;
    }
  }
}
