.PHONY:all 

all:server client 

server:dict_server.cc tcp_epoll_server.hpp tcp_socket.hpp 
	g++ dict_server.cc -o server -std=c++11 

client:dict_client.cc tcp_client.hpp tcp_socket.hpp 
	g++ dict_client.cc -o client -std=c++11
