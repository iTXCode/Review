#pragma once 

#include"udp_socket.hpp"


class UdpClient{
  public:
    UdpClient(const std::string& ip,uint16_t port)
      :_ip(ip)
       ,_port(port)
    {
      _sock.Socket();
    }

    ~UdpClient(){
      _sock.Close();
    }

    bool SendTo(const std::string &msg){

      return _sock.SendTo(msg,_ip,_port);
    }

    bool RecvFrom(std::string* msg){
      
       return _sock.ResvFrom(msg);
    
    }
  private:
    UdpSocket _sock;
    std::string _ip;
    uint16_t _port;
};
