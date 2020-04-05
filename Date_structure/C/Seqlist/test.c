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
  printf("seqlist->_capacity:%d\n",n);
}

int main(){
  TestSeqlist();
  return 0;
}
