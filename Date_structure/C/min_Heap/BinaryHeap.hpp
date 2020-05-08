#pragma once
#include<iostream>
#include<memory.h>
#include<stdlib.h>
using namespace std; 

template <class T>
class Heap{
  public:
    Heap(const int& size=T())
      :_array(nullptr)
       ,_size(size) 
  {}

    void HeapInit(Heap<T>* heap,T* array,int size){
      
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

    void AdjustDown(T* array,int size,int parent){
      //向下调整,

      while(1){
        int left=2*parent+1;
        int right=2*parent+2;


        if(left>=size){
          //需要调整的这个结点没有左孩子的情况
          return;
        }
        int min=left;

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

    void AdjustUp(T* array,int size,int child){
      
    
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
      int index=-1;

      for(int i=0;i<heap->_size;i++){
        if(heap->_array[i]==value){
          index=i;
        }
      }

      if(index==-1){
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
    void CreateHeap(T* array,int& size){
  
      for(int i=(size-2)/2;i>=0;i--){
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
  int _size;
};



