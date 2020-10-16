#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string>
using namespace std;

int main(){
  pid_t pid;
  pid=fork();
  int status;
  if(pid>0){
    wait(&status);
    if(WIFEXITED(status)){
      cout<<WEXITSTATUS(status)<<endl;
    }
    printf("I'm father!,pid=%d,ppid=%d\n",getpid(),getppid());
    while(1){
      sleep(1);
    }
  }else if(pid==0){
    printf("I'm child!,pid=%d,ppid=%d\n",getpid(),getppid());
    char *str="1234";
    str[0]='a';
  }
  return 0;
}
