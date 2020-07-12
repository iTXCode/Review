//#include<stdio.h>
//int main() { 
//int i = 0;
//int a=0;
//int b=2;
//int c=3;
//int  d=4; 
////i = a++ && ++b && d++; 
//i = a++||++b||d++; 
//printf("i=%d\n a = %d\n b = %d\n c = %d\nd = %d\n&quo",i, a, b, c, d); 
//return 0; 
//}


//#include<stdio.h>
//
//int fun(){
//  static int num=1;
//  return ++num;
//}
//
//int main(){
//  int count=0;
//  count=fun()+fun()*fun();
//  printf("%d\n",count);
//  return 0;
//}


//#include<stdio.h>
//
//int main(void) {
//  printf("%s , %5.3s\n","computer","computer"); 
//  return 0;
//}


//#include<stdio.h>
//char* q=NULL;
//
//void Fun(){
//  char a[]="abc";
//  q=a;
//
//  printf("%s\n",q);
//
//
//}
//
//int main(){
//  Fun();
//  printf("%s\n",q);
//
//  return 0;
//}


//#include<stdio.h>
//
//
//int main(){
//  int *p[4];
//  int (*q)[4];
//  int val=10;
//  p[0]=&val;
//
// printf("%p",p[0]);
// printf("%p",q);
//
//  return 0;
//}


//#include<iostream>
//#include<string>
//
//int main(){
//  char acX[]="abc";
//  char acY[]={'a','b','c'};
//  char *szX=acX;
//  char *szY=acY;
//  char  *str1="abc";
//  char *str2="abc";
//  printf("acX=%s\n",acX);
//  printf("sizeof(acX)=%d\n",sizeof(acX));
//  
//  printf("acY=%s\n",acY);
//  printf("sizeof(acY)=%d\n",sizeof(acY));
//  printf("szX=%p\n",szX);
//  printf("szY=%p\n",szY);
//  
//  printf("&str1=%p\n",&str1);
//  std::cout<<"str1="<<str1<<std::endl;
//  printf("&str2=%p\n",&str2);
//  std::cout<<"str2="<<str2<<std::endl;
//  return 0;
//}


//#include<iostream>
//#include<math.h>
//#include<algorithm>
//using namespace std;
//int main(){
//  int num=pow(2,31)-1;
//  int*p =&num; 
//  cout<<num<<endl;
//  long sum=pow(2,33);
//  cout<<sum<<endl;
//  
//  cout<<"*p="<<sizeof(p)<<endl;
//  cout<<sizeof(int)<<endl;
//  cout<<sizeof(long)<<endl;
//  cout<<"sizeof(long long):"<<sizeof(long long)<<endl;
//  return 0;
//}


//#include<stdio.h>
//int main()
//{
//  printf("%d\n",sizeof(char));
//  printf("%d\n",sizeof(short));
//  printf("%d\n",sizeof(int ));
//  printf("%d\n",sizeof(long));
//  printf("%d\n",sizeof(long long));
//  printf("%d\n",sizeof(float));
//  printf("%d\n",sizeof(double));
//
//  return 0;
//
//}

#include<stdio.h>
struct A{
  char c=1;
};

int main(){
  printf(" sizeof(struct A)=%d\n",sizeof(struct A));
}
