#include"BinaryHeap.hpp"

void TestHeap(){
  int array[]={1,2,3,4,5,6,7,8,9};
  size_t size=sizeof(array)/sizeof(array[0]);
  Heap<int> heap;
  heap.HeapInit(&heap,array,size);
  heap.PrintHeap(&heap);
  heap.HeapPush(&heap,100);
  heap.PrintHeap(&heap);
  heap.HeapPop(&heap);
  heap.PrintHeap(&heap);

  heap.HeapModify(&heap);
  heap.PrintHeap(&heap);

  heap.Heap_Find(&heap);
  heap.Heap_Sort(array,size);
  
  for(auto& e:array){
    cout<<e<<" ";
  }
  cout<<endl;
}

int main(){
  TestHeap();
  return 0;
}



