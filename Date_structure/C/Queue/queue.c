#include"queue.h"

void TestQueue(){
  Queue queue;
  QueueInit(&queue);
  QueuePush(&queue,1);
  QueuePush(&queue,2);
  Queue_Print(&queue);
  QueuePop(&queue);
  Queue_Print(&queue);

  printf("队首元素:%d\n",QueueFront(&queue));
  printf("队尾元素:%d\n",QueueBack(&queue));
  QueuePop(&queue);
  Queue_Print(&queue);
}


int main(){
  TestQueue();
  return 0;
}
