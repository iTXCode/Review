#include<iostream>
#include<unistd.h>

int main(){
  pid_t pid;
  int i=0;
  for(i=0;i<5;i++){
    pid=fork();
    if(pid==0){
      break; 
    }
  }

  sleep(i);

  if(i<5){
    printf("I'm child!,pid=%d,ppid=%d\n",getpid(),getppid());
  }else{
    printf("I'm father!\n");
  }
  return 0;
}
