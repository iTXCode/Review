#include<stdio.h>

typedef struct Stack{
  int array[100];
  int top;
}Stack; 


//初始化栈

void StackInit(Stack *stack){
  stack->top=0;
}

//压栈(顺序表的尾端插入)
//先进后出

void StackPush(Stack* stack,int value){

  if(stack->top==100){
    printf("提示栈已经饱和,不能继续往其中添加内容\n");
    return; 
  }

  stack->array[stack->top]=value;
  stack->top++;
}

void StackPop(Stack *stack){
  stack->top--;
}


int StackTop(Stack *stack){
  return stack->array[stack->top];
}

int  StackEmpty(Stack *stack){
  return stack->top==0?1:0;
}

void StackPrint(Stack* stack){
  if(stack->top==0){
    return; 
  }

  for(int i=stack->top-1;i>=0;--i){
    printf("%d ",stack->array[i]);
  }
  printf("\n");
}

//获取size
int StackSize(const Stack* stack){
  return stack->top; 
}

int main(){
  Stack stack;
  StackInit(&stack);
  StackPush(&stack,1);
  StackPush(&stack,2);
  StackPrint(&stack);
  return 0;
}
