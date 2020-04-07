#include<stdio.h>

typedef int DListType;

typedef struct DLNode{
  DListType _value;
  struct DLNode* _prev;
  struct DLNode* _next;
}DLNode;


typedef struct DList{
  DLNode* _head;
}DList;

//初始化
void DListInit(DList* dlist);

//销毁
//1.清空链表

void DListClear(DList* dlist);

//2.彻底的清空链表,彻底销毁
void DListDestory(DList* dlist);

//【增】
//头插


void DList_PushFront(DList* dlist , DListType value);

//尾插
void DList_PushBack(DList* dlist,DListType value);

//【删】
//头删

void DList_PopFront(DList* dlist);

//尾删
void DList_PopBack(DList* dlist);


//【查】

DLNode* DListFind(DList* dlist,DListType value);

//【插入】
//在pos的前面进行插入

void DList_Insert(DLNode* pos,DListType value);

//删除pos位置的结点
void DList_Erase(DLNode* pos);

void DListRemove(DList* dlist,DListType value);


void DListRemoveAll(DList *dlist,DListType value);
//打印
void DList_Print(DList* dlist);
