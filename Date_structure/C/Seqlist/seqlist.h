#pragma once 
#include<stdio.h>
#include<stdbool.h>

typedef int SDateType;

typedef struct SeqList{
 SDateType _size;
 SDateType _capacity;
 SDateType* array; 
}SeqList;

//用于初始化顺序表
void SeqListInit(SeqList* seqlist,int capacity);


int SeqListCapacity(SeqList * seqlist);
//销毁顺序表

void SeqListDestory(SeqList* seqlist);
//【增】

//头插
void SeqListPushFront(SeqList* seqlist,SDateType value);

//尾插
void SeqListPushBack(SeqList* seqlist,SDateType value);

//插入
void SeqListInsert(SeqList* seqlist,int pos,SDateType value);

//【删】

//尾删
void SeqListPopBack(SeqList* seqlist);


//头删
void SeqListPopFront(SeqList* seqlist);


//删除指定位置的数据

void SeqListErase( SeqList *seqlist,int pos);

//打印

void SeqListPrint(const SeqList* seqlist);

//修改pos所在下标的数据为value

void SeqListModify(SeqList* seqlist,int pos,SDateType value);

//查找
int SeqListFind(const SeqList* seqlist,SDateType value);

//找到并删除第一个遇到的value
void SeqListRemove(SeqList* seqlist,SDateType value);


//判断顺序表是否为空
bool SeqListEmpty(const SeqList* seqlist);

//返回数据个数
int SeqListSize(const SeqList *seqlist);

//删除所有需要的value值
void SeqListRemoveAll(SeqList* seqlist,SDateType value);
