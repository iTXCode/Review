#pragma  once 
#include<cstdio>
#include<cstring>
#include<string>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

class TcpSocket{
  public:
    TcpSocket()
      :_sock(-1)
    {

    }

    //给服务器使用
    bool Socket(){

      _sock=socket(AF_INET,SOCK_STREAM,0);
      if(_sock<0){
        perror("socket!");
        return false;
      }
      return true;
    }

    //给服务器使用
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

    bool Listen(){
      //进入监听状态
      int ret=listen(_sock,10);
      //参数2 为等待队列的长度
      if(ret<0){
        perror("listen!");
        return false;
      }
      return true;
    }


    //给服务器使用
    bool Accept(TcpSocket* peer,std::string* ip=nullptr,uint16_t* port=nullptr){
      //从连接队列中取一个连接到用户代码中
      //如果队列中没有连接,就会阻塞(默认行为)
      sockaddr_in addr;
      socklen_t len=sizeof(addr);
   
      int client_sock=accept(_sock,(sockaddr*)&addr,&len);
      //返回值也是一个socket
      
      peer->_sock=client_sock;
      //将对端的文件描述符返回去
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

    //客户端和服务器都会使用
    int Recv(std::string* msg){
      msg->clear();//将消息清空
      char buf[1024*10]={0};
      ssize_t n=recv(_sock,buf,sizeof(buf)-1,0);
      //recv的返回值：如果读取成功,返回结果为读到的字节数
      //如果读取失败,返回结果为-1
      //如果对端关闭了,socket返回结果为0
      if(n<0){
        perror("recv!");
        return 1;
      }else if(n==0){
        //需要考虑到返回 0 的情况
        return 0;
      }
      msg->assign(buf);//将缓冲区中的消息赋值到返回消息空间中

      return 1;
    }

    //客户端和服务器都会使用
    bool Send(const std::string& msg){
      ssize_t n=send(_sock,msg.c_str(),msg.size(),0);
      if(n<0){
        perror("send!");
          return false;
      }
      return true;
    }

    //给客户端使用
    bool Connect(const std::string& ip,uint16_t port){
      sockaddr_in addr;
      addr.sin_family=AF_INET;
      addr.sin_port=htons(port);
      addr.sin_addr.s_addr=inet_addr(ip.c_str());
      
      int ret=connect(_sock,(sockaddr*)&addr,sizeof(addr));
      if(ret<0){
        perror("connect!");
        return false;
      }
      return true;
    }
  //服务器使用
    bool Close(){

      if(_sock!=-1){
        close(_sock);
      }
      return true;
    }
  private:
    int _sock;
};
