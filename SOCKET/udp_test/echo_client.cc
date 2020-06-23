#include"udp_client.hpp"

int main(int argc,char* argv[]){
  if(argc!=2){
    printf("Usge: ./client [ip]\n");
  }
  
  UdpClient client(argv[1],9090);
  while(true){
    char buf[1024]={0};
    printf("请输入回显内容:");
    fflush(stdout);
    scanf("%s",buf);

    client.SendTo(buf);
     
    std::string resp;
    client.RecvFrom(&resp);
    printf("resp:%s\n",resp.c_str());
  } 

  return 0;
}
