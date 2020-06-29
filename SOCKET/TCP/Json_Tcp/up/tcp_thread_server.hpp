#pragma once 

#include<pthread.h>
#include<functional>
#include"tcp_socket.hpp"


#define CHECK_RET(exp) if(!(exp)){\
  return false;\
}

typedef std::function<void(const std::string&,std::string*)> Handler;

class TcpTheadServer{
  public:
    TcpTheadServer(){
      
    }

    ~TcpTheadServer(){
      listen_sock.Close();
    }

    bool Start(const std::string& ip,uint16_t port,Handler handler){
      CHECK_RET(listen_sock.Socket());
      CHECK_RET(listen_sock.Bind(ip,port));
      CHECK_RET(listen_sock.Listen());

      while(true){
        TcpSocket client_sock;  

        std::string peer_ip;
        uint16_t peer_port;
        
        bool ret=listen_sock.Accept(&client_sock,&peer_ip,&peer_port);

        if(!ret){
          continue;
        }
        
        //建立成功
        printf("[%s:%d]客户端建立连接!\n",peer_ip.c_str(),peer_port);
      
      //6.创建线程处理客户端的请求
      ThreadConnect(client_sock,peer_ip,peer_port,handler);
      }
    }
  private:

    struct ThreadEntryArg{
        TcpSocket client_sock;
        std::string ip;
        uint16_t port;
        Handler handler;
    };


    void ThreadConnect(TcpSocket& client_sock,const std::string& peer_ip,uint16_t peer_port,Handler handler){

      //1.创建线程
      pthread_t tid;
      ThreadEntryArg* arg=new ThreadEntryArg;
      arg->client_sock=client_sock;
      arg->ip=peer_ip;
      arg->port=peer_port;
      arg->handler=handler;
      pthread_create(&tid,NULL,ThreadEntry,(void*)arg);
      //2.对于主线程来说,让函数立刻返回
      pthread_detach(tid); //线程等待
      //3.对于新线程来说,循环处理客户端的操作

    }

    static void* ThreadEntry(void* arg){
      
      ThreadEntryArg *argue=(ThreadEntryArg*)arg;
      TcpSocket& client_sock=argue->client_sock;
      std::string& ip=argue->ip;
      uint16_t port=argue->port;
      Handler handler=argue->handler;
      while(true){
      //    a.读取客户端请求
      std::string req;
      int ret=client_sock.Recv(&req);

      if(ret<0){
        continue;
      }

      if(ret==0){
        client_sock.Close();
        printf("客户端[%s:%d]断开连接!\n",ip.c_str(),port);
        break;
      }
      //    b.根据请求计算响应
     printf("[%s:%d] 客户端请求:\n req: %s\n",ip.c_str(),port,req.c_str());
      
     std::string resp; 
      handler(req,&resp);
      //    c.将响应结果返回给客户端
      client_sock.Send(resp);
      }
      //delete 
      delete argue;
    }

    TcpSocket listen_sock;
};
