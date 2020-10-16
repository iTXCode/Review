#include<iostream>
#include<unistd.h>

int main(){
  pid_t pid;
  pid=fork();
  if(pid<0){

    perror("fork!");
    exit(1);
  }else if(pid>0){
    
    while(1)
    {  printf("father!,pid=%d,ppid=%d\n",getpid(),getppid());
      sleep(2); }
  }else{
    printf("child!\n,pid=%d,ppid=%d\n",getpid(),getppid());
    sleep(10);
    printf("----child die!----\n");
  }
  return 0;
}
