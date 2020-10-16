#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


int main(){
  int fd[2];
  int ret=pipe(fd);
  if(ret<0){
    perror("pipe!");
    exit(1);
  }

  pid_t pid=fork();

  if(pid<0){
    perror("fork!");
    exit(1);
  }else if(pid==0){
    sleep(2);
    close(fd[1]);
    char buf[1024]={0};
    ret=read(fd[0],buf,sizeof(buf)-1);
    if(ret<0){
      perror("read");
      exit(1);
    }

    write(STDOUT_FILENO,buf,sizeof(buf));
  }else{
    sleep(1);
    close(fd[0]);
    char buf[1024]="1234";
    ret=write(fd[1],buf,sizeof(buf));
    if(ret<0){
      perror("write!");
      exit(1);
    }
  }

  close(fd[0]);
  close(fd[1]);
  return 0;
}

