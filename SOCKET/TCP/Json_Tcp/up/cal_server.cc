#include<jsoncpp/json/json.h>
#include"tcp_thread_server.hpp"


//使用Json的方式来进行序列化和反序列化
//{
// "nums":[1,2,3,4,5.....],
// "op"  :"+",
//}
//
//{
//  "result" :30
//}
//
// 可以借助第三方库 josncpp 来解析Json格式
//
//Json::Value  用来表示一个Json数据
//Json::Reader  把字符串转换成Json::Value 
//Json::Writer  把Json::Value 转换成字符串
int main(){
  TcpTheadServer server;
  server.Start("0.0.0.0",9090,[](const std::string& req,std::string * resp){
        //1.先将req反序列化
      Json::Reader reader;
      Json::Value req_json;
      reader.parse(req,req_json);//将字符串转换成Json格式
      //2.根据反序列化的结果,进行计算
      Json::Value& nums=req_json["nums"];
      std::string op=req_json["op"].asString();
      int result=0;
//      if(op=="+"){
//      result=num1+num2;
//      }else if(op=="-"){
//      result=num1-num2;
//      }else if(op=="*"){
//      result=num1*num2;
//      }else if(op=="/"){
//      result=num1/num2; 
//      }else if(op=="%"){
//      result=num1%num2;
//      }

      for(size_t i=0;i<nums.size();i++){
         if(op=="+"){
      result+=nums[(int)i].asInt();
      }else if(op=="-"){
      result-=nums[(int)i].asInt();
      }else if(op=="*"){
      result*=nums[(int)i].asInt(); 
      }else if(op=="/"){
      result/=nums[(int)i].asInt(); 
      }

      }
      //Json::FastWriter writer; //将Json中的内容按照一行输出
      Json::StyledWriter writer; //将Json中的内容按格式输出
      Json::Value resp_json;
      resp_json["result"]=result;

      *resp=writer.write(resp_json);
      printf("resp:%s\n",( *resp ).c_str());
  });
  return 0;
}
