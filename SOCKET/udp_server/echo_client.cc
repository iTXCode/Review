#include"udp_client.hpp"
#include<cstring>
int main(int argc,char* argv[]){
 UdpClient client(argv[1],9090);
 printf("请输入内容:");;
  string s="hahha";
 fflush(stdout);
client.RecvFrom(&s);

 string ret;
 client.RecvFrom(&ret);
 printf("%s\n",ret.c_str());
 return 0;
}

