#pragma once 

#include<cstdio>
#include<unistd.h>
#include<cstring>
#include<string>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h> 
#include<netinet/in.h>


class UdpSocket{
  public:
    UdpSocket()
      :_sock(-1)
    {}

    bool Socket(){
      
      _sock=socket(AF_INET,SOCK_DGRAM,0);
      if(_sock<0){
        perror("socket!");
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

    bool Bind(const std::string& ip,uint16_t& port){
      
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

    bool RecvFrom(std::string* msg,std::string* ip,uint16_t *port){
      
      char buf[1024]={0};
      sockaddr_in peer;
      socklen_t len=sizeof(peer);
      ssize_t n=recvfrom(_sock,buf,sizeof(buf)-1,0,(sockaddr*)&peer,&len);
      if(n<0){
        perror("recvfrom!");
        return false;
      } 
      buf[n]='\0';
      *msg=buf;

      if(ip!=nullptr){
        *ip=inet_ntoa(peer.sin_addr);
      }

      if(port!=nullptr){
        *port=ntohs(peer.sin_port);
      }
      return true;
    }


    bool SendTo(const std::string& msg,const std::string&ip,uint16_t port){
      sockaddr_in addr;
      addr.sin_family=AF_INET;
      addr.sin_addr.s_addr=inet_addr(ip.c_str());
      addr.sin_port=htons(port);
      ssize_t n=sendto(_sock,msg.c_str(),msg.size(),0,(sockaddr*)& addr,sizeof(addr));
      if(n<0){
        perror("sendto!");
        return false;
      }

      return true;
    }
  private:
    int _sock;
};
