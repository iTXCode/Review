#include"udp_server.hpp"
#include<unordered_map>

int main(){
  std::unordered_map<std::string,std::string> u_map;
  u_map.insert(make_pair("hello","你好")); 
  u_map.insert(make_pair("world","世界"));
  u_map.insert(make_pair("bit","比特"));

  UdpServer server;


  //lambda表达式的[]中可以写东西
  //把lambda外部的变量"捕获"到lambda表达式里面
  //捕获可以按值捕获,也可以用引用捕获
  server.Start("0.0.0.0",9090,[&u_map](const std::string &req,
      std::string *resp){
      auto it=u_map.find(req);
      if(it==u_map.end()){
       *resp="未找到结果!";
       }else{
        *resp=it->second;
       }
      });
  return 0;
}


/*
 *啥样的对象能放到vector里面a.能拷贝b.支持移动语义
 *能放到list中的(和vector相同)
 *能放到deque里面(和vector相同)
 *能放到std::array 里面(和vector相同)
 *std::set a。能拷贝b.能够比较 <
 * std::map:key  a.能拷贝，b.能够比较相等，c.能哈希value
 *
 * */
