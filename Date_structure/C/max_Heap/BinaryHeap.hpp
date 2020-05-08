#pragma once 
#include<iostream>
#include<memory.h>

using namespace std;

template <class T>

class Heap{
  public:
    Heap(int size=T())
      :_array(nullptr)
       ,_size(size)
  {}

    void HeapInit(Heap<int>* heap,const T* array,int size){
      heap->_array=new T[size];
      heap->_size=size;
      memcpy(heap->_array,array,sizeof(T)*size);
      //用来将指定数据中的内容拷贝到堆数组空间中
      _CreateHeap(heap->_array,heap->_size); 
    }




    void PrintHeap(const Heap<T>* heap){
      if(heap==nullptr){
        return;
      }

      for(int i=0;i<heap->_size;i++){
        cout<<heap->_array[i]<< " ";
      }
      cout<<endl;
    }


   void  HeapPush(Heap<T>* heap,T val){
      heap->_array[heap->_size]=val;
      heap->_size++;
      AdjustUp(heap->_array,heap->_size,heap->_size-1);
    }

   void HeapPop(Heap<T>* heap){
     if(heap==nullptr){
       return;
     }

     Swap(heap->_array,&heap->_array[--heap->_size]);

     AdjustDown(heap->_array,heap->_size,0);
   }

   void Heap_Find(const Heap<T>* heap){
     int val=0;
    
     cout<<"请输入您要差找的值:";
     cin>>val;
     int  index=-1;

     for(int i=0;i<heap->_size;i++){
       if(heap->_array[i]==val){
         index=i;
         break;
       }
     }

     if(index==-1){
       cout<<"您所要查找的值不存在!"<<endl;
       return;
     }

     cout<<"您所要查找的值在该堆中!"<<endl;

   }


   T& Heap_Top(const Heap<T>* heap){
     cout<<heap->_array[0];
   }


   //堆排序
   void Heap_Sort(T* array,int size){
     _CreateHeap(array,size);
     for(int i=0;i<size;i++){
       Swap(array,array+(size-1-i));
       AdjustDown(array,size-1-i,0);
     }
   }

   
   void HeapModify(Heap<T>* heap){
     int val;
     cout<<"请输入要修改的值:";
     cin>>val;

     int  index=-1;

     for(int i=0;i<heap->_size;i++){
       if(heap->_array[i]==val){
         index=i;
         break;
       }
     }

     if(index==-1){
       cout<<"您所要修改的值不存在!"<<endl;
       return;
     }

     cout<<"请输入修改后的值:";
     cin>>val;
     heap->_array[index]=val;

     AdjustUp(heap->_array,heap->_size,index);
   }
  private:
    void _CreateHeap(T* array,int size){
      for(int i=(size-2)/2;i>=0;i--){
        AdjustDown(array,size,i);
      }
    }

    void Swap(T* a,T* b){
      T tmp=*a;
      *a=*b;
      *b=tmp;
    }

    void AdjustDown( T* array,int size,int parent){
      while(1){
        int left=2*parent+1;
        if(left>=size){
          return;
        }



        int max=left;
         int right=2*parent+2;     
        if(right<size && array[left]<array[right]){
          max=right;
        }

        if(array[parent] >=  array[max]){
          return;
        }

        Swap(array+parent,array+max);
        parent=max;
      }
    }


    void AdjustUp(T* array,int  size,int child){

      while(child!=0){
        
        if(child>size){
          return;
        }
        int root=(child-2)/2;

        if(array[root]>=array[child]){
          return;
        }

        Swap(array+root,array+child);
        child=root;
      }
    }
  private:
    T* _array;
    int _size;
};
