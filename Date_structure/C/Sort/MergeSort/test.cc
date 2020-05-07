#include"MergeSort.hpp"

void TestSort(){
  int array[]={1,3,7,9,6,4,54,76,34,66};
  int size=sizeof(array)/sizeof(array[0]);
  PrintArray(array,size);
  MergeSort(array,size);
  PrintArray(array,size);

  int array1[]={66,44,33,22,11,9,8,7};
  int size1=sizeof(array)/sizeof(array[0]);

  Merge_Sort(array1,size1);
  PrintArray(array1,size1);
}

int main(){
  TestSort();
  return 0;
}
