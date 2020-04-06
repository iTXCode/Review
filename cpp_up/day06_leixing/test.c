//#include<stdio.h>
//
//int main(){
//  int a=1;
//  float b=1.0;
//  char c='$';
//  printf("a=%d\n",a);
//  printf("b=%f\n",b);
//  printf("c=%c\n",c);
//  printf("after!\n");
//  a=b;
//  printf("a=%d\n",a);
//  b=c;
//  printf("b=%f\n",b);
//  
//  int *p=&a;
//
// printf("p=%x\n",p);
//  return 0;
//
//}


#include<stdio.h>


int main(){
  int a=20;
  int*p =&a;


  printf("*p=%d\n",*p);
  printf("p=%p\n",p);
  printf("&a=%p\n",&a);

  float b=10;
  int* pb=(int*)&b;
  printf("pb=%p\n",pb);
  printf("&b=%p\n",&b);
  printf("*pb=%d\n",*pb);

  return 0;

}



