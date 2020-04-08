#include"DList.h"
#include<assert.h>
#include<stdlib.h>

DListNode* DList_BuyNode(DLDateType value){
  DListNode* ptr=(DListNode*)malloc(sizeof(DListNode));
  ptr->_value=value;
  ptr->_prev=ptr->_next=NULL;
  return ptr;
}
void DList_Init(DList* dlist){
  assert(dlist!=NULL);
  dlist->_head=DList_BuyNode(0);
  //头结点不用于真实的存储
  dlist->_head->_next=dlist->_head;
  dlist->_head->_prev=dlist->_head;
}

void DList_Clear(DList* dlist){
  assert(dlist!=NULL);
  //清除所有除头结点以外的结点
  DListNode* cur=dlist->_head->_next;
  DListNode* next=cur;

  while(cur!=dlist->_head){
    next=cur->_next;
    free(cur);
    cur=next;
  }
  dlist->_head->_next=dlist->_head->_prev=dlist->_head;
  printf("循环双链表以清空!\n");
}

void DList_Destory(DList* dlist){
  assert(dlist!=NULL);

  DList_Clear(dlist);

  if(dlist->_head->_next!=NULL)
  free(dlist->_head);
  dlist->_head=NULL;

  printf("循环双链表已销毁\n");
}

void DList_PushFront(DList* dlist,DLDateType value){
  assert(dlist!=NULL);

  DListNode* new_node=DList_BuyNode(value);
  DListNode* cur=dlist->_head->_next;

  new_node->_next=cur;
  cur->_prev=new_node;
  dlist->_head->_next=new_node;
  new_node->_prev=dlist->_head;
}

void DList_PushBack(DList* dlist,DLDateType value){
  assert(dlist!=NULL);
  DListNode* new_node=DList_BuyNode(value);

  DListNode* cur=dlist->_head->_next;
  while(cur!=dlist->_head){
    cur=cur->_next;
  }
  new_node->_next=dlist->_head; 
  new_node->_prev=dlist->_head->_prev;
  dlist->_head->_prev->_next=new_node;
  dlist->_head->_prev=new_node; 
}

void DList_PopFront(DList* dlist){
  assert(dlist!=NULL);
  DListNode * cur=dlist->_head->_next;
  if(cur->_next==dlist->_head){
    //只有一个结点
    free(cur);
    dlist->_head->_next=dlist->_head;
    return ;
  }
  //有两个以上的结点
  DListNode* next=cur->_next;
  free(cur);
  dlist->_head->_next=next;

  next->_prev=dlist->_head;
}

void DList_PopBack(DList* dlist){
  assert(dlist!=NULL);

  //如果链表中没有结点
  if(dlist->_head->_next==dlist->_head){
    return;
  }
  //如果链表中只有一个结点
  DListNode* cur=dlist->_head->_next;
  if(cur->_next==dlist->_head){
    free(cur);
    dlist->_head->_next=dlist->_head;
    dlist->_head->_prev=dlist->_head;
    return;
  }

  //有两个结点及往上的结点
  while(cur->_next!=dlist->_head){
    cur=cur->_next;
  } 

  DListNode* prev=cur->_prev;
  free(cur);
  prev->_next=dlist->_head;
  dlist->_head->_prev=prev;
}

bool DList_Empty(const DList* dlist){
  assert(dlist!=NULL);
  if(dlist->_head->_next==dlist->_head)
    return true;
  return false;
}

DListNode* DList_Find(const DList* dlist,DLDateType value){
  assert(dlist!=NULL);

  DListNode* cur=dlist->_head->_next;
  while(cur!=dlist->_head){
    if(cur->_value==value){
      return cur;
    }
    cur=cur->_next;
  }
  //没有找到的情况 
  return NULL;
}




//插
//往pos的前面进行插入

void DList_Insert(DListNode* pos,DLDateType value){
  DListNode* new_node=DList_BuyNode(value);

  DListNode* prev=pos->_prev; 

  new_node->_next=pos;
  pos->_prev=new_node;
  prev->_next=new_node;
  prev=new_node->_prev;
}

//删除pos位置的结点

void DList_Erase(DListNode* pos){
  DListNode* prev=pos->_prev;
  DListNode* next=pos->_next;
  prev->_next=next;
  next->_prev=prev;
  free(pos);
}

void DList_Romove(DList* dlist,DLDateType value){
  //删除遇到的值为value的特定结点
  
  assert(dlist!=NULL);
  DListNode* cur=dlist->_head->_next;

  while(cur!=dlist->_head){
    if(cur->_value==value){
      DList_Erase(cur);
      return;
    }
    cur=cur->_next;
  }
}

void DList_RemoreAll(DList* dlist,DLDateType value){
  assert(dlist!=NULL);
  DListNode* cur=dlist->_head->_next;

  while(cur!=dlist->_head){
    if(cur->_value==value){
      DList_Erase(cur);
    }
    cur=cur->_next;
  }
}

//打印
void DList_Print(const DList* dlist){
  assert(dlist!=NULL);

  DListNode* cur=dlist->_head->_next;
  while(cur!=dlist->_head){
    printf("%d-->",cur->_value);
    cur=cur->_next;
  }
  printf("\n");
}
