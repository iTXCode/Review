#include"SelectSort.hpp"

void TestSort(){
  int array[]={1,4,3,9,78,65,98,20};
  int size=sizeof(array)/sizeof(array[0]);

  SelectSort(array,size);
  PrintSort(array,size);

  SelectSortR(array,size);
  PrintSort(array,size);

  SelectSortXN(array,size);
  PrintSort(array,size);

  HeapSort(array,size);
  PrintSort(array,size);

  BubbleSort(array,size);
  PrintSort(array,size);

  BubbleSort1(array,size);
  PrintSort(array,size);
}

int main(){
  TestSort();
  return 0;
}



