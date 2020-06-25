#pragma once 
#include<sys/wait.h>
#include<functional>
#include<signal.h>
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
      signal(SIGCLD,SIG_IGN);
      //解决僵尸进程问题
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


          //6.创建子进程,让子进程去处理客户端的请求
          // 父进程继续调用Accept
        ProcessConnet(client_sock,peer_ip,peer_port,handler);
        
      }

    }
  private:
    
    void ProcessConnet( TcpSocket& client_sock,
        const std::string& ip,uint16_t port,
        Handler handler){
      //1.创建子进程
      pid_t ret=fork();
      //2.父进程直接结束这个函数
      if(ret>0){
        //父进程
        //父进程也需要关闭这个socket
        //否则就会出现文件描述符泄露
        client_sock.Close();
        return; 

        //进程创建失败的原因:
        //  1.内存不够
        //  2.进程太多
        
      }


      //3.子进程循环以下事情
      //   a.读取客户端请求
      while(true){
        std::string req;
        int index=client_sock.Recv(&req);

        if(index<0){
          continue; 
        }

        if(index==0){
          printf("[%s:%d] 客户端端开连接!\n",ip.c_str(),port);
          break;
        }
        //通过函数recv来读取对端内容
        printf("[%s:%d]客户端发送了%s\n",ip.c_str(),port,req.c_str());
        //   b.根据请求计算响应
        std::string resp;
        handler(req,&resp);
          //   c.把响应写回客户端
        client_sock.Send(resp); 
        //通过函数send() 将反馈内容协会对端

      }  

      //子进程的收尾工作
      //1.关闭socket
      client_sock.Close();
      //结束进程
      exit(0);
    }

    TcpSocket _sock;
};




