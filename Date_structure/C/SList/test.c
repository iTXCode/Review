#include"SList.h"

void TestSList(){
  SList list;
  SListInit(&list);
  SList_PushFront(&list,1);
  SList_PushFront(&list,2);
  SList_PushFront(&list,3);
  SList_PushFront(&list,4);
  SList_PushFront(&list,5);
  SList_PushBack(&list,2);
  SList_PushBack(&list,520);
  SLNode* node=SList_Find(&list,520);

  SList_Print(&list);
  printf("所要查找的内容值:%d\n",node->_value);
  SList_PopFront(&list);
  SList_Print(&list);
 
  SList_PopBack(&list);
  SList_Print(&list);

  SListNode_Update(list._head,520);

  SList_Print(&list);
  SLNode* pos=SList_Find(&list,520);
  SListInsertAfter(pos,1314);
  SList_Print(&list);

  SListInsertBefore(&list,pos,666);
  SList_Print(&list);

  SListEraseAftre(pos);
  SList_Print(&list);
  SLNode* pos1=SList_Find(&list,520);
  SListInsertBefore(&list,pos1,1314);
  SList_Print(&list);
}

int main(){
  TestSList();
  return 0;
}
