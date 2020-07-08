#pragma once  

#include<sys/epoll.h>
#include<vector>
#include<functional>
#include"tcp_socket.hpp"

//Epoll类提供的操作和select类提供的差不多

class Epoll{
  public:
    Epoll(){
      _epoll_fd=epoll_create(10);
    }

    ~Epoll(){
      close(_epoll_fd);
    }
   
    //只有新客户端连接过来才回调用,调用的频率远低于select
    //也就意味着epoll 拷贝数据就没有select 拷贝的那么频繁
    void Add(const TcpSocket& sock,bool is_et=false){
      //epoll   默认是水平触发的,这里修改成垂直触发
      
      //打印日志
      printf("Epoll::Add %d\n",sock.GetFd());
      //打印出添加的问文件描述符
      epoll_event event;
      event.events=EPOLLIN;
      if(is_et==true){
        event.events |=EPOLLET;
      }
      //此处epoll在add的时候插入的是键值对
      //fd在键和值之中都出现了,这件事情是迫不得已(这也是epoll的槽点之一)
      event.data.fd=sock.GetFd();
      epoll_ctl(_epoll_fd,EPOLL_CTL_ADD,sock.GetFd(),&event); 

    }

    void Del(const TcpSocket& sock){
      //打印日志
      printf("[Epoll::Del] %d\n",sock.GetFd());
      epoll_ctl(_epoll_fd,EPOLL_CTL_DEL,sock.GetFd(),NULL);

    } 

    void Wait(std::vector<TcpSocket>* output){
  
      output->clear();
      //等待文件描述符就绪
      epoll_event events[100];
      //结构体数组
      int nfds=epoll_wait(_epoll_fd,events,100,-1);
      //最后一个参数表示阻塞等待
      //返回之后就又若干个文件描述符就绪,保存在events数组中
      //返回结果就是在描述数组中有几个有效元素
      //epoll_wait返回的内容只是一个键值对的值
      //如果不加任何处理的话,用户不知道对应的文件描述符是那个
      //所以只能在插入的时候,把socket往值里也存一份
      if(nfds<0){
        perror("epoll_wait!");
        return;
      }

      //成功返回数组中的就绪元素个数
      //依次处理每个就绪的文件描述符
      for(int i=0;i<nfds;++i){
        int sock=events[i].data.fd;
        output->push_back(TcpSocket(sock));
      }

    }
  private:
    // epoll底层就是通过红黑树实现的
    // 所以不需要使用有排序功能的set存储
    int _epoll_fd;
    //通过这个_epoll_fd 找到内核中的对象,从而对内和中的
    //文件描述符进行管理
};


typedef std::function<void(const std::string&,std::string*)> Handler;

#define CHECK_RET(EXP)\
  if(!EXP){\
    return false;\
  }

class TcpEpollServer{
  public:
    bool Start(const std::string& ip,uint16_t port,Handler handler){
    //1.创建一个文件描述符
    TcpSocket listen_sock;
    CHECK_RET(listen_sock.Socket());
    //2.绑定端口号
    CHECK_RET(listen_sock.Bind(ip,port));
    //3.监听socket
    CHECK_RET(listen_sock.Listen());
    //4.创建Epoll对象,并把listen_sock用epoll管理起来
    Epoll epoll;
    epoll.Add(listen_sock);
    //5.进入主循环
    while(true){
      //6.使用Epoll::Wait 等待文件描述符就绪
      std::vector<TcpSocket>  output;
      epoll.Wait(&output);
      //7.循环处理每一个就绪的文件描述符,封为两种情况
      for(auto sock:output){
        if(sock.GetFd()==listen_sock.GetFd()){
          //  a.listen_sock就调用Accept
          TcpSocket client_sock;
          sock.Accept(&client_sock);
          epoll.Add(client_sock);
        }else{
          //  b.非listen_sock 就调用Recv 
          std::string  req;
          //ET模式下必须采用非阻塞的方式进行读写
          
          int n=sock.Recv(&req);
          if(n<0){
            continue;
          }
          if(n==0){
            //对端关闭
            printf("[client:%d ] disconnected!\n",sock.GetFd());
            sock.Close();
            epoll.Del(sock);
            continue;
          }
          printf("[client %d]req:%s\n",sock.GetFd(),req.c_str());
          //正确读取情况
          std::string  resp;
          handler(req,&resp);
          //8.根据响应计算响应结果
          sock.Send(resp);
          //9.将响应结果返回给对端 
        }

      } 
      }
    }
};


