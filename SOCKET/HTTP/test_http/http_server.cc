#include"tcp_thread_server.hpp"

int main(){
  TcpTheadServer server;
  server.Start("0.0.0.0",9090,[](const std::string& req,std::string* resp){
        (void)req;
        std::string first_line="HTTP/1.1 303 Found\n";
        //std::string body="<html><div>hello world!</div></html>";
        std::string header="Location: http://www.baidu.com\n"  
        "Content-Type: text/html\n"
        "Content-Length: 11\n";
        std::string body="helloworld!";
        *resp=first_line+header+"\n"+body;
      });
  return 0;
}
