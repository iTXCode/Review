#pragma once  

#include<sys/epoll.h>
#include<vector>
#include"tcp_socket.hpp"

//Epoll类提供的操作和select类提供的差不多

class Epoll{
  public:
    void Add(const TcpSocket& sock){
      //打印日志
      printf("Epoll::Add %d\n",sock.GetFd());
      //打印出添加的问文件描述符
      
    }

    void Del(const TcpSocket& sock){

    }

    void Wait(std::vector<TcpSocket>* output){

    }
  private:
    // epoll底层就是通过红黑树实现的
    // 所以不需要使用有排序功能的set存储
    int _epoll_fd;
    //通过这个_epoll_fd 找到内核中的对象,从而对内和中的
    //文件描述符进行管理
};
