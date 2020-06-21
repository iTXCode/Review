#include"tcp_server.hpp"

//6.12:2.02

int main(int argc,char* argv[]){
  TcpServer server;
  server.Start(argv[1],9090,[](const std::string& rep,std::string* resp){

      };
  return 0;
}
