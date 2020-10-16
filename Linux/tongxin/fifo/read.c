#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>


int main(){
  int fd=open("./pipe",O_RDONLY);

  if(fd<0){
    perror("open!");
    exit(1);
  }

  while(1){
    char buf[1024]={0};
    ssize_t  ret=read(fd,buf,sizeof(buf)-1);
    if(ret<0){
      perror("read!");
      exit(1);
    }
    if(ret==0){
      printf("read done!\n");
      return  0;
    }
    buf[ret]='\0';
    write(STDOUT_FILENO,buf,strlen(buf));
    
  }
  close(fd);
  return 0;
}
