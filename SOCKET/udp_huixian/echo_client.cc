#include"udp_client.hpp"
#include<cstring>
int main(int argc,char* argv[]){
  UdpClient client(argv[1],9090);
  while(true){
    printf("请输入内容:");;

    fflush(stdout);
    char req[1024]={0};
    scanf("%s",req);

    client.SendTo(req);

    string ret;
    client.RecvFrom(&ret);
    printf("resp: %s\n",ret.c_str());
  } 
 return 0;
}

