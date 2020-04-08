#include"DList.h"

void TestDLoopList(){
  DList dlist;
  DList_Init(&dlist);

  DList_PushFront(&dlist,520);
  DList_PushFront(&dlist,520);
  DList_PopFront(&dlist);
  DList_Print(&dlist);
  DList_PushFront(&dlist,520);
  DList_PushFront(&dlist,520);
  DList_PushFront(&dlist,520);
  DList_PushFront(&dlist,520);
  DList_PushFront(&dlist,520);
  DList_PushFront(&dlist,520);
  DList_PushFront(&dlist,520);
  DList_PushFront(&dlist,520);
  DList_PushFront(&dlist,520);  
  DList_Print(&dlist);

  printf("尾插\n");
  DList_PushBack(&dlist,1314);
  DList_PopFront(&dlist);
  DList_Print(&dlist);
  DList_PushBack(&dlist,1314);
  DList_PushBack(&dlist,1314);
  DList_PushBack(&dlist,1314);
  DList_PushBack(&dlist,1314);
  DList_PushBack(&dlist,1314);
  DList_Print(&dlist);
  printf("尾删\n");
  DList_PopBack(&dlist);
  DList_Print(&dlist);

  printf("查找\n");
  DListNode* pos=DList_Find(&dlist,1314);
  printf("所要查找的值=%d\n",pos->_value);

  DList_Insert(pos,1234);
  DList_Print(&dlist);

  DList_Erase(pos);
  DList_Print(&dlist);

  DList_Romove(&dlist,520);
  DList_Print(&dlist);

  DList_RemoreAll(&dlist,520);
  DList_Print(&dlist);
  DList_Destory(&dlist);
}

int main(){
  TestDLoopList();
  return 0;
}
