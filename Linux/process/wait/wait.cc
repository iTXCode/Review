#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
using namespace  std;

int main(int argc,char* argv[]){
  pid_t pid;
  pid_t wpid;
  int i;
  int n=5;
  if(argc==2){
    n=atoi(argv[1]);
  }
  for( i=0;i<5;i++){
    pid=fork();
    if(pid==0){
      break;
    }
  }

  if(n==i){
    sleep(n);
    printf("I'm father,pid=%d,ppid=%d\n",getpid(),getppid());
    //while(wait(NULL));
    while(waitpid(-1,NULL,0));
    while(1){
      sleep(1);
    }
  }else{
    sleep(i);
    printf("I'm child%d,pid=%d,ppid=%d\n",i+1,getpid(),getppid());
  } 
  return 0;
}
