#include<iostream>
#include<stack>

using namespace std;

void Swap(int* a,int* b){
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


int Partition(int* array,int left,int right){
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

void _QuickSort(int* array,int left,int right){
  stack<int> s;
  s.push(right);
  s.push(left);

  while(!s.empty()){
    int _left=s.top();
    s.pop();
    int _right=s.top();
    s.pop();

    if(_left>=_right){
      continue; 
    }

    int div=Partition(array,_left,_right);

    //div+1 right
    s.push(_right);
    s.push(div+1);
    //_left,div -1
    s.push(div-1);
    s.push(_left);
  }
}

void QuickSort(int* array,int size){
  _QuickSort(array,0,size-1);
}

