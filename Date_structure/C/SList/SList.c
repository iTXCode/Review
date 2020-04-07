#include"SList.h"
#include<assert.h>
#include<stdlib.h>
//初始化

void SListInit(SList* list){
  assert(list!=NULL);
  list->_head=NULL;
}

//销毁过程
void SListDestory(SList* list){
  assert(list!=NULL);

  SLNode* cur=list->_head;
  SLNode* next=NULL;

  while(cur!=NULL){
    next=cur->_next;
    free(cur);
    cur=next;
  }
  list->_head=NULL;

  printf("单链表已销毁!\n");
}

//【增】
//头插
void SList_PushFront(SList* list, SLDateType value){
  assert(list!=NULL);

  SLNode* new_node=(SLNode*)malloc(sizeof(SLNode));
  new_node->_value=value;
  new_node->_next=list->_head;
  list->_head=new_node;
}
//尾插
void SList_PushBack(SList* list,SLDateType value){
  assert(list!=NULL);
  SLNode* new_node=(SLNode*)malloc(sizeof(SLNode));
  new_node->_value=value;
  new_node->_next=NULL;
  SLNode* cur=list->_head;
  while(cur->_next!=NULL){
    cur=cur->_next;
  }
  cur->_next=new_node;
}

//【删】
//头删
void SList_PopFront(SList* list){
  assert(list!=NULL);
  SLNode* cur=list->_head;
  list->_head=cur->_next;
  free(cur);
}

//尾删
//
//TODO
void SList_PopBack(SList* list){
  assert(list!=NULL);
  assert(list->_head!=NULL);
  SLNode* cur=list->_head;
  //只有一个结点的时候
  if(cur->_next==NULL){
    free(cur);
    list->_head=NULL;
    return; 
  }
  //拥有两个以上结点的时
  ////拥有两个以上结点的时候候
  while(cur->_next->_next!=NULL){
    cur=cur->_next;
  }
  free(cur->_next);
  cur->_next=NULL;
}

//打印
void SList_Print(const SList* list){
  assert(list!=NULL);

  SLNode* cur=list->_head;
  //如果只有一个结点的时候就打印一个结点
  if(cur->_next==NULL){
    printf("%d\n",cur->_value);
    return;
  }
  //拥有两个以上的结点的时候
  while(cur->_next!=NULL){
    printf("%d-->",cur->_value);
    cur=cur->_next;
  }

  printf("%d\n",cur->_value);
}

//查
SLNode* SList_Find(const SList* list,SLDateType value){
  assert(list!=NULL);
  assert(list->_head!=NULL);

  SLNode* cur=list->_head;

//  //先解决只有一个结点的情况
//  if(cur->_next==NULL){
//    if(cur->_value==value){
//      return cur;
//    }
//  }
//
//  //拥有两个结点以上的情况
//  while(cur->_next!=NULL){
//    if(cur->_value==value){
//      return cur;
//    }
//    cur=cur->_next;
//  }
//
//  if(cur->_value==value)
//    return cur;
//  //走到这里就是没有找到要找的内容 


  while(cur!=NULL){
    if(cur->_value==value){
      return cur;
    }
    cur=cur->_next;
  }

  return NULL;
}
//【改】

void SListNode_Update(SLNode* node,SLDateType value){
  assert(node!=NULL);
  //需要确定所要查找的结点是否在该单链表中
  node->_value=value;
}

//指定位置插入元素

void SListInsertAfter(SLNode* pos,SLDateType value){
  SLNode* new_node=(SLNode*)malloc(sizeof(SLNode));
  new_node->_value=value;
  SLNode* next=pos->_next;
  pos->_next=new_node;
  new_node->_next=next;
}

//删除给定 pos 位置后面的结点
void SListEraseAftre(SLNode* pos){
  SLNode* cur=pos->_next;
  pos->_next=pos->_next->_next;
  free(cur);
}


//指定位置pos前面插入新的结点
void SListInsertBefore(SList* list,SLNode *pos,SLDateType value){
  assert(list!=NULL);
  SLNode* cur=list->_head;

  //需要先确定所要插入位置是否为头结点
  if(pos==list->_head){
    SList_PushFront(list,value);
    return;
  }
  SLNode* new_node=(SLNode*)malloc(sizeof(SLNode));
  new_node->_value=value;
  while(cur->_next!=pos){
    cur=cur->_next;
  }
  cur->_next=new_node;
  new_node->_next=pos;
}

