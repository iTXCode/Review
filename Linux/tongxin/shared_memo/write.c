#include"myshm.h"
#include<string.h>

int main(){
  //1.创建/打开共享内存对象
  int shmid=CreateShm();
  //2.附加到共享内存对象上
  char* p=(char*)shmat(shmid,NULL,0);
  //3.直接使用
  strcpy(p,"hehe\n");
  return 0;
}
