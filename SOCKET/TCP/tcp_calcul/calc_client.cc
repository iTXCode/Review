#include<sstream>
#include"tcp_client.hpp"

int main(int argc,char* argv[]){
  if(argc!=2){
    printf("Uage ./client [ip]\n");
  }

  TcpClient client;
  bool ret=client.Connect(argv[1],9090);
  
  if(!ret){
    return 1;
  }
  while(true){
    printf("请输入两个操作数:");
    fflush(stdout);
    int num1=0;
    int num2=0;
    char op[10]={0};
    scanf("%d %d %s",&num1,&num2,op);
    //序列化
    std::stringstream ss;
    ss<<num1<<" "<<num2<<" "<<op;
    //给服务器发送数据
    client.Send(ss.str());
    //反序列化
    std::string resp;
    client.Recv(&resp);
    printf("resp:%s\n",resp.c_str());
  }
  return 0;
}
