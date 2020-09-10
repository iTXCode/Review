#include<iostream>

void Swap(int* a,int* b){
  int tmp=*a;
  *a=*b;
  *b=tmp;
}

void SelectSort(int* array,int size){
  for(int i=0;i<size;i++){
    int min=i;

    for(int j=i+1;j<size;j++){
      if(array[j] <= array[min]){
        min=j;
      }
    }
    if(i!=min)
    Swap(array+i,array+min); 
  }
}


//void Select(int *array,int size){
//  for(int i=0;i<size;i++){
//    int min=i;
//    for(int j=i+1;j<size ;j++){
//      if(array[j]<array[min]){
//        min=j;
//      }
//    }
//    Swap(array+i,array+min);
//  }
//}

void Print(int* array,int size){
  for(int i=0;i<size;i++){
    std::cout<<array[i]<<" ";
  }
  std::cout<<std::endl;
}

void SelectMaxMin(int *array,int size){
    int maxValue=0;
    int minValue=size-1;

    while(minValue<maxValue){
      int min=minValue;
      int max=minValue; 

      for(int i = min+1;i<=maxValue; i++){
        if(array[i] > array[max]){
          max=i;
        }

        if(array[i]< array[min]){
          min=i;
        }
      }
      Swap(array+min ,array+minValue);

      if(max == minValue){
        max=min;
      }

      Swap(array+max,array+maxValue);
      minValue++;
      maxValue--;
    }

}


//void MaxMin(int *array,int size){
//  int minSpace=0;
//  int maxSpace=size-1;
//  while(minSpace < maxSpace){
//    int min=minSpace;
//    int max=minSpace;
//
//    for(int i=min+1 ; i< maxSpace;i++){
//      if(array[i] < array[min]){
//        min=i;
//      }
//
//      if(array[i] > array[max]){
//        max=i;
//      }
//    }
//
//    Swap(array+min,array+minSpace);
//
//    if(max == minSpace){
//      max=min;  //存在一组元素相等的情况
//    }
//
//    Swap(array+max ,array + maxSpace);
//    minSpace++;
//    maxSpace--;
//  }
//}

void BubbleSort(int* array,int size){

  for(int i=0;i < size; i++){
    for(int j=0;j < size-1-i;j++){
      if(array[j] < array[j+1]){
        Swap(array+j,array+j+1);
      }
    }
  }
}

int main(){
  int array[]={0,1,4,3,2,8,6,4,5,9};
  int size=sizeof(array)/sizeof(array[0]);
  SelectSort(array,size);
  Print(array,size);
  SelectMaxMin(array,size);
  Print(array,size);
  BubbleSort(array,size);
  printf("冒泡排序:");
  Print(array,size);
  return 0;
}
