//#include<iostream>
//
//void Swap(int *a,int *b){
//  int tmp=*a;
//   *a=*b;
//  *b=tmp;
//}
//
//
//int Partion(int *array,int left,int right){
//  //将基准值大的放到基准值右边,小的放到左边
//  int start=left;
//  int end=right;
//  while(start<end){
//    while(start<end && array[start]<= array[right]){
//      start++;
//    }
//
//    while(start<end && array[end] >= array[right]){
//      end--;
//    }
//
//    Swap(array+start,array+end);
//  }
//  Swap(array+ start,array+right);
//  return start;
//}
//
//int Partion1(int *array,int left,int right){
//  
//  int tmp=array[right];
//  int start=left;
//  int end=right;
//  while(start<end){
//    while(start<end && array[start] < tmp){
//      start++;
//    }
//
//    array[end]=array[start];
//    while(start<end && array[end ]> tmp){
//      end--;
//    }
//
//    array[start]=array[end];
//  }
//  array[start]=tmp;
//  return start;
//}
//
//
//int  Partion2(int *array,int left,int right){
//  //前后标兵法
//  int index=left;
//  for(int i=left;i<right;i++){
//    if(array[i]>array[right]){
//      if(index!=i){
//        Swap(array+index,array+i);
//      }
//    index++;
//    }
//
//  }
//  Swap(array+index,array+right);
//  return index;
//}
//
//void Print(int *array,int size){
//  for(int i=0;i<size;i++){
//    std::cout<<array[i]<<" ";
//  }
//  std::cout<<std::endl;
//}
//
//void QuickSort(int* array,int left,int right){
//  if(left>=right){
//    return;
//  }
//
//  int div=Partion(array,left,right);
//  QuickSort(array,left,div-1);
//  QuickSort(array,div+1,right);
//}
//
//void FastSort(int *array,int size){
//  
//  
//  QuickSort(array,0,size-1);
//}
//
//int main(){
//
//  return 0;
//}


#include<iostream>

using  namespace  std;

void Swap(int* a,int* b){
  int tmp=*a;
  *a=*b;
  *b=tmp;
}
int Partion(int* array,int left,int right){


    int start=left;
    int end=right;
    while(start<end){ 
      while(start<end && array[start] < array[right]){
        start++;
      }

      while(start<end && array[end] > array[right]){
        end--;
      }

      Swap(array+start,array+end);
    }

    Swap(array+start, array+right);
    return start;
}

int Partion1(int* array,int left,int right){
  int start=left;
  int end=right;
  int memo=array[right];
  while(start<end){
    while(start<end && array[start] >= memo){
      start++;
    } 

    array[end]=array[start];
    while(start< end && array[end ]<= memo){
      end--;
    }

    array[start]=array[end];
  }

  array[start]=memo;
  return start;
}

int Partion2(int *array,int left,int right){
  int index = left;
  for(int i=left;i<right;i++){
    if(array[i] > array[right]){
      if(index != i){
        Swap(array+i,array+index);
      }
    index++;
    }

  }
  Swap(array+index,array+right);
  return index;
}

void QuickSort(int *array,int left,int right){
  if(left>=right){
    return;
  }

  //int div=Partion(array,left,right);
  
  //int div=Partion1(array,left,right);

  int div=Partion2(array,left,right);
  QuickSort(array,left,div-1);
  QuickSort(array,div+1,right);
}


void FastSort(int* array,int size){
  QuickSort(array,0,size-1);
}

void Print(int* array,int size){
  for(int i=0;i<size;i++){
    cout<<array[i]<<" ";
  }
  cout<<endl;
}

int main(){
  int array[]={1,0,9,4,2,5,6,7,8,3};
  int len=sizeof(array)/sizeof(array[0]);
  FastSort(array,len);
  Print(array,len);
  return 0;
}
