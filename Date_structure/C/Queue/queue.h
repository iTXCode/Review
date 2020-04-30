#include<stdio.h>
#include<stdlib.h>

typedef int Type;
typedef struct QueueNode{
  Type _data;
  struct QueueNode *_next;
}Node;

typedef struct Queue{
  Node* _front;//记录队列首端的位置
  Node* _rear;//记录队列尾端的位置
  Type _size;//记录队列中有效元素的个数
}Queue;

void QueueInit(Queue* queue){
  queue->_front=queue->_rear=NULL;
  queue->_size=0;
}

void QueueDestory(Queue* queue){
  Node* cur=queue->_front;
  Node* next=NULL;
  while(cur){
    next=cur->_next;
    free(cur);
    cur=next;
  }

  queue->_front=queue->_rear=NULL;
  queue->_size=0;
}
Node* BuyQueueNode(Type data){
  Node* newNode=(Node*)malloc(sizeof(Node));
  newNode->_data=data;
  newNode->_next=NULL;
  return newNode;
}
void QueuePush(Queue* queue, Type data){

  Node* new_node=BuyQueueNode(data);
  if(queue->_front==NULL& queue->_rear==NULL){
    //第一次插入

    queue->_rear=new_node;
    queue->_rear=new_node;
    queue->_front=queue->_rear;
    queue->_size++;
    return ;
  }


  //非的第一次插入
  queue->_rear->_next=new_node;
  queue->_rear=new_node;
  queue->_size++;
}


void QueuePop(Queue* queue){

  //处理只有一个结点的时候
  if(queue->_front==queue->_rear&&queue->_front!=NULL){
    free(queue->_front);
    queue->_front=queue->_rear=NULL;
    queue->_size=0;
    return;
  }

  Node* cur=queue->_front->_next;
  
  free(queue->_front);
  queue->_front=cur;
  queue->_size--;
}

Type QueueFront(Queue* queue){
  //取队首元素
  if(queue->_front==NULL){
    printf("队列的头部元素为空\n");
    return 0;
  }
  
  return queue->_front->_data;
}
Type QueueBack(Queue* queue){
  //返回队列尾部元素
  
  //首先需要确定队列尾部元素是否存在
  if(queue->_rear==NULL){
    printf("队列尾部元素不存在\n");
  }

  return queue->_rear->_data;
}
int QueueEmpty(Queue* queue){
  return queue->_size==0?0:1;
} 
int QueueSize(Queue* queue){
  
  return queue->_size;
} 

void Queue_Print(Queue* queue){
  if(queue->_front==NULL){

    printf("队列已为空!\n");
    return;
  }
  Node* cur=queue->_front;
  while(cur){
    printf("%d ",cur->_data);
    cur=cur->_next;
  }
  printf("\n");
}

