#pragma once 

#include<cassert>
#include"udp_socket.hpp"
#include<functional>
typedef std::function<void(const std::string&,std::string*)> Handler;

class UdpServer{
  public:
  UdpServer(){
    assert( _sock.Socket() );
  }
  
  bool Start(const std::string& ip,uint16_t port,Handler handler){
    bool ret=_sock.Bind(ip,port);
    if(!ret){
      return false; 
    }

    //绑定成功
    
    //进入死循环
    while(true){
      //处理每一个请求
      //1.接收请求内容
      std::string req;
      std::string peer_ip;
      uint16_t peer_port;
      _sock.RecvFrom(&req,&peer_ip,&peer_port);
      //2.根据请求内容计算响应
      //3.将响应结果返回给客户端
      printf("[%s:%d] req:%s\n",peer_ip.c_str(),peer_port,req.c_str());
      
      std::string resp;
      handler(req,&resp);
      _sock.SendTo(resp,peer_ip,peer_port);
    }
  }

  private:
    UdpSocket _sock;
};
