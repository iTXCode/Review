#include"DList.h"
#include<stdlib.h>
#include<assert.h>

DLNode* BuyDLNode(DListType value){
  DLNode* ptr=(DLNode*)malloc(sizeof(DLNode));
  ptr->_value=value;
  ptr->_prev=NULL;
  ptr->_next=NULL;
  return ptr;
}

//初始化
void DListInit(DList* dlist){
  assert(dlist!=NULL);
  dlist->_head=BuyDLNode(0); 
}
//销毁
//1.清空链表

void DListClear(DList* dlist){
  assert(dlist!=NULL);

  DLNode* cur=dlist->_head->_next;
  DLNode* next=cur;


  while(cur!=NULL){
    free(cur);
    next=next->_next;
    cur=next; 
  }
  dlist->_head->_next=dlist->_head->_prev=NULL;
  printf("非循环双链表已清空!\n");
}

//2.彻底的清空链表,彻底销毁
void DListDestory(DList* dlist){
  assert(dlist!=NULL);
  DListClear(dlist);
  free(dlist->_head);
  dlist->_head=NULL;
  printf("非循环双链表已销毁!\n");
}

//【增】
//头插


void DList_PushFront(DList* dlist , DListType value){
  assert(dlist!=NULL);
  DLNode* new_node=BuyDLNode(value);
  DLNode* cur=dlist->_head;
  new_node->_next=cur->_next;
  if(cur->_next!=NULL){
    cur->_next->_prev=new_node;
  }  
  
  new_node->_prev=cur;
  dlist->_head->_next=new_node;
}
//尾插
void DList_PushBack(DList* dlist,DListType value){
  assert(dlist!=NULL);
  DLNode* new_node=BuyDLNode(value);
  DLNode* cur=dlist->_head->_next;
  while(cur->_next!=NULL){
    cur=cur->_next;
  }
  cur->_next=new_node;
  new_node->_prev=cur;
}

//【删】
//头删

void DList_PopFront(DList* dlist){
  assert(dlist!=NULL);
  DLNode* cur=dlist->_head->_next;
  dlist->_head->_next=cur->_next;
  cur->_next->_prev=dlist->_head;
  free(cur);
}

//尾删
void DList_PopBack(DList* dlist){
  assert(dlist!=NULL);
  DLNode* cur=dlist->_head->_next;

  while(cur->_next->_next!=NULL){
    cur=cur->_next;
  }
  
  free(cur->_next);
  cur->_next=NULL;

}


//【查】

DLNode* DListFind(DList* dlist,DListType value){
  assert(dlist!=NULL);
  DLNode* cur=dlist->_head->_next;

  while(cur!=NULL){
    if(cur->_value==value){
      return cur;
    }
    cur=cur->_next;
  }

  return NULL;
}

//【插入】
//在pos的前面进行插入

void DList_Insert(DLNode* pos,DListType value){

  DLNode* prev=pos->_prev;
  DLNode* cur=BuyDLNode(value);
  cur->_next=pos;
  pos->_prev=cur;
  cur->_prev=prev;
  prev->_next=cur;
}

//删除pos位置的结点
void DList_Erase(DLNode* pos){
  DLNode* prev=pos->_prev;
  DLNode* next=pos->_next;

  prev->_next=next;
  next->_prev=prev;

  free(pos);
}

void DListRemove(DList* dlist,DListType value){
  assert(dlist!=NULL);
  DLNode* cur=dlist->_head->_next;
  DLNode* next=cur->_next;
  while(cur!=NULL){
    if(cur->_value==value){
      DList_Erase(cur);
      return;
    }
    cur=next;
    next=cur->_next;
  }
}

void DListRemoveAll(DList* dlist,DListType value){
  assert(dlist!=NULL);
   
  DLNode* cur=dlist->_head->_next;
  DLNode* next=cur;

  while(cur!=NULL){
    next=next->_next;
    if(cur->_value==value){
      DList_Erase(cur);
    }
    cur=next;
  }
}


//打印
void DList_Print(DList* dlist){
  assert(dlist!=NULL);
  DLNode* cur=dlist->_head->_next;
  DLNode* next=cur;
  while(cur!=NULL){
    next=next->_next;
    printf("%d-->",cur->_value);
    cur=next;
  }
  printf("\n");
}
