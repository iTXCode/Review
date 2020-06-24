#pragma once 

#include<functional>
#include"tcp_socket.hpp"
typedef  std::function<void(const std::string&,std::string* resp)> Handler; 

#define CHECK_RET(exp) if(!(exp)){\
  return false;\
}

class TcpProcessServer{
  public:
    TcpProcessServer(){

    }

    ~TcpProcessServer(){
      _sock.Close();
    }

    bool Start(const std::string& ip,uint16_t port,Handler handler){
      //1.创建socket
      CHECK_RET(_sock.Socket());
      //2.绑定端口号
      CHECK_RET(_sock.Bind(ip,port));
      //3.进行监听
      CHECK_RET(_sock.Listen());
      
      //4.进入主循环
      while(true){
        //5.调用accept
        TcpSocket client_sock;
        std::string peer_ip;
        uint16_t  peer_port;

        bool ret=_sock.Accept(&client_sock,&peer_ip,&peer_port);
        if(!ret){
          continue;
        }

        printf("[%s:%d] 客户端进行了连接!\n",peer_ip.c_str(),port);

        while(true){
          //6.创建子进程,让子进程去处理客户端的请求
          // 父进程继续调用Accept
          ProcessConnet();
        }
      }

    }
  private:
    TcpSocket _sock;

    
    void ProcessConnet(const TcpSocket& client_sock,
        const std::string& ip,uint16_t port,
        Handler handler){
      //1.创建子进程
      pid_t ret=fork();
      //2.父进程直接结束这个函数
      if(ret>0){
        //父进程
        return; 

        //进程创建失败的原因:
        //  1.内存不够
        //  2.进程太多
        
      }


      //3.子进程循环一下事情
      
      //   a.读取客户端请求
      //   b.根据请求计算响应
      //   c.把响应写回客户端
       
    }
};

