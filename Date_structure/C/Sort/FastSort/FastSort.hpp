#include<iostream> 

using namespace std; 

void Swap(int *a,int *b){
  int tmp=*a;
  *a=*b;
  *b=tmp;
}

void PrintArray(int *array,int size){
  for(int i=0;i<size;i++){
    cout<<array[i]<<" ";
  }
  cout<<endl;
}

int Partion(int* array,int left,int right){
  int begin=left;
  int end=right;  //不能从right-1开始

  while(begin<end){
    while(begin<end && array[begin]<=array[right]){
      begin++;
      //在遍历过程中对大于基准值的元素进行定位
      //此处的array[begin]<=array[right]中的"=" 必须存在
      //如果不存在的话会造成基准值右边区间的死循环
    }
    

    while(begin<end && array[end]>=array[right]){
      end--;
      //在遍历过程中对小于基准值的元素进行定位
    }

    if(begin!=end){  
      Swap(array+begin,array+end); 
    }//当begin和end两个数相同的时候,两者指向相同的值,所以不需要交换
  }

  Swap(array+begin,array+right);
    //返回当前基准值所在位置,
    return begin;
}


void _QuickSort(int *array,int left,int right){
 //终止条件:size==0 || size==1
 //left ==right 区间内还剩一个数
 //left > right 区间内没有数
  if(left==right){
    return ;
  }
  if(left>right){
    return;
  }

  int div;//比基准值小的放其左边,大的放到后面去,基准值所在的下标
  div=Partion(array,left,right);//遍历array[left,right]区间,把夏普的放左,大的放右面
  _QuickSort(array,left,div-1);//分治解决左边的小区间
  _QuickSort(array,div+1,right);//分治解决右边的小区间
}

//快速排序
//要排序的区间是array[left,right]

void QuickSort(int* array,int size){
  _QuickSort(array,0,size-1);
}
