#include<iostream>
#include<memory.h>
using namespace std; 

void Swap(int * a,int *b){
  int tmp=*a;
  *a=*b;
  *b=tmp; 
}

void PrintArray(int *array,int size){
  if(array==nullptr){
    return;
  }

  for(int i=0;i<size;i++){
    cout<<array[i]<<" ";
  }

  cout<<endl;
}


//合并两个有序数组
//array[left,mid)
//array[mid,right)
void Merge(int *array,int left,int mid,int right ,int* arr){
  int size=right-left;//区间大小

  int _left_index=left; 
  int _right_index=mid;
  int arr_index=0;

  while(_left_index< mid && _right_index < right ){

    if(array[_left_index]<= array[_right_index]){
      arr[arr_index]=array[_left_index];
      _left_index++;
    }else{
      arr[arr_index]=array[_right_index];
      _right_index++;
    }
      arr_index++; 
  }


  //走到这里说明有一个区间的数已经被移动完了
  //需要将另一个区间中的数加到新的空间中
  
  while(_left_index< mid){
    arr[arr_index++]=array[_left_index++];
  }

  while(_right_index< right){
    arr[arr_index++]=array[_right_index++];
  }
  
  for(int i=0;i<size;i++){
    array[left+i]=arr[i];
  }

}

/*非递归版本
 * */
void Merge_Sort(int *array,int size){
   int *arr=new int[size];

   for(int i=1;i<size;i*=2){
     for(int j=0;j<size;j+=2*i){
       int left=j;
       int mid=left+i;
       if(mid>=size){
         continue;
       }

       int right=mid+i;
       if(right>size){
         right=size;
       }
       Merge(array,left,mid,right,arr);
     }
   }

   delete[] arr;
}



//归并排序
//区间为[left,right)
//左闭右开的区间
void _MergeSort(int *array,int left,int right,int *arr){
  if(right==left+1){
    //区间中只剩一个数字
    return;
  }

  if(left>=right){
    //区间内没有数了
    return ;
  }
  
  int mid=(right-left)/2+left;


  //此处的mid+left的原因是
  //可能存在left为非0 的位置开始,则不加left不能得到准确的mid
  
  //区间被分成左右两个小区间
  //[left,mid)
  //[mid,right)
  //先把左右两个小区间进行排序,分治算法,递归解决
  _MergeSort(array,left,mid,arr);
  _MergeSort(array,mid,right,arr);

  //左右两个小区间已经有序了
  //合并两个有序数组
  Merge(array,left,mid,right,arr);
}

//归并排序
void MergeSort(int *array,int size){

  //让所有的排序在一个固定的区间中执行
  int* arr=new int[size];
  _MergeSort(array,0,size,arr);
  delete[] arr;
}
