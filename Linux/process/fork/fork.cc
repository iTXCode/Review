#include<iostream>
#include<unistd.h>

int global=0;
int main(){
  int i=0;
  pid_t pid;

  for( i=0;i<5;i++){
    pid=fork();

    if(pid>0){
      global=55;
      printf("I'm father! pid=%d,ppid=%d\n,global=%d\n",getpid(),getppid(),global);
      break;
    }else if(pid==0){
      global=300;
      printf("I'm child! pid=%d,ppid=%d\n,global=%d\n",getpid(),getppid(),global);
    break;
    }else{
      perror("fork!");
    }
  }
  return 0;
}
