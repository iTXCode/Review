#include"FastSort.hpp"

void TestSort(){
  int array[]={1,4,3,7,8,4,0,45,65,12,1,46};
  int size=sizeof(array)/sizeof(array[0]);

  PrintArray(array,size);

  cout<<"hoare法测试:"<<endl;
  QuickSort(array,size);
  PrintArray(array,size);

  int array1[]={65,46,45,12,8,7,4,4,3,1,1,0};
  int size1=sizeof(array1)/sizeof(array1[0]);
  cout<<"挖坑法测试:"<<endl;
  QuickSort_wakeng(array1,size1);
  PrintArray(array1,size1);

  int array3[]={ 65,46,45,12,8,7,4,4,3,1,1,0 };
  int size3=sizeof(array3)/sizeof(array3[0]);

  cout<<"前后下标法:"<<endl;
  QuickSort_Point(array3,size3);
  PrintArray(array3,size3);
}

int main(){
  TestSort();
  return 0;
}
