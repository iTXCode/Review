#include"myshm.h"

int main(){
  //1.打开/创建内存共享对象
  int shmid=CreateShm();
  
  //2.附加到共享内存对象上
  char* p=(char*)shmat(shmid,NULL,0);
  printf("reader: %s\n",p);
  return 0;
}
