#include"udp_server.hpp"

int main(){
  UdpServer server;
  server.Start("0.0.0.0",9090,[](const std::string&req,std::string* resp ){
        *resp=req;
      }); 
  return 0;
}
