#include"DList.h"
void TestDList(){
  DList dlist;
  DListInit(&dlist);
  DList_PushFront(&dlist,520);
  DList_PushFront(&dlist,520);
  DList_PushFront(&dlist,520);
  DList_PushFront(&dlist,520);
  DList_PushFront(&dlist,520);
  DList_PushBack(&dlist,1314);
  DList_PushFront(&dlist,520);
  DList_PushBack(&dlist,1314);
  DList_PushFront(&dlist,520);
  DList_PushBack(&dlist,1314); 
  DList_Print(&dlist);

  DList_PopFront(&dlist);
  DList_Print(&dlist);
  DList_PopBack(&dlist);
  DList_Print(&dlist);

  DLNode* pos=DListFind(&dlist,1314);

  printf("所找的值为:%d\n",pos->_value);
  DList_Insert(pos,1234);
  DList_Print(&dlist);

  DList_Erase(pos);
  DList_Print(&dlist);

  DListRemove(&dlist,1234);
  DList_Print(&dlist);

  DListRemoveAll(&dlist,520);
  DList_Print(&dlist);
  DListDestory(&dlist);
}

int main(){
  TestDList();
  return 0;
}
