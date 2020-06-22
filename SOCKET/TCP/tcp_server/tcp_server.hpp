//通用的tcp服务器

#pragma once 
#include<functional>
#include"tcp_socket.hpp"

#define CHECK_RET(exp) if(!(exp)){\
  return false;\
}

typedef std::function<void(const std::string&,std::string*)> Handler; 

class TcpServer{
  public:
    TcpServer()
    {
    }

    bool Start(const std::string& ip,uint16_t port,Handler handler){
      
      //1.创建一个socket
      CHECK_RET( listen_sock.Socket() );
      //2.绑定端口号  
      CHECK_RET( listen_sock.Bind(ip,port) );
 
      //3.进行监听
      CHECK_RET(listen_sock.Listen());
      
      //4.进入主循环
      while(true){
        //5.通过accept获取到一个连接
        TcpSocket clientsock;
        std::string ip;
        uint16_t port;

        //核心问题在于,第一次Accept之后就进入了一个循环
        //在这个操作过程中,循环一只没有结束,Accept没有被重复调用
        //后序链接过来的客户端都在内核的链接队列中排队,一直在等待处理
        //我们需要想办法让我们的程序能够更快速的调用Accept
        bool ret=listen_sock.Accept(&clientsock,&ip,&port);
        if(!ret){
          continue;
        }
        printf("[%s:%d] 有客户端连接!\n",ip.c_str(),port);
        //6.和客户端进行具体的沟通,一次连接中和客户端进行多次沟通
        while(true){
          //1.读取请求
          std::string req;
          int r=clientsock.Recv(&req);

          if(r<0){
            continue;
          }

          if(r==0){
            //对端关闭了socket
            clientsock.Close();
            printf("[%s:%d] 对端关闭了连接!\n",ip.c_str(),port);
            break;
          }
         printf("[%s:%d] 对端发送了%s\n",ip.c_str(),port,req.c_str());
          //b.根据请求计算响应
          std::string resp;
          handler(req,&resp);

          //c.把响应写回到客户端
          clientsock.Send(resp);

        } 
      }
    }

  private:
    TcpSocket listen_sock;
};
