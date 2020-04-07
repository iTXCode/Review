#include"seqlist.h"

void TestSeqlist(){
  SeqList seqlist;
  SeqListInit(&seqlist,100);
  for(int i=0;i<101;i++)
  { 
    SeqListPushFront(&seqlist,i); 
  }

  SeqListPrint(&seqlist);
  int n=   SeqListSize(&seqlist);
  printf("seqlist->_size:%d\n",n);
  printf("seqlist->_capacity:%d\n",SeqListCapacity(&seqlist));

  SeqListPushBack(&seqlist,520);
  SeqListPrint(&seqlist);

  SeqListPopBack(&seqlist);
  SeqListPopFront(&seqlist);
  SeqListPrint(&seqlist);

  int pos=SeqListFind(&seqlist,99);
  printf("pos=%d\n",pos);

  SeqListInsert(&seqlist,pos,520);
  SeqListPrint(&seqlist);


  SeqListErase(&seqlist,pos);
  SeqListPrint(&seqlist);
  
  SeqListModify(&seqlist,pos,520);
  SeqListPrint(&seqlist);

  SeqListRemove(&seqlist,98);
  SeqListPrint(&seqlist);

  SeqListDestory(&seqlist);
  SeqListPrint(&seqlist);
}

int main(){
  TestSeqlist();
  return 0;
}
