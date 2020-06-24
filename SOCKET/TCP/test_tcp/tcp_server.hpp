#pragma once 
#include<functional>
#include"tcp_socket.hpp"

#define CHECK_RET(exp) if(!(exp)){\
  return false;\
}

typedef std::function<void(const std::string& ,std::string*)>  Handler;

class TcpServer{
  public:
  TcpServer(){

   }


  bool Start(const std::string& ip,uint16_t port,Handler handler){
    //1.创建文件描述符 
    CHECK_RET(_sock.Socket());
    //2.绑定服务器的端口号和ip地址
    CHECK_RET(_sock.Bind(ip,port));
    //3.开始监听队列消息
    CHECK_RET(_sock.Listen());
    
    //进入主循环
    while(true){
      //获取对端请求
      TcpSocket client_sock;
      std::string ip;
      uint16_t port;
      bool ret=_sock.Accept(&client_sock,&ip,&port);
      //从等待队列中取出第一个连接请求
      if(!ret){
        continue;
      }

      printf("[%s:%d] 客户端进行了连接!\n",ip.c_str(),port);
      //和客户端连接进行沟通
      while(true){
        std::string req;
        int r=client_sock.Recv(&req);
        if(r<0){
          continue;
        }
        if( r ==0  ){
          client_sock.Close();
          printf("[%s:%d] 对端关闭了连接!\n",ip.c_str(),port);
        break;
        }   
        printf("[%s:%d] req:%s\n",ip.c_str(),port,req.c_str());
     //根据请求计算响应
      std::string resp;
      handler(req,&resp);
      client_sock.Send(resp);
      //将响应结果写回客户端
      } 
    }

  }
  private:
    TcpSocket _sock;
};
