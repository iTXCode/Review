#pragma  once
#include<stdio.h>
#include<stdbool.h>
typedef int DLDateType;

typedef struct DListNode{
  DLDateType _value;
  struct DListNode* _prev;
  struct DListNode* _next;
}DListNode;


typedef struct DList{
  DListNode* _head;
}DList;

void DList_Init(DList* dlist);

void DList_Clear(DList* dlist);

void DList_Destory(DList* dlist);

void DList_PushFront(DList* dlist,DLDateType value);

void DList_PushBack(DList* dlist,DLDateType value);

void DList_PopFront(DList* dlist);

void DList_PopBack(DList* dlist);

bool DList_Empty(const DList* dlist);

DListNode* DList_Find(const DList* dlist,DLDateType value);

DListNode* DList_BuyNode(DLDateType value);


//插
//往pos的前面进行插入

void DList_Insert(DListNode* pos,DLDateType value);

//删除pos位置的结点

void DList_Erase(DListNode* pos);

void DList_Romove(DList* dlist,DLDateType value);

void DList_RemoreAll(DList* dlist,DLDateType value);

//打印
void DList_Print(const DList* dlist);
