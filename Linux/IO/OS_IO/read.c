#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(){
  int fd=open("./myfile.txt",O_RDONLY);

  if(fd<0){
    perror("open!");
    return 1;
  }

  char buf[1024]={0};
  ssize_t n=read(fd,buf,sizeof(buf)-1);
  buf[n]='\0';
  printf("%s\n",buf);
  close(fd);
  return 0;
}
