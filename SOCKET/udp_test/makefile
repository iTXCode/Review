.PHONY:all 

all: server client 

server:echo_server.cc   udp_server.hpp udp_socket.hpp 
	g++ echo_server.cc -o server 

client:echo_client.cc udp_client.hpp udp_socket.hpp 
	g++ echo_client.cc -o client 
