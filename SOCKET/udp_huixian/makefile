.PHONY:all 

all:server client 

server:udp_server.hpp udp_socket.hpp echo_server.cc 
	g++ echo_server.cc -o server

client: udp_socket.hpp udp_client.hpp echo_client.cc 
	g++ echo_client.cc -o client 
