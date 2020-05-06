#include"Quick_sort.hpp"

void TestSort(){
  int array[]={0,1,4,3,6,4,57,76,89,23,2};
  int size=sizeof(array)/sizeof(array[0]);
 
  QuickSort(array,size);
  PrintArray(array,size);
}

int main(){
  TestSort();
  return 0;
}
