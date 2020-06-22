#include"tcp_client.hpp"

int main(int argc,char* argv[]){
  //从标准输入读数据
  if(argc!=2){
    printf("Usage ./client [ip]\n");
    return 1;
  }
  TcpClient client;
  bool ret=client.Connect(argv[1],9090);
  if(!ret){
    printf("Connect failed!,please try again!");
    return 1;
  }
  while(true){
    printf("请输入一个要查询的单词: ");
    fflush(stdout);
    char req[1024]={0};
    scanf("%s",req);
    //把读取到的数据发送给服务器
    client.Send(req);
    std::string resp;
    client.Recv(&resp);
  //读取服务器的响应结果
  //把响应结果显示到标准输出上
  printf("resp: %s\n",resp.c_str());
  }
  return 0;
}
