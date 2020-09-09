#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void CountSort(int* array,int len){

  int maxValue=0;
  for(int i=0;i<len ;i++){
    maxValue=max(maxValue,array[i]);
  }
  vector<int> memo(maxValue+1,0);
  
  for(int i=0;i<len;i++){
    memo[array[i]]++;
  }
  int index=0;
  for(int i=0;i<=maxValue;i++){  
    while(memo[i]){
      array[index++]=i;
      memo[i]--; 
    }
  }
}

void CountSort1(int* array,int len){
  int minValue=array[0];
  int maxValue=array[0];

  for(int i=0;i<len;i++){
    if(array[i]<minValue){
       minValue=min(array[i],minValue);
    }

    if(array[i]>maxValue){
       maxValue=max(array[i],maxValue);
    }
  }

  int *arr=new int[maxValue-minValue+1];
  int gap=maxValue-minValue;

  for(int i=0;i<len;i++){
    arr[array[i]-minValue]++;
  }
  
  for(int i=1;i<=gap; ++i){
      arr[i]+=arr[i-1];
  }

  int *n_arr=new int[len];
  //从后往前遍历原数组,过程中实现排序
  for(int i=len-1;i>=0;i--){
    n_arr[--arr[array[i]-minValue]]=array[i];
  }

  for(int i=0;i<len;i++){
    array[i]=n_arr[i];
  }

}

void countSort(int index){

}

//基数排序
void CountSort2(int *array,int len){
  int max=array[0];
  for(int i=1;i<len;i++){
    if(array[i]>max){
      max=array[i];
    }
  }

  for(int j=1;j<=max;j*=10){
    countSort(j);
  }
}


int main(){
  int array[]={0,0,3,4,6,3,4,5,7,9,6,7,8,10};
  int len=sizeof(array)/sizeof(array[0]);
  CountSort1(array,len);
  for(int i=0;i<len;i++){
    cout<<array[i]<<" ";
  }
  cout<<endl;
  return 0;
}

