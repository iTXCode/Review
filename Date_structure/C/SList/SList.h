#pragma  once 
#include<stdio.h>

typedef int SLDateType;

typedef struct SLNode{
  SLDateType _value;
  struct SLNode *_next;
}SLNode;

typedef struct SList{
  SLNode* _head;
}SList;

//初始化

void SListInit(SList* list);

//销毁过程
void SListDestory(SList* list);

//【增】
//头插
void SList_PushFront(SList* list, SLDateType value);

//尾插
void SList_PushBack(SList* list,SLDateType value);

//【删】
//头删
void SList_PopFront(SList* list);

//尾删
void SList_PopBack(SList* list);


//打印
void SList_Print(const SList* list);

//查
SLNode* SList_Find(const SList* list,SLDateType value);

//【改】

void SListNode_Update(SLNode* node,SLDateType value);

//指定位置插入元素

void SListInsertAfter(SLNode* pos,SLDateType value);

//删除给定 pos 位置后面的结点
void SListEraseAftre(SLNode* pos);


//指定位置pos前面插入新的结点
void SListInsertBefore(SList* list,SLNode *pos,SLDateType value);


