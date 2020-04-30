#include<stdio.h>
#include<stdlib.h>

typedef int Type; 
typedef  struct StackNode{
  Type _data;
  struct StackNode *_next;
}Node; 

typedef struct Stack{
  Node* _top;
  Node* _end;
  int _size; 
}Stack;

void StackInit(Stack *stack){
  stack->_top=stack->_end=NULL;
  stack->_size=0;
}

void Push(Stack* stack,Type value){
  if(stack->_top == NULL){  
    stack->_top =(Node*)malloc(sizeof(Node));
    stack->_top->_data=value;
    stack->_top->_next=NULL;
    stack->_end=stack->_top;
    stack->_size++;
    return; 
  }
  
  //非第一次插入
  Node* newNode=(Node*)malloc(sizeof(Node));
  newNode->_data=value; 
  newNode->_next=NULL;
  stack->_top->_next=newNode;
  stack->_top=newNode;
  stack->_size++;
}

void Pop(Stack* stack){
  if(stack->_top==NULL){
    return;
  }

  if(stack->_top==stack->_end){
    free(stack->_top);
    stack->_end=stack->_top=NULL;
    stack->_size--;
    return;
  }

  Node* cur=stack->_end; 
  while(cur->_next!=stack->_top){
    cur=cur->_next; 
  }
  cur->_next=NULL;
  free(stack->_top);
  stack->_top=cur;
  stack->_size--;
}

Type StackTop(const Stack* stack){
  return stack->_top->_data;
}

int Empty(Stack* stack){
  if(stack->_size==0)
    return 0;
  return 1;
}

int StackSize(Stack *stack){
  return stack->_size; 
}
void StackPrint(Stack* stack){
  if(stack==NULL){
    return; 
  }
  if(stack->_end==stack->_top&&stack->_top==NULL){
    printf("栈已为空\n");
    return;
  }
  Node* cur=stack->_end;
  while(cur){
    printf("%d->",cur->_data);
    cur=cur->_next; 
  }
  printf("\n");
}


void Test(){
  Stack stack;
  StackInit(&stack);
  Push(&stack,1);
  Push(&stack,2);
  int size=StackSize(&stack);
  printf("%d\n",size);
  StackPrint(&stack);

  Pop(&stack);
  printf("%d\n",StackSize(&stack));
  StackPrint(&stack); 
  Pop(&stack);
  StackPrint(&stack);
}

int main(){
  Test();
}
