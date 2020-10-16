#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

int main(){
  int  fd=open("./file.txt",O_WRONLY);
  if(fd<0){
     perror("open!");
     return 1;
  }


  char buf[1024]={"将军的荣耀!\n"};
  ssize_t n=write(fd,buf,strlen(buf));
  if(n<0){
    perror("write!");
    return 1;
  }
  buf[n]='\0';
  printf("%s",buf);;
  close(fd);
  return 0;
}
