#include<iostream>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>


using namespace  std;

int main(){
  int fd[2];
  int ret=pipe(fd);
  //读端和写端
  if(ret==-1){
    perror("pipe!");
    exit(1);
  }

  pid_t pid=fork();

  if(pid==-1){
    perror("fork!");
    exit(1);
  }else if(pid>0){
    //父进程的逻辑写数据
    close(fd[0]);
    char buf[1024]="I'm a man!";
    int n=strlen(buf);
    ret=write(fd[1],buf,n);

    if(ret==0){
      perror("write!");
      exit(1);
    }
    buf[n]='\0';  
  
  }else{
    //子进程的逻辑读数据
    close(fd[1]);
    char buf[1024];
    ret=read(fd[0],buf,sizeof(buf));
    if(ret==0){
      perror("write!");
      exit(1);
    }
   write(STDOUT_FILENO,buf,ret);

  }
  return 0;
}
