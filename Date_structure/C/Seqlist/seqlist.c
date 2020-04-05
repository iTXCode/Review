#include"seqlist.h"
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>


//用于初始化顺序表
void SeqListInit(SeqList* seqlist,int capacity){
  assert(seqlist);

  seqlist->array=(int*)malloc(sizeof(SDateType)*capacity);
  seqlist->_size=0;
  seqlist->_capacity=capacity;
}

//销毁顺序表
void SeqListDestory(SeqList* seqlist){
  assert(seqlist!=NULL);
  assert(seqlist->array!=NULL);
  assert(seqlist->_size>0);
  free(seqlist->array);
  seqlist->_size=0;
  seqlist->_capacity=0;
}

//扩容

static void CheckCapacity(SeqList* seqlist){
  assert(seqlist!=NULL);
  assert(seqlist->array!=NULL);
  assert(seqlist->_size<=seqlist->_capacity);

  //检查是否需要扩容
  if(seqlist->_size<seqlist->_capacity){
    return;
  }

  //这里就需要进行扩容了
  //扩容的步骤
  //1.申请一块新的地址空间
  //2.将旧的数据搬到新的地址空间上
  //3.释放原来的地址空间
  //4.将指向旧的地址空间的指针指向新的地址空间
  
  SDateType capacity=2*seqlist->_capacity;
  SDateType* new_array=(SDateType*)malloc(sizeof(SDateType)*capacity);

  //进行数据的搬移
  for(int i=0;i<seqlist->_size;i++){
    new_array[i]=seqlist->array[i];
  }

  seqlist->_capacity=capacity;
  //释放原来的空间
  free(seqlist->array);
  seqlist->array=new_array;
}

//【增】

//头插
void SeqListPushFront(SeqList* seqlist,SDateType value){
  assert(seqlist!=NULL);
  assert(seqlist->array!=NULL);

  //需要检查是否需要扩容
  CheckCapacity(seqlist);

  //已经进行了扩容或者不需要扩容
  //
  //将原来空间内的数据往后搬移
  
  for(int i=seqlist->_size;i>=0;i--){
    seqlist->array[i]=seqlist->array[i-1];
  }
  seqlist->array[0]=value;
  seqlist->_size++;
}

//尾插
void SeqListPushBack(SeqList* seqlist,SDateType value){
  assert(seqlist!=NULL);
  assert(seqlist->array!=NULL);

  //检查是否需要扩容
  CheckCapacity(seqlist);
  seqlist->array[seqlist->_size]=value;
  seqlist->_size++;
}

//插入
void SeqListInsert(SeqList* seqlist,int pos,SDateType value){
  assert(seqlist!=NULL);
  assert(seqlist->array!=NULL);
  assert(pos>=0&&pos<=seqlist->_size);
  CheckCapacity(seqlist);

  //往后搬移数据
  for(int i=seqlist->_size;i>=pos;i--){
    seqlist->array[i]=seqlist->array[i-1];
  }

  seqlist->array[pos]=value;
  seqlist->_size++;
}
//【删】

//尾删
void SeqListPopBack(SeqList* seqlist){
  assert(seqlist!=NULL);
  assert(seqlist->array!=NULL);

  seqlist->_size--;
}


//头删
//需要将第二个开始往后的所有的元素往前移动一位
void SeqListPopFront(SeqList* seqlist){
  assert(seqlist!=NULL);
  assert(seqlist->array!=NULL);

  for(int i=0;i<seqlist->_size;i++){
    seqlist->array[i]=seqlist->array[i+1];
  }
  seqlist->_size--;
}

//删除指定位置的数据

void SeqListErase( SeqList *seqlist,int pos){
  assert(seqlist!=NULL);
  assert(seqlist->array!=NULL);
  assert(pos>=0&&pos<seqlist->_size);

  for(int i=pos;i<seqlist->_size;i++){
    seqlist->array[i]=seqlist->array[i+1];
  }
  seqlist->_size--;
}

//打印

void SeqListPrint(const SeqList* seqlist){
  assert(seqlist!=NULL);
  assert(seqlist->array!=NULL);

  for(int i=0;i<seqlist->_size;i++){
    printf("%d ",seqlist->array[i]);
  }
  printf("\n");
}

//修改pos所在下标的数据为value

void SeqListModify(SeqList* seqlist,int pos,SDateType value){
  assert(seqlist!=NULL);
  assert(seqlist->array!=NULL);
  assert(pos>=0&& pos<seqlist->_size);

  seqlist->array[pos]=value;
}
//查找
int  SeqListFind(const SeqList* seqlist,SDateType value){
  assert(seqlist!=NULL);
  assert(seqlist->array!=NULL);
  for(int i=0;i<seqlist->_size;i++){
    if(seqlist->array[i]==value){
      return i;
    }
  }
  return -1;
}
//找到并删除第一个遇到的value
void SeqListRemove(SeqList* seqlist,SDateType value){
  assert(seqlist!=NULL);
  assert(seqlist->array!=NULL);
  
  int pos=SeqListFind(seqlist,value);
  if(pos!=-1){
    SeqListErase(seqlist,pos);
  }
}

//判断顺序表是否为空
bool SeqListEmpty(const SeqList* seqlist){
  assert(seqlist!=NULL);
  assert(seqlist->array!=NULL);

  if(seqlist->_size==0){
    return true;
  }
  return false;
}

//返回数据个数
int SeqListSize(const SeqList *seqlist){
  assert(seqlist!=NULL);
  assert(seqlist->array!=NULL);
  return seqlist->_size;
}

//删除所有需要的value值
void SeqListRemoveAll(SeqList* seqlist,SDateType value){
  assert(seqlist!=NULL);
  assert(seqlist->array!=NULL);

  for(int i=0;i<seqlist->_size;i++){
    if(seqlist->array[i]==value){
      SeqListErase(seqlist,i);
    }
  }
}
