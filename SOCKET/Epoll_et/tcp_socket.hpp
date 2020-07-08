#pragma once 

#include<cstdio>
#include<cstring>
#include<string>
#include<unistd.h>
#include<fcntl.h>
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
    
    //为了将水平触发的epoll改成垂直触发方式,
    //将代码改成非阻塞的
    
    bool SetNoBlock(){
      //获取到_sock这个文件描述符的相关标志位
      //这些标志位也是通过一个位图的方式来反应的,保存在f1这个int 中
      int fl=fcntl(_sock,F_GETFL);

      if(fl<0){
        perror("fcntl F_SETFL!");
        return false;
      }

      int ret=fcntl(_sock,F_SETFL,fl | O_NONBLOCK);

      if(ret<0){
        perror("fcntl  F_SETFL!");
        return false;
      }
      return true;
    }


    //非阻塞读
    int RecvNoBlock(std::string* msg)const {
      msg->clear();
      // 这是一个近似的写法,不够严谨,没有考虑粘包问题
      // 如果TCP的接收缓冲区为空,此时会读不到数据,但是recv也会返回,errno会被设置成EA_GAIN 或者 EWOULDBLOCK
      // 如果当前读到的数据长度比设定的用户缓冲区场地一样,就认为暂时读完了
    char tmp[1024*10]={0};
    while(true){
      ssize_t n=recv(_sock,tmp,1024*10-1,0);
      if(n<0){
        if(errno==EAGAIN || errno==EWOULDBLOCK){
          //此时缓冲区已经没有数据了,还是继续尝试读
          continue;
        }
        //如果是其他原因导致的读失败,退出函数
        return -1; 
      }

      if(n==0){
        //对端关闭
        return 0;
      }
      tmp[n]='\0';
      //把这个数据追加到 输出参数中
      msg->append(tmp); //相当于+=
      
      if(n<(ssize_t)sizeof(tmp)-1){
        //这一次读取没有填充满整个缓冲区,我们认为当前缓冲区中暂时没有数据
       break;
      }

    }
      return msg->size();
    }
    
    //非阻塞写
    bool SendNoBlock(const std::string& msg) const{
      //想比于RECV更简单一些
      //当我们实际发送的数据长度和msg的长度一样的时候就发送完了
      //send(_sock,msg.c_str(),msg.size(),0);
      //由于当前是非阻塞IO,如果发送缓冲区已经满了,函数一旦调用就返回,可能会出现发送失败的情况
     //更严谨的情况,应该是小块小块的数据发送,每次发一个数据之后
     //都要检查自己发送了多少数据,累加发送成功的数据达到msg的长度的时候
     //才最终发送完成
     return true;
    }
  private:
    int _sock;
};
