#pragma once 

#include<cstdio>
#include<cstring>
#include<string>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<functional>

class TcpSocket{
  public:
    TcpSocket()
    :_sock(-1)
    {

    }
    
    TcpSocket(int fd){
      _sock=fd;
    }

    bool Socket(){
      _sock=socket(AF_INET,SOCK_STREAM,0);
      if(_sock<0){
        perror("socket!");
        return false;
      }
      return true;
    }

    bool Bind(const std::string& ip,uint16_t port){

      sockaddr_in addr;
      addr.sin_family=AF_INET;
      addr.sin_port=htons(port);
      addr.sin_addr.s_addr=inet_addr(ip.c_str());
      int ret=bind(_sock,(sockaddr*)& addr,sizeof(addr));
      
      if(ret<0){
        perror("bind!");
        return false;
      }
      return true;
    }

    bool Connect(const std::string& ip,uint16_t port)
    {
      sockaddr_in addr; 
      addr.sin_family=AF_INET;
      addr.sin_port=htons(port);
      addr.sin_addr.s_addr=inet_addr(ip.c_str());
      int ret=connect(_sock,(sockaddr*)& addr,sizeof(addr));
      if(ret<0){
        perror("connect!");
        return false;
      }
      return true;
    }


    bool Listen(){

      int  n=listen(_sock,10);
      if(n<0){
        perror("listen!");
        return false;
      }
      return true;
    }
   
    bool Accept(TcpSocket *peer,std::string* ip=nullptr,uint16_t* port=nullptr){
      
      sockaddr_in addr;
      socklen_t len=sizeof(addr);
      int client_sock=accept(_sock,(sockaddr*)& addr,&len);

      peer->_sock=client_sock; 
      //将取到的文件描述符赋值给参数peer内部的文件描述符
      if(client_sock<0){
        perror("accept!");
        return false;
      }
      
      if(ip!=nullptr){
        *ip=inet_ntoa(addr.sin_addr);
      }

      if(port!=nullptr){
        *port=ntohs(addr.sin_port);
      }
      return true;
    }

    int Recv(std::string* msg){
      msg->clear();

      char buf[1024*10]={0};

      int ret=recv(_sock,buf,sizeof(buf)-1,0);
      if(ret<0){
        perror("recv!");
        return 1;
      }else if(ret==0){
        return 0;
      }

      msg->assign(buf);
      return 1;
    }

    bool Send(const std::string& msg){
      
      size_t ret=send(_sock,msg.c_str(),msg.size(),0);
      if(ret<0){
        perror("send!");
        return false;
      }
      return true;
    }

    bool Close(){
      if(_sock!=-1){
        close(_sock);
      }
      return true;
    }

    int GetFd() const{
      return _sock;
    }

  private:
    int _sock;
};
