#pragma  once 
#include<vector>
#include<sys/select.h> //位图使用
#include<set> 
//1.需要高效的插入和删除
//2.需要方便的找到最大元素
#include"tcp_socket.hpp"

bool operator<(const TcpSocket&lhs,const TcpSocket& rhs ){
  return lhs.GetFd()<rhs.GetFd(); 
  
}

//select 这个函数本身用起来不叫繁琐,所以将其封装成类
//提供以下几个操作
// 文件描述符的管理器,这个管理器中包含的socket就是要
// 使用select来管理的socket
//1.新增一个文价描述符
//2.删除一个文件描述符
//3.等待操作等待管理的文件描述符就绪(只考虑就绪的情况)

class Selector{
  public:
    void Add(const TcpSocket& sock){
      printf("[Selector:Add] %d\n",sock.GetFd());      
      _socket_set.insert(sock);
    }

    void Del(const TcpSocket& sock){
      printf("[Selector:Del %d]\n",sock.GetFd());
      _socket_set.erase(sock);
    }

    //wait返回的时候需要告诉调用者那些文件描述符就绪了
    void Wait(std::vector<TcpSocket>* output){
        //调用Wait 就相当于调用select进行等待
      //1.获取到最大文件描述符
      if(_socket_set.empty()){
        printf("[Selector::Wait] _socket_set is empty\n");
      return;
      }
      int max_fd=_socket_set.rbegin()->GetFd();
       fd_set readfds; 
       FD_ZERO(&readfds);
       //把set中的每个需要关注的文件描述符都设置到readfds之中
       for(const auto& sock:_socket_set){
         FD_SET(sock.GetFd(),&readfds);
       }

       //select 默认是阻塞等待的,有文件描述符返回的时候,才会进行返回
       //当这个函数返回之后，就应该根据文件描述符的返回情况
       //构造一个输出参数,告诉调用者哪些socket就绪了
       
       int nfds=select(max_fd+1,&readfds,NULL,NULL,NULL);
       
       if(nfds<0){
         perror("select");
         return;
       }
       //已经返回了,返回结果同样也是保存在readfds中
       for(int fd=0;fd<max_fd+1;++fd){
         if(FD_ISSET(fd,&readfds)){
           //如果是,说明当前fd就是读就绪的
           //就把这个结果放到输出结果中
           output->push_back(TcpSocket(fd));
         }
       } 
    }
  private:
    //使用一个数据结构把需要的socket存起来
    std::set<TcpSocket> _socket_set;
    //使用set要求TcpSocket类支持比较操作
};


//实现一个select 版本的TCP server 
typedef std::function<void (const std::string&, std::string* resp)> Handler;

//检查宏函数的定义
#define CHECK_RET(exp)\
  if(!exp){\
  return false;\
  }


class TcpSelectServer{
  public:
      
    //一个服务器程序在处理请求的过程中的典型流程就是3个步骤
    //1.读取请求并解析
    //2.根据请求计算响应handler
    //3.返回计算结果
    bool Start(const std::string& ip,uint16_t port,Handler handler){
     //1.创建socket
     TcpSocket listen_sock;

     CHECK_RET(listen_sock.Socket());

     //2.绑定端口号
     CHECK_RET(  listen_sock.Bind(ip,port) );
    
     //3.进行监听
     CHECK_RET(listen_sock.Listen());

    //4.创建一个selector对象,让这些对象先把listen_sock管理起来,
    //后续进行等待都是靠selector对象完成
    
     Selector selector; 
    selector.Add(listen_sock);
    
    //5.进入主循环
     while(true){
      //6.不再是直接调用accept，而是使用selector进行等待
       std::vector<TcpSocket> output;
       selector.Wait(&output);
       //7.遍历返回结果,依次处理每个就绪的socket
       for(auto tcp_socket:output){
         //8.分成两种情况讨论
        if(tcp_socket.GetFd() == listen_sock.GetFd()){
           // a.如果 就绪socket是listen_sock要进
           // 行的操作是调用accept

           TcpSocket client_sock;
            std::string ip;
            uint16_t port;
            tcp_socket.Accept(&client_sock,&ip,&port);
          selector.Add(client_sock);
          printf("[client %s:%d] connected!\n",ip.c_str(),port);
        }else{  
          // b.如果 就绪的socket 不是listen_sock 
          // 要进行的操作是调用Recv
          
          //普通socket
          std::string req; 
           int n=tcp_socket.Recv(&req);

           if(n<0){
             continue;
           }

           if(n==0){
             printf("对端关闭\n");
             //对端关闭,也要把这个socket从selector中删除
             tcp_socket.Close();
             selector.Del(tcp_socket);
             continue;
           }

      
          printf("[client] %s\n",req.c_str());
           //根据请求计算响应
           
          std::string resp; 
          handler(req,&resp);
          tcp_socket.Send(resp);
        }
    
       }
     }
    }
  private:

};
