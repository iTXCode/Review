#pragma once  

#include"tcp_socket.hpp"

class TcpClient{

  public:
    TcpClient(){
      _sock.Socket();
    }

    ~TcpClient(){
      _sock.Close();
    }

    bool Connect(const std::string& ip,uint16_t port){
      return _sock.Connect(ip,port);
    }

    bool Recv( std::string* resp){
      return _sock.Recv(resp);
    }

    bool Send(const std::string& rsp){
      return _sock.Send(rsp);
    }
  private:
    TcpSocket _sock;
};
