#include"tcp_server.hpp"
#include<unordered_map>
//6.12:2.02

int main(){
  TcpServer server;
  std::unordered_map<std::string,std::string> u_map;
  u_map.insert(std::make_pair("bit","比特"));
  u_map.insert(std::make_pair("world","世界"));
  u_map.insert(std::make_pair("time","时间"));
  server.Start("0.0.0.0",9090,[&u_map](const std::string& req,std::string* resp){
      if(u_map.find(req)==u_map.end()){
        *resp="没有找到您所查找的内容!";
        }else{
        *resp=u_map[req];
        }
      });
  return 0;
}
