
#include<iostream>
#include<memory.h>
#include<stdlib.h>
using namespace std; 

template <class T>
class Heap{
  public:
    Heap(const size_t& size=T())
      :_array(nullptr)
       ,_size(size) 
  {}

    void HeapInit(Heap<T>* heap,T* array,size_t size){
      
      heap->_array=new T[size];
      heap->_size=size;
      memcpy(heap->_array,array,sizeof(T)*size);
      CreateHeap(heap->_array,heap->_size);
    }


    void PrintHeap(const Heap<T>* heap){
      for(int i=0;i<heap->_size;i++){
        cout<< heap->_array[i]<<" ";
      }
      cout<<endl;
    }

    void AdjustDown(T* array,size_t size,size_t parent){
      //向下调整,

      while(1){
        size_t left=2*parent+1;
        size_t right=2*parent+2;


        if(left>=size){
          //需要调整的这个结点没有左孩子的情况
          return;
        }
        size_t min=left;

        if(right<size && array[right]<array[left]){
          min=right;
        }

        if(array[parent]<=array[min]){
          return ;
        }

        Swap(array+parent,array+min);
        parent=min;
      }
    }

    void AdjustUp(T* array,size_t size,size_t child){
      
    
      while(child!=0){
        if(child>size){
          return;
        }

        int root =(child-1)/2;

        if(array[root]<array[child]){
          return;
        }
        Swap(array+root,array+child);
        child=root;
      }
    }


    bool Find(const Heap<T>* heap,T value){
      for(int i=0;i<heap->_size;i++){
        if(value==heap->_array[i])
          return true;
      }
      return false;
    }

    void HeapModify(Heap<T>* heap,T value){
      int index=0;

      for(int i=0;i<heap->_size;i++){
        if(heap->_array[i]==value){
          index=i;
        }
      }

      if(index==0){
        cout<<"您所要修改的的内容不在该堆中!"<<endl;
        return;
      }

      cout<<"请输入修改后的值:";
      T data;
      cin>>data;
      heap->_array[index]=data;

      for(int i=(heap->_size-2)/2;i>=0;i--){
        AdjustDown(heap->_array,heap->_size,i);
      }
    }


    void HeapPush(Heap<T>* heap,T& value){
 
     heap->_array[heap->_size++]=value;
     AdjustUp(heap->_array,heap->_size,heap->_size-1);
    }

    void HeapPop(Heap<T>* heap){ 
      Swap(heap->_array,heap->_array+(heap->_size-1));
      heap->_size--;
      AdjustDown(heap->_array,heap->_size,0);
    }
  private:
    void CreateHeap(T* array,size_t& size){
  
      for(size_t i=(size-2)/2;i>0;i--){
        AdjustDown(array,size,i);
      }
    }


    void Swap(T* a,T* b){
      T tmp=*a;
      *a=*b;
      *b=tmp;
    }

  private:
  T *_array;
  size_t _size;
};


void Test(){
  int array[]={1,64,5,36,78,97,46,23};
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
