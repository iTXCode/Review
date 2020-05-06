#include"FastSort.hpp"

void TestSort(){
  int array[]={1,4,3,7,8,4,0,45,65,12,1,46};
  int size=sizeof(array)/sizeof(array[0]);

  PrintArray(array,size);

  QuickSort(array,size);
  PrintArray(array,size);
}

int main(){
  TestSort();
  return 0;
}
