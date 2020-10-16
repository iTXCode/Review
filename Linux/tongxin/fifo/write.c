#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>

int main(){
  int fd=open("./pipe",O_WRONLY);
  if(fd<0){
    perror("open!");
    exit(1);
  }

  while(1){
    printf("->");
    fflush(stdout);
    char buf[1024]={0};
    read(0,buf,sizeof(buf)-1);
    int ret=write(fd,buf,strlen(buf));
    if(ret<0){
      perror("write!");
      exit(1);
    }
  }
  close(fd);
  return 0;
}
