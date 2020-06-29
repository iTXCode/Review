FLAG=-std=c++11 -lpthread  -ljsoncpp #链接动态库

.PHONY:all 

all:server client 

server:cal_server.cc tcp_socket.hpp tcp_thread_server.hpp 
	g++ cal_server.cc -o server $(FLAG) 


client:cal_client.cc tcp_socket.hpp  tcp_client.hpp 
	g++ cal_client.cc -o client  $(FLAG) 
