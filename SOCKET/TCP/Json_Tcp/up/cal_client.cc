#include<jsoncpp/json/json.h>
#include"tcp_client.hpp"

int main(int argc,char* argv[]){

  TcpClient client;
  bool ret=client.Connect(argv[1],9090);
  if(!ret){
    printf("connect failed!\n");
    return 1;
  }

  //2.进入主循环
  while(true){
    printf("请输入两个操作数和一个操作符:");
    fflush(stdout);
    char op[10]={0};
    int num1,num2;
    scanf("%d %d %s",&num1,&num2,op);
    //3.根据用户输入的内容,构造一个Json对象
    Json::Value req_json;
    req_json["num1"]=num1;
    req_json["num2"]=num2;
    req_json["op"]=op;
    //4.把Json 对象序列化成一个字符串
    //Json::FastWriter writer; //输入内容在一行
    Json::StyledWriter writer;
    std::string req=writer.write(req_json);
    printf("req:%s\n",req.c_str());
    //5.把字符串发送到服务器端
    client.Send(req);
    //6.从服务器读取返回结果
    std::string resp="";
    client.Recv(&resp);
    //7.把服务器返回结果进行解析
    Json::Reader reader;
    Json::Value resp_json;
    reader.parse(resp,resp_json);
    printf("result = %s\n",resp.c_str());
  }
  return 0;
}
