#include"InsertSort.hpp"

void TestSort(){
  int array[]={1,2,5,6,4,8,7,0,9};
  size_t size=sizeof(array)/sizeof(array[0]);

  InsertSort(array,size);
  PrintArray(array,size);


  ShellSort(array,size);
  PrintArray(array,size);
}

int main(){
  TestSort();
  return 0;
}
