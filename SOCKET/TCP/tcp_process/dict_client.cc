#include"tcp_client.hpp"


int main(int argc,char* argv[]){
  if(argc!=2){
    printf("Uage ./client [ip]\n");
  }

  TcpClient client;
  if(!client.Connect(argv[1],9090) ){
    printf("连接失败,请重新连接!");
    return 1;
  }
  
  while(true){
    char buf[1024]={0};
    printf("请输入查询的内容:");
    fflush(stdout);
    scanf("%s",buf);
    client.Send(buf);
    std::string resp;
    client.Recv(&resp);
    printf("resp:%s\n",resp.c_str());
  }
  return 0;
}
