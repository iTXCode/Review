///////////////
//创建内存共享对象
///////////////////////////////// 

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/shm.h>


int main(){
  key_t key=ftok(".",0x1);
  if(key==-1){
    perror("ftok!");
    return 1;
  }
  printf("key=%d\n",key);
  int ret=shmget(key,1024,IPC_CREAT | IPC_EXCL);
  if(ret<0){
    perror("shmget!");
    return 1;
  }

  printf("ret=%d\n",ret);
  return 0;
}
