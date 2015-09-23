all: server client server.o client.o Socket.o
Socket.o: Socket.h Socket.cpp
	g++ -c -g Socket.cpp
client.o: Socket.h Socket.cpp client.cpp
	g++ -c -g Socket.cpp client.cpp
server.o: Socket.h Socket.cpp server.cpp
	g++ -c -g Socket.cpp server.cpp
client: client.o Socket.o
	g++ client.o Socket.o -o client
server: server.o Socket.o
	g++ server.o Socket.o -o server
