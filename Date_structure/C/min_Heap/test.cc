#include"BinaryHeap.hpp"

void Test(){
  int array[]={100,64,5,36,78,97,46,23};
  size_t size=sizeof(array)/sizeof(array[0]);
  Heap<int> heap;
  heap.HeapInit(&heap,array,size);
  heap.PrintHeap(&heap);
  heap.HeapPop(&heap);
  heap.PrintHeap(&heap);

  cout<<"请输入你要插入的值:";
  int value=0;
  cin>>value;
  heap.HeapPush(&heap,value);
  heap.PrintHeap(&heap);
  cout<<"请输入你要插入的值:";
  int value1;
  cin>>value1;
  heap.HeapPush(&heap,value1);
  heap.PrintHeap(&heap);

  cout<<"请输入要查找的内容:";
  int data=0;
  cin>>data;
  bool ret=heap.Find(&heap,data);

  if(ret==0){
    cout<<"您所差找的内容不存在!"<<endl;
  }else {
    cout<<"您所差找的内容存在!"<<endl;
  }

  cout<<"请输入您要修改的内容:";
  int val;
  cin>>val;
  heap.HeapModify(&heap,val);
  heap.PrintHeap(&heap);
}

int main(){
  Test();
  return 0;
}
