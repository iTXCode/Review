FLAG=-std=c++11 -lpthread

.PHONY:all 

all:server client 

server:calc_server.cc tcp_thread_server.hpp tcp_socket.hpp 
	g++ calc_server.cc -o server $(FLAG) 

client:calc_client.cc tcp_client.hpp tcp_socket.hpp 
	g++ calc_client.cc -o client -std=c++11
