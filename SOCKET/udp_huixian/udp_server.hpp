#pragma once 
#include<cassert>
#include<functional> //提供函数模板
#include"udp_socket.hpp"

//通用的udp 服务器类
//1.读取请求
//2.根据请求计算响应
//3.把响应内容写回客户端
//其中1，3 是固定的
//2 是业务相关的,所以就把 2 对应的代码提取成一个回调函数

//typedef void (*Handler)(const std::string& req,
//   std::string* resp);

typedef std::function<void(const std::string&,std::string*)> Handler; 
//同时兼容仿函数和函数指针

class UdpServer{
  public:
    UdpServer(){
      assert(_sock.Socket());
    }

    ~UdpServer(){
      _sock.Close();
    }

    bool Start(const std::string& ip,uint16_t port,Handler handler){
      //1.创建socket(构造函数已经完成)
      //2.绑定端口号
      bool ret=_sock.Bind(ip,port);
      if(!ret){
        return false;
      }

      //3.进入一个死循环
      while(true){
        //处理每个请求
        //a.接收请求内容
        std::string req;
        std::string peer_ip;
        uint16_t peer_port;
        _sock.ResvFrom(&req,&peer_ip,&peer_port);
        //b.根据请求计算响应
        printf("[%s:%d] req:%s\n",peer_ip.c_str(),ntohs( peer_port ),req.c_str());
        std::string resp;
        handler(req,&resp);
        //c.把响应返回客户端
        printf("server resp: %s\n",resp.c_str());
        _sock.SendTo(resp,peer_ip,peer_port);
      } 
      return true;
    }
  private:
    UdpSocket _sock;
};
